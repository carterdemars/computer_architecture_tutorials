#include <stdio.h> 
#include <stdlib.h>
#include "day.h"

// Function to compare two events based on their start times
// Written with the help of ChatGPT
int compareEvents(const void *a, const void *b) {
    const event_t *eventA = a;
    const event_t *eventB = b;
    if (eventA->start.hour == eventB->start.hour) {
        return eventA->start.minute - eventB->start.minute;
    }
    return eventA->start.hour - eventB->start.hour;
}

// Function to sort events in ascending order of their start times
void sortDay(event_t events[], uint32_t n) {
    qsort(events, n, sizeof(event_t), compareEvents);
	//        void qsort(void base[.size * .nmemb], size_t nmemb, size_t size,
	//                          int (*compar)(const void [.size], const void [.size]));
	// TODO: talk about const qualifier. 
}

// Function to print an event
void printEvent(event_t *event) {
	int end_minute = event->start.minute + event->duration;
	int extra_hour = end_minute / 60;
	end_minute -= extra_hour * 60;
	int end_hour = event->start.hour + extra_hour;
    printf("%s from %02d:%02d to %02d:%02d\n", event->name,
           event->start.hour, event->start.minute, end_hour, end_minute);
}

int main(void) {
	event_t events[] = {
		{ "Lunch", { 12, 0 }, 30 },
		{ "Breakfast", { 7, 30 }, 45 },
		{ "Supper", { 17, 30 }, 60 } ,
		{ "Exercise", { 11, 30 }, 30 },
		{ "Sleep", { 22, 30 }, 480 } };
	int n = sizeof(events)/sizeof(event_t);
	sortDay(events, n);
	for(int i=0; i<n; i++)
		printEvent(&events[i]);
}
