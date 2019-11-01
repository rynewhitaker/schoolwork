/* 
   window5.cc  -- Program to create 9 windows using a subroutine

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
WINDOW* createWindow(int row, int col, char letter) {
   WINDOW *w = newwin(5,5,row,col); // Size 5 x 5 at (row,col)
   wborder(w, '|', '|', '-', '-', '+', '+', '+', '+');
   wmove(w,2,2); waddch(w,letter);
   wrefresh(w);
   return w;
}
int main () {
   initscr();
   cbreak();
   char message[] = "This is my first message";
   WINDOW *win1 = createWindow(4,4,'L');
   WINDOW *win2 = createWindow(4,8,'J'); 
   WINDOW *win3 = createWindow(4,12,'M');
   WINDOW *win4 = createWindow(8,4,'J');
   WINDOW *win5 = createWindow(8,8,'J');
   WINDOW *win6 = createWindow(8,12,'J');
   WINDOW *win7 = createWindow(12,4,'M');
   WINDOW *win8 = createWindow(12,8,'J');
   WINDOW *win9 = createWindow(12,12,'L');
   wgetch(win1); 
   endwin();
   return 0;
}

