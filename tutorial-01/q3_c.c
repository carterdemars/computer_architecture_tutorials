/** 
 * This is the second "correct" way that cannot trigger undefined behaviour. 
 */
#include <stdio.h>
#include <stdint.h>

int main (void) {
	uint32_t a = 0x01020304;
	unsigned char *p = (unsigned char *) &a;

	// This is allowed, because p is a char pointer. 
	// https://port70.net/~nsz/c/c11/n1570.html#6.5p7
	if (p[0] == 0x01 && p[3] == 0x04) {
		printf("Big endiant\n");
	} else if (p[0] == 0x04 && p[3] == 0x01) {
		printf("Little endiant\n");
	}
}

