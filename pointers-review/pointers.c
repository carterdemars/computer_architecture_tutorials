#include <stdint.h> 
#include <stdio.h>
#include <stdlib.h>

int myfunc1(int a) {
    return a + 1;
}

int myfunc2(int b) {
    return b - 1;
}

int myfunc3(int c) {
    return c / 2;
}

/*
function that takes a void pointer and increments its value by 5 if it can be 
cast as an int
*/ 
void myfunc4(void* d) {

    if ((int*) d != NULL) {
        *(int*)d = *(int*)d + 5;
    }
    
    return;
}


int main(void) {

    // 1. dynamically allocate an array of integers
    int* myArray = malloc(10*sizeof(int));
    printf("%p", (void*)myArray);
    free(myArray);

    // 4. exploring function pointers
    int (*func_ptr[3])(int) = {&myfunc1, &myfunc2, &myfunc3};

    for (int i = 0; i < 3; i++) {
        printf("\n%d", (*func_ptr[i])(10));
    }

    // 5. using a function to modify the value of a pointer
    int x = 120;
    int* testPtr = malloc(sizeof(int));
    (*testPtr) = x;
    printf("\nBefore changing: %d", *testPtr);
    myfunc4(testPtr);
    printf("\nAfter changing: %d", *testPtr);
    free(testPtr);

    return 0;
}