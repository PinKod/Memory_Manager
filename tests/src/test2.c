//
// Created by Calamari Yeste on 2024-09-14.
//
#include <assert.h>
#include <stdlib.h>
#include "../../src/include/cust_allocation.h"
#include "../../src/include/faults_handle.h"

void test_cust_calloc() {
    assert(cust_calloc(10, NULL) != NULL);
    assert(cust_calloc(0, NULL) != NULL);
    assert(cust_calloc(100, NULL) != NULL);

    void *ptr = cust_calloc(20, free);
    cust_free();
    free(ptr);
}

void test_memory_management() {
    assert(memory_manager.num_of_references == 0);
    cust_calloc(5, NULL);
    assert(memory_manager.num_of_references == 1);
    assert(cust_calloc(10, NULL) != NULL);
    assert(memory_manager.num_of_references == 2);
    cust_free();
    assert(memory_manager.num_of_references == 0);
}

int main() {
    handler();
    test_cust_calloc();
    test_memory_management();
    cust_free();
    return 0;
}
