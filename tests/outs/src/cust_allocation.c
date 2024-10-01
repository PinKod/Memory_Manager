//
// Created by pinkod on 12.09.2024.
//
#include "include/cust_allocation.h"

#include <stdlib.h>

//Memory_Manager memory_manager = {.num_of_references = 0, .ptr_to_first_Reference = NULL};

void *cust_calloc(unsigned long long int size_in_bytes, void (*complex_free_func) (void*)) {
    void *ptr = calloc(1, size_in_bytes);
    if(ptr == NULL) {
        return NULL;
    }
    void *temp_ptr = realloc(memory_manager.ptr_to_first_Reference, (memory_manager.num_of_references + 1) * sizeof (Reference_Struct));
    if(temp_ptr == NULL) {
        free(ptr);
        return NULL;
    }
    memory_manager.num_of_references += 1;
    memory_manager.ptr_to_first_Reference = temp_ptr;
    memory_manager.ptr_to_first_Reference[memory_manager.num_of_references - 1].reference = ptr;
    memory_manager.ptr_to_first_Reference[memory_manager.num_of_references - 1].free_func = complex_free_func;
    return ptr;
}

void cust_free() {
    if(memory_manager.num_of_references == 0 || memory_manager.ptr_to_first_Reference == NULL) {
        return;
    }
    for(unsigned long long int i = 0; i < memory_manager.num_of_references; i++) {
        if(memory_manager.ptr_to_first_Reference != NULL) {
            //if(memory_manager.ptr_to_first_Reference[i] != NULL) {
                if(memory_manager.ptr_to_first_Reference[i].free_func == NULL && memory_manager.ptr_to_first_Reference[i].reference != NULL) {
                    free(memory_manager.ptr_to_first_Reference[i].reference);
                }
                else if (memory_manager.ptr_to_first_Reference[i].reference != NULL){
                    memory_manager.ptr_to_first_Reference[i].free_func(memory_manager.ptr_to_first_Reference[i].reference);
                }
            //}
        }
    }
    free(memory_manager.ptr_to_first_Reference);
    memory_manager.num_of_references = 0;
}

