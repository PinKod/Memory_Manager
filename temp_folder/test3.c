//
// Created by Calamari Yeste on 2024-09-14.
//
#include <assert.h>
#include <stdlib.h>
#include "../../src/include/cust_allocation.h"
#include "../../src/include/faults_handle.h"

struct A {
    int b;
    double *c;
};

void free_A(void *a) {
    struct A *a_a = a;
    free(a_a->c);
}

void test_complex_free_function() {
    struct A *a = cust_calloc(sizeof (struct A), free_A);
    //printf("test_complex_free_function\n");
}


void test_edge_cases() {
    assert(cust_calloc(0, NULL) != NULL);
    assert(cust_calloc(1, NULL) != NULL);
}

void test_memory_leak() {
    void *ptr = cust_calloc(20, NULL);
    assert(ptr != NULL);
    cust_free(); // Should free the allocated memory
    //assert(ptr == NULL); // Check if memory leak occurred
}

int main() {
    handler();
    test_complex_free_function();
    test_edge_cases();
    test_memory_leak();
    cust_free();
    return 0;
}