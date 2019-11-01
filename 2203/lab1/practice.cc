/* 
   practice.cc  -- Program to  ... (Fill this in) ...

   Author: Ryne Whitaker

   Modification History
   Date        Action
   09/17/18  -- Original version

   ID code: 5Ajt7FvyGJVdw
*/
using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
#include <ncurses.h>

int main () {
   initscr();
   cbreak();
   WINDOW * w;
   w = newwin(5, 5, 13, 15);
   wborder(w, '|', '|', '-', '-', '+', '+', '+', '+');
   wmove(w, 2, 1);
   wprintw(w, "Message");
   wrefresh;
   wgetch(w);
   endwin();
   return 0;
}

