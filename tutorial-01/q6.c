#include <stdio.h>
#include <stdlib.h>

// Defines and initialize a global variables
// added to .bss
int w = 1;

int main(void) {

    // define and initialize a local variables
	// stored in the stack
	int x = 2;
	printf("aaa\n");

    // define a pointer and initialize it
	// the pointer y is stored in the stack, the allocated space is in the heap
	int *y = malloc(sizeof(int));

    // define a bunch of pointers and initialize them
	void *a=&w, *b=&x, *c=y, *d=&y;

    // a holds the address of w, b points to x, c holds the value of y, d points to y
	printf("%14p\n%14p\n%14p\n%14p\n", a, b, c, d);
	free(y);
}
