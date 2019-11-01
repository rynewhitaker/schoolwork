/*
main.cc  -- Program to read commands typed in one window and write them to another

Author: Larry Morell

Modification History
Date        Action
10/15/18  -- Original version

*/
using namespace std;
#include <string>
#include "DebugWindow.h"
#include "CommandWindow.h"

int main () {
   initscr();
   cbreak(); 
   DebugWindow debugWindow;
   debugWindow.on();
   CommandWindow commandWindow = CommandWindow();
   string command = commandWindow.readString();
   while ( ! (command == "q" or command == "Q" )) {
      debugWindow.write (command);
      commandWindow.clear();
      command = commandWindow.readString();
      debugWindow.clear();
   }
   endwin();
   return 0;
}
