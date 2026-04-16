#include <stdio.h>
#include <ncurses.h>
#define COLOR_LIME 10
int main(int argc, char** argv)
{
	initscr();
	/* fill the screen with blue background and white text */
	/* LINES and COLS are global variables that hold the number of lines and columns of the terminal */
	WINDOW* win = newwin(25, 80, 23, 7); /* this creates a new window with height 25, width 80, starting at line 23 and column 7 */
	refresh(); /* Refresh the standard screen to show the new window */
	box(win, 0, 0); /* Draw a box around the window */
	mvwprintw(win, 5, 5, "Hello, ncurses!");
	wrefresh(win); /* Refresh the window to show the changes */
	getch(); /* Wait for user input */
	endwin(); /* End ncurses mode */
	return 0;
}
