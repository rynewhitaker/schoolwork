#include "Debug.h"
bool dbg = true;
using namespace std;
void debug(string message) {
   if( dbg ) {
      WINDOW *debug = newwin(3,COLS,LINES-3,0);
      box (debug,0,0);
      wmove(debug,1,1);
      waddstr (debug, message.c_str()); 
      wrefresh(debug);
      wgetch(debug);
      delwin(debug);
   }
}
int numRows() { int r,c; getmaxyx(stdscr,r,c); return r; }
int numCols() { int r,c; getmaxyx(stdscr,r,c); return c; }
