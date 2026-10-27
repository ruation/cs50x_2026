// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Size
unsigned int size_dic = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    node *buffer = table[hash(word)];
    while(1){
        if(strcasecmp(word, buffer->word) == 0){
            return true;
        }else if(buffer->next == NULL){
            break;
        }else{
            buffer = buffer->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    for(int i = 0; i < N; i++){
        table[i] = NULL;
    }

    FILE *file = fopen(dictionary, "r");
    if(file == NULL){
        return false;
    }
    char buffer[LENGTH+1];
    while(fscanf(file, "%s", buffer) != EOF){
        node *n = malloc(sizeof(node));
        if(n == NULL){
            fclose(file);
            return false;}
        strcpy(n->word, buffer);
        n->next = table[hash(buffer)];
        table[hash(buffer)] = n;
        size_dic++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return size_dic;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *pointer, *tmp;
    for(int i = 0; i < N; i++){
        pointer = table[i];
        while(pointer!=NULL){
            tmp = pointer;
            pointer = pointer->next;
            free(tmp);
        }
    }
    return true;
}
