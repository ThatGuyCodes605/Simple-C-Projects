#include <ncurses.h>
int main() {
		initscr(); // Initialize the ncurses library
		printw("Hello, World!"); // Print "Hello, World!" to the screen
		refresh(); // Refresh the screen to show the changes
		int c = getch(); // Wait for user input
		printw("You pressed: %c", c); // Print the character that was pressed	
		getch(); // Wait for user input
		/*   y  x     */
		/*   V  V     */
		move(5, 10); // Move the cursor to row 5, column 10
		printw("Goodbye!"); // Print "Goodbye!" to the screen
		refresh(); // Refresh the screen to show the changes
		getch(); // Wait for user input
		mvprintw(7, 20, "Press any key to exit..."); // Move to row 7, column 20 and print a message
		refresh(); // Refresh the screen to show the changes
		getch(); // Wait for user input
		clear(); // Clear the screen
		refresh(); // Refresh the screen to show the changes
		endwin(); // End ncurses mode
		return 0;
}
