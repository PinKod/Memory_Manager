//
// Created by pinkod on 12.09.2024.
//

#ifndef CUST_ALLOCATION_CUST_ALLOCATION_H
#define CUST_ALLOCATION_CUST_ALLOCATION_H

#include <stdio.h>
#include "stdbool.h"

typedef struct {
    void *reference;
    void (*free_func) (void*);
} Reference_Struct;

typedef struct {
    Reference_Struct *ptr_to_first_Reference;
    unsigned long long int num_of_references;
} Memory_Manager;

#ifndef MEMORY_MANAGER_STRUCT
#define MEMORY_MANAGER_STRUCT
 extern Memory_Manager memory_manager; //= {.num_of_references = 0, .ptr_to_first_Reference = NULL};
#endif

void *cust_calloc(unsigned long long int size_in_bytes, void (*complex_free_func) (void*));
void cust_free();

#endif //CUST_ALLOCATION_CUST_ALLOCATION_H
