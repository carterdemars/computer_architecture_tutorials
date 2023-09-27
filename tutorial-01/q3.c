#include <stdio.h>
#include <stdint.h>

int main (void) {
	union { 
		uint32_t a;
		uint8_t b[4];
	} u;
	u.a = 0x01020304;

	// This is indeed called type punning, it is fine in C since C99 
	// https://port70.net/~nsz/c/c11/n1570.html#note95
	if (u.b[0] == 0x01 && u.b[3] == 0x04) {
		printf("Big endiant\n");
	} else if (u.b[0] == 0x04 && u.b[3] == 0x01) {
		printf("Little endiant\n");
	} else {
		printf("Undefined behaviour triggered.\n");
	}
}
