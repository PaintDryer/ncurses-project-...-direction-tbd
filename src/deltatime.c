#include <ncurses.h>
#include "deltatime.h"

// must handle tv_nsec wrapping when nanoseconds become seconds (10^9)
double time_diff(timepoint* a, timepoint* b)
{
	int a_nsec = a->tv_nsec;
	int b_nsec = b->tv_nsec;
	double t = a->tv_sec - b->tv_sec;
	if (b->tv_nsec > a->tv_nsec)
	{
		t--;
		a_nsec += MILLION * 1000; // 10^9ns or 1s
	}
	t *= MILLION * 1000;
	t += a_nsec - b_nsec;
	return (t);
}

// clock_gettime is used because time() doesn't go below seconds
timepoint set_now(timepoint* t)
{
	if (!t)
	{
		timepoint temp = {};
		if (clock_gettime(CLOCK_MONOTONIC, &temp) == -1)
			printf("failed to obtain time");
		return temp;
	}
	else
	{
		if (clock_gettime(CLOCK_MONOTONIC, t) == -1)
			printf("failed to set time");
		return *t;
	}
}

// debugging option should never be included in game loop
void display_fps(timepoint* curr, timepoint* last, double* deltatime)
{
	static int seconds = 0;
	static int framecount = 0;
	mvprintw(0,0, "deltatime: %.2f ms\n",
			*deltatime / MILLION);
	
	if (curr->tv_nsec < last->tv_nsec) // check for nanosecond rollover
	{
		mvprintw(1,0, "seconds: %d, fps: %d", seconds++, framecount);
		framecount = 0;
	}
	else
	{
		framecount++;
		mvprintw(2,1,"curr: %ld", curr->tv_nsec);
		mvprintw(3,1,"last: %ld", last->tv_nsec);
		mvprintw(4,1,"difference: %d",
				(int)(curr->tv_nsec - last->tv_nsec));
	}
}
