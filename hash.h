#ifndef HASH_H
#define HASH_H
#include <stdbool.h>

typedef void* Hash;

Hash hash_createTable(int n);

bool hash_insertReg(Hash h, char* key, int value);

bool hash_removeReg(Hash h, char* key);

Hash hash_get(Hash h, const char* key);

void hash_set(Hash h, const char* key);

bool hash_exists(Hash h, char* key);

int hash_getRegistry(Hash h, char* key);

void hash_destroyTable(Hash h);

#endif