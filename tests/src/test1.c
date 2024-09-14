#include <stdio.h>
#include "../../src/include/cust_allocation.h"
#include "../../src/include/faults_handle.h"

void seg_fault() {
    int c = 1;
    int d = 0;
    int e = c / d;
    printf("%d\n", e);
}

int main(void) {
    handler();
    struct B {
        int a;
        double b;
        char c[10];
    };
    int *a = cust_calloc(sizeof(int) * 2, NULL);
    struct B *b = cust_calloc(sizeof(struct B) * 3, NULL);
    printf("%lld\n", memory_manager.num_of_references);
    printf("before\n");



    cust_free();
    printf("after\n");
    printf("%lld\n", memory_manager.num_of_references);
    return 0;
}
