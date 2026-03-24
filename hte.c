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





