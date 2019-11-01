/* 
   window7.cc  -- Repeatedly read a win # and erase its char with windows in a 3 x 3 grid

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

void updateDisplay(WINDOW *w, char ch) {
   wmove(w,2,2);
   waddch(w,ch);
   wrefresh(w);
}

int main () {
   initscr();
   cbreak();
   //  Set up the model -- the data that underlies the display
   char model[3][3]  { 
       {'a', 'b', 'c' },
       {'d', 'e', 'f' },
       {'g', 'h', 'i' }
   };

   // Set up the 3 x 3 display
   // There are 3 rows, positioned at 4, 8, and 12
   // There are 3 cols, positioned at 4, 8, and 12
   WINDOW *display[3][3];
   int r, c;
   for (r=0; r < 3; ++r) {  // iterate through the rows
      for (c=0; c < 3; ++c ) {  // iterate through the cols
         // Place the char at model[r][c] in display [r][c]
         display[r][c] = createWindow(4*(r+1),4*(c+1), model[r][c]) ;
      }
   }
  
   // Create a window at the bottom of the screen
   // LINES == number of lines on the screen, defined in curses.h
   // COLS == number of columns on the screen, defined in curses.h

   WINDOW *command = newwin(1,20,LINES-1,0);
   wprintw(command,"Window: " );
   wrefresh(command);

   // Now repeatedly read a letter to be removed
   // from the 3 x 3 grid, find that letter, and
   // remove it from the grid, then redisplay

   char ch;
   while ( (ch = wgetch(command)) != 'q' ) {
      WINDOW *w;
      // Find the window with c in it; 

      for (r = 0; r < 3; ++r) {
         for (c = 0; c < 3; ++c) {
            if ( model[r][c] == ch ) {  // found the character
               model[r][c] = ' '; // Change the model
               w = display[r][c]; 
               updateDisplay(w,' ');
            } 
         }
      }

      // clear previously typed command 
      wmove(command,0,8);
      wclrtoeol(command);
      wrefresh(command);
   }
   endwin();
   return 0;
}

