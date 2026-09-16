#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float average_letters(string text);

float average_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    float index = 0.0588 * average_letters(text) - 0.296 * average_sentences(text) - 15.8;
    if(index < 1){printf("Before Grade 1\n");}
    else if(index >= 16){printf("Grade 16+\n");}
    else{printf("Grade %.0f\n", round(index));}
}


float average_letters(string text){
    int words = 0, letters = 0;

    for(int i = 0, length = strlen(text); i < length; i++){
        if( isalpha( text[i] ) ){ letters++; }
        else if( (text[i] == ' ' || text[i] == '.' || text[i] == '!' || text[i] == '?') && i != 0){
            if((text[i-1] != ' ' && text[i-1] != '.' && text[i-1] != '!' && text[i-1] != '?'))words++;
        }

    }

    float average = letters / (float) words;


    return average * 100;
}

float average_sentences(string text){
    int sentences = 0, words = 0;

    for(int i = 0, length = strlen(text); i < length; i++){
        if( (text[i] == ' ' || text[i] == '.' || text[i] == '!' || text[i] == '?') && i != 0){
            if((text[i-1] != ' ' && text[i-1] != '.' && text[i-1] != '!' && text[i-1] != '?'))words++;
        }
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')sentences++;

    }
    float average = sentences / (float) words;


    return average * 100;
}
