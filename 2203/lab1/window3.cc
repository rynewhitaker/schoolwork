/* 
   window2.cc  -- Program to  create an additional window and write to it

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
   char message[] = "This is my first message";
   WINDOW *win = newwin(5,40,4,4); // Size 5 x 5 at (4,4)
   wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
   wmove(win,2,1);
   wprintw(win,message);
   wrefresh(win);
   wgetch(win); 
   endwin();
   return 0;
}

