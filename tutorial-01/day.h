#include <stdint.h> 

typedef struct {
	uint32_t hour, minute;
} tod_t;

typedef struct {
	char name[40];
	tod_t start;
	uint32_t duration; // duration in minutes
} event_t;

void sortDay(event_t events[], uint32_t n);
void printEvent(event_t *event);
