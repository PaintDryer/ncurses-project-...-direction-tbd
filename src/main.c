#include <ncurses.h>
#include <unistd.h>
#include "vec2.h"
#include "deltatime.h"

#define DEBUG 1
int main(void) {
	initscr();				// start curses mode
	noecho();				// no echo
	raw();					// no line buffering
	keypad(stdscr, TRUE);	// F keys
	
	timeout(1);
	timepoint	lastframe = set_now(NULL);
	
	char c = getch();
	while (!(c == KEY_F(1) || c == 'q'))
	{
		timepoint currenttime = set_now(NULL);
		double deltatime = time_diff(&currenttime, &lastframe);
		if (deltatime >= 16.0 * MILLION) // ns -> ms
		{
			if (DEBUG)
				display_fps(&currenttime, &lastframe, &deltatime);
			set_now(&lastframe);
		}
		c = getch();
		if (c != ERR)
			mvprintw(10,10, "%c", c);
	}
	endwin();
	return 0;
}
