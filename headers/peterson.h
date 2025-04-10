/*
    These two lines ensure that the compiler doesn't include two of the same header files
    since if two files do #include "peterson.h" then it will cause errors as you can't do
    it twice, by using a global ID like "PETERSON_H_" to not conflict with struct or anything 
    like that it will make the compiler skip the initalisaiton of this header file as it has 
    already been made 
*/
#ifndef PETERSON_H_
#define PETERSON_H_

/*
    The following are declaring that these variables exist within the program and to not throw
    any errors regarding about them, if multiple files are using this header then it can use this
    to memory reference them and allow sharing variables within different files
*/
extern volatile int turn;
extern volatile int flag[2];

/*
    The function declarations below are standard C procedure to let the compiler know that these
    functions exist within this .c file, headers are just stacked ontop of .c files
*/
int p0(void);
int p1(void);

int p0_critical_section(void);
int p1_critical_section(void);


#endif // This links into the include guard from the top, all the above was created if PETERSON_H wasn't defined
