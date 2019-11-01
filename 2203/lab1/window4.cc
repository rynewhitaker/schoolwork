/* 
   window4.cc  -- Program to create 9 windows in a grid and populate with initiaals

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

   WINDOW *win1 = newwin(5,5,4,4); // Size 5 x 5 at (4,4)
   wborder(win1, '|', '|', '-', '-', '+', '+', '+', '+');
   wmove(win1,2,2); waddch(win1,'L');
   wrefresh(win1);

   WINDOW *win2 = newwin(5,5,4,8); // Size 5 x 5 at (4,8)
   wborder(win2, '|', '|', '-', '-', '+', '+', '+', '+');
   wmove(win2,2,2); waddch(win2,'J');
   wrefresh(win2);

   WINDOW *win3 = newwin(5,5,4,12); // Size 5 x 5 at (4,12)
   wborder(win3, '|', '|', '-', '-', '+', '+', '+', '+');
   wmove(win3,2,2); waddch(win3,'M');
   wrefresh(win3);

   WINDOW *win4 = newwin(5,5,8,4); // Size 5 x 5 at (8,4)
   wborder(win4, '|', '|', '-', '-', '+', '+', '+', '+');
   wmove(win4,2,2); waddch(win4,'J');
   wrefresh(win4);

   WINDOW *win5 = newwin(5,5,8,8); // Size 5 x 5 at (8,8)
   wborder(win5, '|', '|', '-', '-', '+', '+', '+', '+');
   wmove(win5,2,2); waddch(win5,'J');
   wrefresh(win5);

   WINDOW *win6 = newwin(5,5,8,12); // Size 5 x 5 at (8,12)
   wborder(win6, '|', '|', '-', '-', '+', '+', '+', '+');
   wmove(win6,2,2); waddch(win6,'J');
   wrefresh(win6);

   WINDOW *win7 = newwin(5,5,12,4); // Size 5 x 5 at (12,4)
   wborder(win7, '|', '|', '-', '-', '+', '+', '+', '+');
   wmove(win7,2,2); waddch(win7,'M');
   wrefresh(win7);

   WINDOW *win8 = newwin(5,5,12,8); // Size 5 x 5 at (12,8)
   wborder(win8, '|', '|', '-', '-', '+', '+', '+', '+');
   wmove(win8,2,2); waddch(win8,'J');
   wrefresh(win8);

   WINDOW *win9 = newwin(5,5,12,12); // Size 5 x 5 at (12,12)
   wborder(win9, '|', '|', '-', '-', '+', '+', '+', '+');
   wmove(win9,2,2); waddch(win9,'L');
   wrefresh(win9);
   wgetch(win9); 

   endwin();
   return 0;
}

