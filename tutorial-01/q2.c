#include <stdio.h> 
#include <stdlib.h>
#include "day.h"


// comparison function for qsort
int compareEvents(const void* a, const void* b) {
    const event_t *eventA = a;
    const event_t *eventB = b;

    if (eventA->start.hour == eventB->start.hour) {
        return eventA->start.minute - eventB->start.minute;
    }
    return eventA->start.hour - eventB->start.hour;

}

void sortDay(event_t events[], uint32_t n) {

    /* the C library has a function qsort that sorts an array

    qsort(void *base, size_t nitems, size_t size, 
    int (*compar)(const void *, const void*))

    1) base is the pointer to the first element in the array to be sorted
    2) nitems is the number of elements in the array pointed by base
    3) size is the size in bytes of each element in the array
    4) compar is a function to compare two elements
    */

   qsort(events, n, sizeof(event_t), compareEvents);
   return;
}

void printEvent(event_t *event) {

    int end_minute = event->start.minute + event->duration;
    int dur_hours = end_minute / 60;
    int dur_mins = end_minute - dur_hours*60;
    int end_hour = event->start.hour + dur_hours;

    printf("%s from %02d:%02d to %02d:%02d\n", event->name, event->start.hour, 
    event->start.minute, end_hour, end_minute);

    return;
}

int main(void) {
	event_t events[] = {
		{ "Lunch", { 12, 0 }, 30 },
		{ "Breakfast", { 7, 30 }, 45 },
		{ "Supper", { 17, 30 }, 60 } ,
		{ "Exercise", { 11, 30 }, 30 },
		{ "Sleep", { 22, 30 }, 480 } 
    };

	int n = sizeof(events)/sizeof(event_t);
	sortDay(events, n);
	for(int i=0; i<n; i++)
		printEvent(&events[i]);
}
