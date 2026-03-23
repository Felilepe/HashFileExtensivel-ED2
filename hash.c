#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef void* Hash;

Hash hash_createTable(int n);

bool hash_insertReg(Hash h, char* string, int registry);

bool hash_removeReg(Hash h, char* string);

bool hash_exists(Hash h, char* string);

int hash_getRegistry(Hash h, char* string);




