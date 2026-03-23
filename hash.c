#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <hash.h>

typedef struct
{
    const char* key;
    int value;
} hash_entry;

typedef struct
{
    hash_entry* entries;
    size_t capacity;
    size_t size;
} hash_table;

Hash hash_createTable(int n);

bool hash_insertReg(Hash h, char* key, int value);

bool hash_removeReg(Hash h, char* key);

Hash hash_get(Hash h, const char* key);

void hash_set(Hash h, const char* key);

bool hash_exists(Hash h, char* key);

int hash_getRegistry(Hash h, char* key);

void hash_destroyTable(Hash h);




