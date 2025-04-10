/*
    We include both the .h files here, this is not encouraged but since these files are
    independent then we can include them all in main.c as they would be linked but if we 
    wanted test_and_set.c to use stuff from peterson.c, then we would include within
    test_and_set.c to ensure modularity
*/
#include "headers/peterson.h"
#include "headers/test_and_set.h"
#include <stdio.h>

volatile int lock = 0; // Volatile to avoid compiler assumptions for optimisations

int main() {
    // p0() and p1() would be called by seperate threads that main() would create
    do {
        while(test_and_set(&lock));
        // Critical section
        printf("%d\n", lock);
        lock = 0;
    } while (1);
    return 0;
}