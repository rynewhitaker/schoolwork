/* 
   practice2.cc  -- Program to  ... (Fill this in) ...

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
   int array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   cout << array[0][0];
   endwin();
   return 0;
}

