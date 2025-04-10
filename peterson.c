#include <stdio.h>
#include "peterson.h"
// #include <stdbool.h> would be used if we was using true, false but we are using 1, 0 respectively.

/* 
    Volatile prevent compiler optimisations to say that these variables are shared, ensures that
    there is no assumptions made by the compiler. Earlier we saw these within peterson.h, this is
    the defining part of the declration from peterson.h
*/
volatile int turn;
volatile int flag[2] = {0,0};

/*
We could extend this to increase to n processes:
int pn() {
    do {
        flag[n] = 1;
        turn = 1 - i;
        while(flag[n] && turn == 1 = i);
        pn_critical_section();
        flag[n] = 0;
        // pn's remainder section
    } while (1);
    return 0;
}
*/

// Returning int makes this infinite but we could add a break clause like if(break_condition) break; if we wanted to
int p0(void) {
    do {
        flag[0] = 1; // Flags represent wishes
        turn = 1; // Allows other process to go
        while (flag[1] && turn == 1); // Boundary
        p0_critical_section();
        flag[0] = 0; // Done with its critical section
        // p0's remainder section
    } while (1);
    return 0;
}

int p1(void) {
    do {
        flag[1] = 1;
        turn = 0;
        while (flag[0] && turn == 0);
        p1_critical_section();
        flag[1] = 0; // Done with its critical section
        // p1's remainder section
    } while(1);
    return 0;
}

// We use void to match the declration in the .h file of this .c
int p1_critical_section(void) {
    printf("p1 is in its critical section.");
    // Do stuff
    return 0;
}

int p0_critical_section(void) {
    printf("p0 is in its critical section");
    // Do stuff
    return 0;
}