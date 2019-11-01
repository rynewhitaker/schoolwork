/* 
   window1.cc  -- Program to illustrate writing on the standard screen (stdscr)

   Author: Larry Morell

   Modification History
   Date        Action
   09/10/18  -- Original version

   ID code: 5AYVK3r3f.ARA
*/
using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
#include <ncurses.h>

int main () {
   initscr();
   cbreak();
   wmove(stdscr,10,20);
   wprintw(stdscr,"This is my first window message");
   wrefresh(stdscr);
   getch(); 
   endwin();
   return 0;
}

