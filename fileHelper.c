//
// Created by dubjr on 3/17/2017.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "hashHelper.h"
#include "fileHelper.h"


void stringRemoveNonAlphaNum(char *str){
    unsigned long i = 0;
    unsigned long j = 0;
    char c;

    while ((c = str[i++]) != '\0'){
        //change to isalnum to include numbers
        if (isalpha(c)){
            str[j++] = tolower(c);
        }
    }
    str[j] = '\0';
}

void concordance(fileH file){
    if(!file){
        printf("Please init before running result set!");
    }
    if(!file->hash){
        printf("Please load file before printing result");
    }

    if (file->file) {
        while (fscanf(file->file, " %1023s", file->buf) == 1) {
            stringRemoveNonAlphaNum(file->buf);
            if(strlen(file->buf) != 0) {
                incramentAdd(file->hash, file->buf);
            }
        }
        if (ferror(file->file)) {
            printf("Failed to open file");
        }
        fclose(file->file);
        hashPrint(file->hash);
    }
    else{
        printf("File not defined");
    }
    return;
}

fileH newFileHelper(char* fileName){
    FILE* t = fopen(fileName, "r");
    fileHelper file = {fileName, t, newHash(CHUNK)};
    fileH filePointer = malloc(sizeof(fileHelper));
    //file = fopen("C:\\test.txt", "r");

    *filePointer = file;
    return filePointer;
}

void freeFileHelper(fileH file){
    //First free the sub-value parts
    freeHash(file->hash);
    free(file->buf);
    //Remove the rest
    free(file->file);
    free(file);
}