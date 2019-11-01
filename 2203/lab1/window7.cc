/* 
   window7.cc  -- Repeatedly read a win # and erase its char

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
   // Create 9 windows
   WINDOW *win1 = createWindow(4,4,'L');
   WINDOW *win2 = createWindow(4,8,'J'); 
   WINDOW *win3 = createWindow(4,12,'M');
   WINDOW *win4 = createWindow(8,4,'J');
   WINDOW *win5 = createWindow(8,8,'J');
   WINDOW *win6 = createWindow(8,12,'J');
   WINDOW *win7 = createWindow(12,4,'M');
   WINDOW *win8 = createWindow(12,8,'J');
   WINDOW *win9 = createWindow(12,12,'L');
  
   // Now read a window number to be erased
   // LINES == number of lines on the screen
   // COLS == number of columns on the screen
   // Create a window at the bottom of the screen
   WINDOW *command = newwin(1,20,LINES-1,0);
   wprintw(command,"Window number: " );
   wrefresh(command);
   char c;
   while ( (c = wgetch(command)) != 'q' ) {
      int n = c - '0';
      WINDOW *w;
      switch (n) {
         case 1: 
            w = win1;
            break;
         case 2: 
            w = win2;
            break;
         case 3: 
            w = win3;
            break;
         case 4: 
            w = win4;
            break;
         case 5: 
            w = win5;
            break;
         case 6: 
            w = win6;
            break;
         case 7: 
            w = win7;
            break;
         case 8: 
            w = win8;
            break;
         case 9: 
            w = win9;
            break;
      } 
      wmove(w,2,2);
      waddch(w,' ');  // erase the character in window w
      wrefresh(w);
      wmove(command,0,14);
      wclrtoeol(command);
      wrefresh(command);
   }
   endwin();
   return 0;
}

