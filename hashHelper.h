//
// Created by dubjr on 3/17/2017.
//

#ifndef CONCORDANCE_HASHHELPER_H_H
#define CONCORDANCE_HASHHELPER_H_H

/**
 * hashValue: A struct for the hash values in the map.
 * @param key: A pointer to the hashValue's key
 * @param value: A pointer to the hashValue's value
 */
typedef struct hashValue {
    const char *key;
    int value;
} hashV;
/**
 * hashMap: The containing struct for the hashMap structure
 * @param hash: An incoming pointer to an existing hash map
 * @param len: The current length of the hash map
 * @param cap: The size of allowcated memory available for the hash. This allows for restructuring
 * @param value: The values array for hash map entries
 */
typedef struct hashMap{
    int len;
    int cap;
    hashV *item;
    hashV *items[10];
} hashMap, *hashM;
/**
 * Finds the index of the current value
 * @param hash: A pointer to our hash
 * @param key: A constant pointer to our key
 * @return Index of the queried key iff in hash, else -1
 */
int hashFindIndex(hashM hash, const char *key);
/**
 * Finds and returns a value within the queried hash
 * @param hash: A pointer to the hash
 * @param key: A constant pointer to our key
 * @return Returns the value of the queried object iff in the hash, else -1
 */
int hashFind(hashM hash, const char* key);
/**
 * Adds a value to the hash
 * @param hash: A pointer to the hash
 * @param key: A pointer to the key
 * @param val: The value (int) we want to insert
 */
void hashAdd(hashM hash, const char *key, int val);
/**
 *
 * @param hash
 * @param key
 * @param val
 */
void incramentAdd(hashM hash, const char *key);
/**
 *
 * @param a
 * @param b
 * @return
 */
int hashCompare(const void* a, const void* b);
/**
 * Prints out the current hash after a quick sort
 * @param hash
 */
void hashPrint(hashM hash);
/**
 * Creates a new hash
 * @return The new hash pointer
 */
hashM newHash(int size);
/**
 * Frees the hash, please make sure to call this
 * @param hashPointer: The pointer to our current hash
 */
void freeHash(hashM hashPointer);

#endif //CONCORDANCE_HASHHELPER_H_H