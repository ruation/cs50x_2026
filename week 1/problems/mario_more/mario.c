#include <stdio.h>
#include <cs50.h>

int main(void){
    int height;
    do{
        height = get_int("height: ");
    }while(height > 8 || height < 1);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < height; j++){
            if(j<height-i-1){printf(" ");}
            else{printf("#");}
        }
        printf("  ");
        for(int j = 0; j < height; j++){
            if(j<=i){printf("#");}
            else{printf("");}
        }printf("\n");
    }

    return 0;
}
