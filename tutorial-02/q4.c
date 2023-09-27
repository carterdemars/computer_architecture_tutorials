#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
/**
 * You baically have two choices, either implement a separate data structure
 * to track every allocation, or track the allocation using the 
 * "memory" array itself. 
 *
 * I use memory itself to track.  
 * A non-negative number marks how many bytes are usable, following this 
 * location.  A negative number marks how many bytes are occupied.
 */

#define MEMORY_SIZE 256      // Doing this, I can easily change MEMORY_SIZE
#define my_size_t uint16_t
#define my_size_mark_t int16_t

uint8_t *memory; 

void* simple_malloc (my_size_t n) {
	uint8_t *p = memory;
	my_size_mark_t trunk_size;
	while (!((trunk_size = *((my_size_mark_t *) p)) >= n)
			&& p < memory + MEMORY_SIZE
		  ) {
		if (*((my_size_mark_t *) p) < 0) {
			// This trunk is occupied. 
			p += - *((my_size_mark_t *) p) + sizeof(my_size_mark_t);
		} else {
			// This trunk is too small. 
			p += *((my_size_mark_t *) p) + sizeof(my_size_mark_t);
		}
	}
	if (p >= memory + MEMORY_SIZE) {
		assert(p == memory + MEMORY_SIZE);  // As expected
		// No space available
		return NULL; 
	} 
	assert(*((my_size_mark_t *) p) >= n); 
	uint8_t *res = p;
	p += n;
	// allocate the space
	*((my_size_mark_t *) p) = *((my_size_mark_t *) res) - n - sizeof(my_size_mark_t);
	// We actually return the address after the size mark. 
	return res + sizeof(my_size_mark_t);  
}

int main (void) {
	memory = malloc(MEMORY_SIZE);
	*((my_size_mark_t *) memory) = MEMORY_SIZE - sizeof(my_size_mark_t);

	uint32_t *p = simple_malloc(4 * sizeof(uint32_t));
	for (int i = 0; i < 4; i++) {
		p[i] = i * i;
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
