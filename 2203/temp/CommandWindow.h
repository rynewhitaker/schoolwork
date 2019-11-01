#ifndef COMMAND_WINDOW
#define COMMAND_WINDOW
#include <ncurses.h>
#include <sstream>
#include <string>
#include "window.h"
using namespace std;
class CommandWindow: public Window {
private:
   WINDOW *window;
   string contents;
public:
   using Window::write;
   /*
   // Create a command window in the next-to-last row from the bottom of the screen
   CommandWindow() {
      int r,c;
      // Set up command window next to bottom line of the screen
      getmaxyx(stdscr,r,c);
      window = newwin(1,c,r-2,0);
      contents = "Command: ";
      waddstr(window, contents.c_str() );
      wrefresh(window);
   }
   */

   CommandWindow(): Window(1, numCols(), numRows()-2, 0, "Command: ") {
      label = "Command: ";
   }
   
   CommandWindow(int rows, int cols, int r, int c, string in): Window(rows, cols, r, c, label) {
      label = in;
   }

   // readInt -- Read an integer from the command window
   int readInt() {
      char line[101];
      wmove(window,0,9);
      wgetnstr(window,line,100);  
      return atoi(line);
   }

   // readInt -- Read a double from the command window
   double readDouble() {
      char line[101];
      wmove(window,0,9);
      wgetnstr(window,line,100);  
      return atof(line);
   }

   // readInt -- Read a string from the command window (up to 100 chars)
   string readString() {
      char line[101];
      wmove(window,0,9);
      wgetnstr(window,line,100);  
      return string(line);
   }
   
   /*
   // clear -- Clear the command window and redisplay the prompt
   void clear() {
      wclear(window);
      contents = "Command: ";
      write("");
   }
   */
};
#endif
