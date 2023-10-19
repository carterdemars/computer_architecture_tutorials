#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
/**
 * You baically have two choices, either implement a separate data structure
 * to track every allocation, or track the allocation using the 
 * "memory" array itself. 
 *
 * The simplified version uses another variable called allocated to track.
 */

#define MEMORY_SIZE 256      // Doing this, I can easily change MEMORY_SIZE
#define my_size_t uint16_t
#define my_size_mark_t int16_t

uint8_t *memory; 
my_size_t allocated = 0;

void* simple_malloc (my_size_t n) {
	if (allocated + n > MEMORY_SIZE) {
		return NULL;
	}
	uint8_t *res = &memory[allocated];
	allocated += n;
	return res;
}

int main (void) {
	memory = malloc(MEMORY_SIZE);

	uint32_t *p = simple_malloc(4 * sizeof(uint32_t));
	for (int i = 0; i < 4; i++) {
		p[i] = i * i + 10000;
	}
	for (int i = 0; i < 4; i++) {
		printf("%d", p[i]);
		if (i == 3) {
			printf("\n");
		} else {
			printf(" ");
		}
	}

	free(memory);
	return 0;
}

