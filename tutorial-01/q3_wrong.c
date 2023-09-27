/** 
 *
 * This is the way that can trigger undefined behaviour. 
 */
#include <stdio.h>
#include <stdint.h>

int main (void) {
	uint32_t a = 0x01020304;
	uint16_t *p = (uint16_t *) &a;   // The compiler may assume p does not point to a

	// This is allowed, because p is a char pointer. 
	// https://port70.net/~nsz/c/c11/n1570.html#6.5p7
	if (p[0] == 0x0102 && p[1] == 0x0304) {
		printf("Big endiant\n");
	} else if (p[0] == 0x0304 && p[1] == 0x0102) {
		printf("Little endiant\n");
	}
}


