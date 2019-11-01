/* 
   commandTest.cc  -- Program to  ... (Fill this in) ...

   Author: Ryne Whitaker

   Modification History
   Date        Action
   10/24/18  -- Original version

   ID code: 5Ajt7FvyGJVdw
*/
using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
#include <ncurses.h>
#include "CommandWindow.h"

int main () {
   initscr();
   cbreak();

   CommandWindow commandWindow = CommandWindow();
   commandWindow.clear();
   
   // Test readString function
   wmove(stdscr, 1, 0);
   waddstr(stdscr, "Enter a string or \"q\" or \"Q\" to continue to the next test.");
   wrefresh(stdscr);
   commandWindow.clear();

   string command = commandWindow.readString();
   while ( ! (command == "q" or command == "Q" )) {
      commandWindow.write(command);
      commandWindow.clear();
      command = commandWindow.readString();
   }
  
   werase(stdscr);
   commandWindow.clear();

   // Test readInt function
   wmove(stdscr, 1, 0);
   waddstr(stdscr, "Enter an integer or \"-1\" to continue to the next test.");
   wrefresh(stdscr);
   commandWindow.clear();

   int n = commandWindow.readInt();
   while ( ! (n == -1)) {
      commandWindow.write(n);
      commandWindow.clear();
      n = commandWindow.readInt();
   }

   werase(stdscr);
   commandWindow.clear();
   
   // Test readDouble function
   wmove(stdscr, 1, 0);
   waddstr(stdscr, "Enter a double or \"-1\" to continue to the next test.");
   wrefresh(stdscr);
   commandWindow.clear();

   double dub = commandWindow.readDouble();
   while ( ! (dub == -1)) {
      commandWindow.write(dub);
      commandWindow.clear();
      dub = commandWindow.readDouble();
   }

   endwin();
   return 0;
}

