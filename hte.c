#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "hte.h"

#define RECORDS_PER_BUCKET 50

typedef struct
{
    char key[MAX_KEY_LENGHT];
    int value;
    bool is_occupied;
}record;

typedef struct
{
    int local_depth;
    int record_count;
    record records[RECORDS_PER_BUCKET];
}bucket;

typedef struct
{
    FILE *disk_file;
    int global_depth;
    size_t directory_size;
    long *bucket_offsets;
}hte_directory;


Hash hash_openFile(const char* filename)
{
    hte_directory* dir = malloc(sizeof(hte_directory));
    if(dir == NULL) return NULL;

    FILE* f = fopen(filename, "rb+");

    if(f == NULL){
        f = fopen(filename,"wb+");
        if(f == NULL){
            free(dir);
            printf("ERRO ao criar ficheiro no disco");

            return NULL;
        }
        printf("Nenhum fichario com o nome '%s' encontrado. Criando novo fichario...\n", f);

        dir -> disk_file = f;
        dir -> global_depth = 0;
        dir -> directory_size = 1;
        dir -> bucket_offsets = malloc(dir -> directory_size * sizeof(long));

        bucket initial_bucket;
        initial_bucket.local_depth = 0;
        initial_bucket.record_count = 0;

        for (int i = 0; i < RECORDS_PER_BUCKET; i++) {
            initial_bucket.records[i].is_occupied = false;
        }

        dir->bucket_offsets[0] = 0;

        fseek(f, 0, SEEK_SET);
        fwrite(&initial_bucket, sizeof(bucket), 1, f);

        printf("Novo fichario Hash '%s' criado\n", f);
    }

    else{
        dir->disk_file = f;
        printf("Ficheiro Hash '%s' aberto com sucesso\n", filename);
    }
}