#ifndef HTE_H
#define HTE_H

#define MAX_KEY_LENGTH 32

#include <stdbool.h>

typedef void* Hash;

Hash hash_openFile(const char* filename);

bool hash_insertReg(Hash h, char* key, int value);

bool hash_removeReg(Hash h, char* key);

int hash_getSize(Hash h);

bool hash_exists(Hash h, char* key);

int hash_getRegistry(Hash h, char* key);

void hash_closeFile(Hash h);

#endif