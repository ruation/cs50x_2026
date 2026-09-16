#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]){
    int flag = 0;
    if(argc!=2 || strlen(argv[1])!=26){printf("Usage: ./substitution key\n"); return 1;}
    for(int i = 0; i < 26; i++){
        flag = 0;
        for(int j = 0; j < 26; j++){
            if(toupper(argv[1][i]) == toupper(argv[1][j]))flag++;
        }
        if(flag > 1){printf("Usage: ./substitution key\n"); return 1;}
        if(!isalpha(argv[1][i])){printf("Usage: ./substitution key\n"); return 1;}
    }
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for(int i = 0, len = strlen(plaintext); i<len; i++){
        if(!isalpha(plaintext[i])){printf("%c", plaintext[i]); continue;}

        if(isupper(plaintext[i])){
            printf("%c", toupper(argv[1][plaintext[i]-65]));
        }else{
            printf("%c", tolower(argv[1][plaintext[i]-97]));
        }
    }

    printf("\n");


    return 0;
}
