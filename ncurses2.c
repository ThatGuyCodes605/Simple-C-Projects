#include <ncurses.h>
int main(void){
	initscr();
	cbreak(); //cbreak() disables line buffering and allows the program to receive input immediately without waiting for a newline character. This is useful for interactive applications where you want to respond to user input in real-time.
	printw("Hello, World!");
	refresh();
	raw(); //raw mode disables line buffering and special character processing, allowing the program to read input directly from the user without waiting for a newline character. This is useful for real-time applications like games or interactive interfaces.
	noecho(); //noecho() disables the automatic echoing of typed characters to the screen. This is often used in conjunction with raw mode to prevent user input from being displayed, which can be useful for password input or other sensitive data.
	getch();
	WINDOW *win = newwin(10, 30, 5, 5); // Create a new window with height 10, width 30, and position (5, 5)
	box(win, 0, 0); // Draw a box around the window
	mvwprintw(win, 1, 1, "This is a new window!"); // Print text inside the window at position (1, 1)
	wrefresh(win); // Refresh the window to show the changes
	getch();
	delwin(win); // Delete the window
	endwin();
}
