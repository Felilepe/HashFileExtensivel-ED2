#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash.h"

#define HASH 5381

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

static size_t hash_function(const char* key, size_t capacity)
{
    size_t hash = HASH;
    int c;

    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % capacity;
}

static hash_entry* hash_find_entry(hash_table* t, const char* key)
{
    size_t index = hash_function(key, t -> capacity);
    size_t start_index = index;

    while(t -> entries[index].key != NULL){
        if(strcmp(t ->entries[index].key, key) == 0){
            return &(t -> entries[index]);
        }
        index = (index + 1) % t -> capacity;
        if(index == start_index) break;

    }
    return NULL;
}

Hash hash_createTable(int capacity)
{
    hash_table *t = malloc(sizeof(hash_table));
    if(t == NULL || capacity <= 0) return NULL;

    t -> size = 0;
    t -> capacity = capacity;

    t -> entries = calloc(t -> capacity, sizeof(hash_entry));
    if(t -> entries == NULL){
        free(t);
        return NULL;
    }
    return t;
}

bool hash_insertReg(Hash h, char* key, int value)
{

}

bool hash_removeReg(Hash h, char* key);

Hash hash_get(Hash h, const char* key);

void hash_set(Hash h, const char* key);

bool hash_exists(Hash h, char* key)
{
    if (h == NULL || key == NULL) return false;

    hash_table *t = (hash_table *)h;
    if (t->capacity == 0) return false;

    return hash_find_entry(t, key) != NULL;
}

int hash_getRegistry(Hash h, char* key);

void hash_destroyTable(Hash h);




