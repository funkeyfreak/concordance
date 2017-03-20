//
// Created by dubjr on 3/17/2017.
//
#include <stdio.h>
#include "hashHelper.h"
#ifndef CONCORDANCE_FILEHELPER_H
#define CONCORDANCE_FILEHELPER_H
#define CHUNK 1024

/**
 * A simple struct for loading the file
 *
 */
typedef struct fileHelper{
    char* fileName;
    FILE *file;
    hashM hash;
    char buf[CHUNK];
} fileHelper, *fileH;

/**
 * Removes non alpha numeric charictors from incomming words
 * @param str: The char* which holds the incoming string
 */
void stringRemoveNonAlphaNum(char *str);

/**
 * Runs the concordance opperation
 * @param file: The fileHelper pointer
 */
void concordance(fileH file);

/**
 * Creates a new fileHelper object
 * @param fileName: the incomming file
 * @return The new fileHelper object
 */
fileH newFileHelper(char* fileName);

/**
 * Frees resources consumed by the fileHelper object
 * @param file: The fileHelper pointer to remove
 */
void freeFileHelper(fileH file);

#endif //CONCORDANCE_FILEHELPER_H
