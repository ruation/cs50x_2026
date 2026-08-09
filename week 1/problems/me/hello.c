#include <stdio.h>
#include <cs50.h>

int main(void){

    string nome = get_string("What's your name? ");

    printf("hello, %s\n", nome);

    return 0;
}
