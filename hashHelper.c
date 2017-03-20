/**
 * Assumptions: assuming the charictors red are ascii char only
 * @author: Dalin Williams
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashHelper.h"


int hashFindIndex(hashM hash, const char *key){
    if(!hash){
        return -1;
    }
    for(int i = 0; i < hash->len; ++i){
        if (!strcmp(hash->item[i].key, key)) {
            //hash->item[i]->key;
            return i;
        }
    }

    return -1;
}


int hashFind(hashM hash, const char* key){
    if(!hash){
        return -1;
    }
    int index = hashFindIndex(hash, key);
    return (index == -1) ? -1 : hash->item[index].value;
}

void hashAdd(hashM hash, const char *key, int val){
    if(!hash){
        return;
    }
    //We do not take non, positive numbers here
    val = abs(val);
    //Modify the value if it exists
    int index = hashFindIndex(hash, key);
    if(index != -1){
        hash->item[index].value = val;
        return;
    }
    //Double the length if we have expended our resources
    if(hash->len == hash->cap){
        hash->cap *= 2;

        hash->item = realloc(hash->item, hash->cap * sizeof(hashV));
    }
    //Add new
    hash->item[hash->len].key = strdup(key);
    hash->item[hash->len].value = val;
    hash->len++;
}

void incramentAdd(hashM hash, const char *key){
    if(!hash){
        return;
    }
    //Modify the value if it exists
    int index = hashFindIndex(hash, key);
    if(index != -1){
        hash->item[index].value += 1;
        return;
    }
    //Double the length if we have expended our resources
    if(hash->len == hash->cap){
        hash->cap *= 2;

        hash->item = realloc(hash->item, hash->cap * sizeof(hashV));
    }
    //Add new
    hash->item[hash->len].key = strdup(key);
    hash->item[hash->len].value = 1;
    hash->len++;
}

int hashCompare(const void* a, const void* b){
    hashV *ia = (hashV *)a;
    hashV *ib = (hashV *)b;
    return strcmp(ia->key, ib->key);
}

void hashPrint(hashM hash){
    //Quick sort to order the items a-z
    int size = hash->len;
    qsort(hash->item, size, sizeof(hashV), hashCompare);
    for(int i = 0; i < hash->len; i++){
        printf("%s %d \n", hash->item[i].key, hash->item[i].value);
    }
}

hashM newHash(int size){
    hashMap newHash ={0, size, malloc(size * sizeof(hashV))};
    hashM hashPointer = malloc(sizeof(hashMap));
    *hashPointer = newHash;
    return hashPointer;
}

void freeHash(hashM hashPointer){
    //First free the sub-value parts
    for(int i = 0; i < hashPointer->len; i++){
        free((void *) hashPointer->item[i].key);
    }
    //Remove the rest
    free(hashPointer->item);
    free(hashPointer);
}