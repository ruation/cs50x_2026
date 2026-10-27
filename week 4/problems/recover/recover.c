#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("usage: ./recover card.raw\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if(file == NULL){
        printf("corrupt file.\n");
        return 1;
    }
    FILE *img;

    BYTE buffer[512];
    int filecount = -1;
    char *filename = malloc(8 * sizeof(char));
    if(filename == NULL){
        printf("memory error\n");
        return 1;
    }
    while(fread(buffer, sizeof(BYTE), 512, file)){
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            if(filecount>=0)fclose(img);
            filecount++; sprintf(filename, "%03i.jpg", filecount);
            img = fopen(filename, "w");
        }
        if(filecount>=0){
            fwrite(buffer, sizeof(BYTE), 512, img);
        }
    }
    fclose(file);
    fclose(img);
    free(filename);
    return 0;
}
