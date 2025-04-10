#include "headers/test_and_set.h" // Must include test_and_set.h so the compiler matches the defintion with the declaration in the .h

/*
    Locks a region of code determined by *target
    @param *target the lock that is initially false allowing to enter its critical section
    @return original value of target that will be true in the next iteration
*/
int test_and_set(volatile int *target) {
    int val = *target;
    *target = 1;
    return val;
}