#ifndef DELTATIME_H
#define DELTATIME_H

// timespec { time_t tv_sec, long tv_nsec }
#include <time.h>
typedef struct timespec timepoint;

// for conversions
#define MILLION 1000000

// functions
double time_diff(timepoint* a, timepoint* b);
timepoint set_now(timepoint* t);
void display_fps(timepoint* curr, timepoint* last, double* deltatime);

#endif
