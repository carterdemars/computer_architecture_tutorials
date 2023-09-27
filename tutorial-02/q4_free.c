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

#define MEMORY_SIZE 256
#define my_size_t uint16_t
#define my_size_mark_t int16_t

uint8_t *memory; 

void* my_malloc (my_size_t n) {
	uint8_t *p = memory;
	my_size_mark_t trunk_size;
	while (!((trunk_size = *((my_size_mark_t *) p)) >= n)
			&& p < memory + MEMORY_SIZE
		  ) {
		if (*((my_size_mark_t *) p) < 0) {
			// This trunk is occupied. 
			p += - *((my_size_mark_t *) p) + sizeof(my_size_mark_t);
		} else {
			/* This trunk is too small. 
			 *
			 * There can be three cases
			 * 1. (+6) ... (+5) ...
			 * 2. (+6) ... (-5) ...
			 * 3. (+6) ... End of memory
			 */
			// For case 1, we have to merge the adjacent trunks into one. 
			uint8_t *next_p = p + *((my_size_mark_t *) p) + sizeof(my_size_mark_t);
			if (next_p - memory >= MEMORY_SIZE || 
					(*((my_size_mark_t *) next_p)) < 0) {
				// Case 2 or 3
				p = next_p;
			} else {
				// Case 1, concat the two trunks. 
				*((my_size_mark_t *) p) += 
					*((my_size_mark_t *) next_p) + sizeof(my_size_mark_t);
			}
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
	*((my_size_mark_t *) res) = - n;
	// We actually return the address after the size mark. 
	return res + sizeof(my_size_mark_t);  
}

void my_free (void *ptr) {
	// We just change flip the sign, marking the location became available
	my_size_mark_t *p = ptr;
	p -= 1;
	*p = - *p;
}

#define TEST_ARRAY_LENGTH 32

int main (void) {
	memory = malloc(MEMORY_SIZE);
	*((my_size_mark_t *) memory) = MEMORY_SIZE - sizeof(my_size_mark_t);

	char *ps[TEST_ARRAY_LENGTH];
	for (int i = 0; i < TEST_ARRAY_LENGTH; i++) {
		ps[i] = my_malloc(6);
		assert(ps[i] != NULL);
	}
	printf("%p\n", memory);
	for (int i = 0; i < TEST_ARRAY_LENGTH; i++) {
		printf("%d: %p\n", i, ps[i]);
	}
	// The space is now fully allocated. 
	assert(my_malloc(6) == NULL);     // This should fail.

	my_free(ps[1]);
	my_free(ps[2]);
	// Now we have space again
	char *pnew = my_malloc(14);
	assert(pnew == ps[1]);
	assert((void *) ps[0] - (void *) memory == sizeof(my_size_t));

	free(memory);
	return 0;
}
