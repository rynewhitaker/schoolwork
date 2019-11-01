#ifndef DEBUG_WINDOW
#define DEBUG_WINDOW
#include <sstream>
#include <ncurses.h>
#include "window.h"
class DebugWindow: public Window {
private:
   WINDOW *window;
   int pos;
   string contents;
   bool dodebug;
public:
   using Window::write;
   /*
   // Create a window a the bottom of the screen
   DebugWindow() {
      int r,c;
      // Set up debug window at the bottom of the screen
      dodebug = true;
      getmaxyx(stdscr,r,c);
      window = newwin(1,c,r-1,0);
      contents = "Debug: ";
      waddstr(window,contents.c_str() );
      wrefresh(window);
   }
   */
   DebugWindow(): Window(2, numCols(), numRows()-1, 0, "Debug: ") {
      label = "Debug: ";
   }

   DebugWindow(int rows, int cols, int r, int c, string in): Window(rows, cols, r, c, label) {
      label = in;
   }

   // off -- Turn debugging off
   void off() {dodebug = false;}

   // off -- turn debugging on
   void on() {dodebug = true;}

   // write -- Append string s to the debug window
   void write ( string s) {
      if (dodebug) {   // ignore if debug is off
         Window::write(s);
      }
   }

   // write -- Write integer n to the debug window
   void write (double n) {
      if (! dodebug) return;   // ignore if debug is off
         Window::write(n);   // call the string version
   }  

   // write -- Write s: n to the debug window
   void write (string s, double n) {
      if (! dodebug) return;   // ignore if debug is off
         Window::write(s, n);
   }

   /*
   // clear -- Clear the debug window and redisplay the prompt
   void clear() {
      wclear(window);
      contents = "Debug: ";
      write("");
   }
   */
};
#endif
