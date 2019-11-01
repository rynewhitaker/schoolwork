/* 
   window.h  -- Program to  ... (Fill this in) ...

   Author: Ryne Whitaker

   Modification History
   Date        Action
   11/07/18  -- Original version

   ID code: 5Ajt7FvyGJVdw
*/
using namespace std;
#include <string>
#include <ncurses.h>
#include <sstream>
#ifndef WINDOW_H
#define WINDOW_H

int numRows() {int r, c; getmaxyx(stdscr, r, c); return r;}                
int numCols() {int r, c; getmaxyx(stdscr, r, c); return c;}  

class Window {
protected:
   WINDOW * window;
   string contents;
   string label;
public:

   Window(){}

   Window(int rows, int cols, int r, int c, string initialContents){
      window = newwin(rows, cols, r, c);
      contents = initialContents;
      waddstr(window, contents.c_str());
      wrefresh(window);
   }
   
   void write (string s) {
      contents += s;
      wmove(window, 0, 0);
      wclrtoeol(window);
      waddstr(window,contents.c_str());
      wrefresh(window);
   }
  
   void write (string s, double n) {
      write(s);
      write(":");
      write(n);
   }

   void write (double n) {
      stringstream ss;
      ss << n;
      string s = ss.str();
      write (s);   // call the string version
   }  


   void clear() {
      wclear(window);
      contents = label;
      write("");
   }
   
   void pause() {
      wgetch(window);
   }
};
#endif
