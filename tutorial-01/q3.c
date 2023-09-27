#include <stdio.h>
#include <stdint.h>

/*
Q3 Write a C program to determine if the processor it is executing on uses 
big-endian or little-endian byte ordering for storing multi-byte data to memory. 
*/

int main (void) {
	union { 
		uint32_t a;
		uint8_t b[4];
	} u;

	u.a = 0x01020304;

	// This is indeed called type punning, it is fine in C since C99 
	// https://port70.net/~nsz/c/c11/n1570.html#note95

	if (u.b[0] == 0x01 && u.b[3] == 0x04) {
		printf("Big endian\n");
	} else if (u.b[0] == 0x04 && u.b[3] == 0x01) {
		printf("Little endian\n");
	} else {
		printf("Undefined behaviour triggered.\n");
	}
}
