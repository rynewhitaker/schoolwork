/* 
   debugTest.cc  -- Program to  ... (Fill this in) ...

   Author: Ryne Whitaker

   Modification History
   Date        Action
   10/23/18  -- Original version

   ID code: 5Ajt7FvyGJVdw
*/
using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
#include <ncurses.h>
#include "debugWindow.h"



int main () {
   initscr();
   cbreak();
   DebugWindow debugWindow = DebugWindow();
   
   wmove(stdscr, 1, 0);
   waddstr(stdscr, "Press any key to iterate through the tests or press [ctrl + c] to abort");
   wrefresh(stdscr);
   debugWindow.clear();
   
   // Enable debug window printing
   debugWindow.on();
   debugWindow.clear();

   // The string "x" should output in the debug window, increasing by one "x" each iteration, until 100 "x"-es
   //string message = "";
   for (int i = 0; i <= 100; i++) {
      string message (i, 'x');
      wmove(stdscr, 2, 0);
      //string size = to_string(message.size());
      waddstr(stdscr, message.c_str());
      wrefresh(stdscr);
      debugWindow.write(message);
      debugWindow.pause();
      debugWindow.clear();
   }

   // "0" through "100" should output in the debug window
   for (int i = 0; i <= 100; i++) {
      debugWindow.write(i);
      debugWindow.pause();
      debugWindow.clear();
   }

   // "a" through "z" should output in the debug window
   for (char i = 'a'; i <= 'z'; i++) {
      debugWindow.write(i);
      debugWindow.pause();
      debugWindow.clear();
   }

   // "Testing string and int write 25" should output in the debug window
   debugWindow.write("Testing string and int write", 25);
   debugWindow.pause();
   debugWindow.clear();

   
   endwin();
   return 0;
}

