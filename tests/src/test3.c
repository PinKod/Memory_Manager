//
// Created by Calamari Yeste on 2024-09-14.
//
#include <assert.h>
#include <stdlib.h>
#include "../../src/include/cust_allocation.h"
#include "../../src/include/faults_handle.h"

/*
void test_complex_free_function() {
    void (*custom_free)(void*) = malloc(sizeof(int));
    *custom_free = free();
    assert(cust_calloc(10, custom_free) != NULL);
    cust_free();
    assert(custom_free == NULL);
}
*/

void test_edge_cases() {
    assert(cust_calloc(0, NULL) != NULL);
    assert(cust_calloc(1, NULL) != NULL);
}

void test_memory_leak() {
    void *ptr = cust_calloc(20, free);
    assert(ptr != NULL);
    cust_free(); // Should free the allocated memory
    assert(ptr == NULL); // Check if memory leak occurred
}

int main() {
    handler();
    //test_complex_free_function();
    test_edge_cases();
    test_memory_leak();
    return 0;
}