#ifndef DELTATIME_H
#define DELTATIME_H

#include <time.h>
#define MILLION 1000000
typedef struct timespec timepoint;

double time_diff(timepoint* a, timepoint* b);
timepoint set_now(timepoint* t);
void display_fps(timepoint* curr, timepoint* last, double* deltatime);
#endif
