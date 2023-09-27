#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MEMORY_SIZE 256
typedef uint16_t my_size_t;
typedef struct {
	// 0b01110101010100001111100
	int a;          // 4
	// 0b01110101010100001111100
	char c;         // 1
	// 0b01110101010100001111101
					// 3
	// 0b01110101010100010000000
	int b;          // 4
} my_struct_t;
#define my_struct_2_t struct { \
	int a \
	int b; \
} 
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
	for (int i=0; i<4; i++) {
		p[i] = i * i + 10000;
	}
	for (int i=0; i<4; i++) {
		printf("%d\n", p[i]);
	}

	return 0;
}
