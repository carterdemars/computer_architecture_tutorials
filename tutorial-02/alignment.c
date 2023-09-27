#include <stdio.h>

int main (void) {
	printf("Alignment given by GCC:\n");
	printf("short: %ld\n", __alignof__(short));
	printf("int: %ld\n", __alignof__(int));
	printf("long: %ld\n", __alignof__(long));
	printf("float: %ld\n", __alignof__(float));
	printf("double: %ld\n", __alignof__(double));

	printf("\nWARNING: On x86, this is not the same as the requirements for \"correctly alligned\'");
	// https://gcc.gnu.org/onlinedocs/gcc/Alignment.html
	return 0;
}
