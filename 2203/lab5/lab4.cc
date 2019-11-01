/*
main.cc  -- Program to read commands typed in one window and write them to another

Author: Ryne Whitaker

Modification History
Date        Action
10/15/18  -- Original version

*/
using namespace std;
#include <string>
using namespace std;
#include "DebugWindow.h"
#include "CommandWindow.h"

int main () {
   initscr();
   cbreak(); 
   DebugWindow debugWindow; //(10, 20, 30,40,"New Debug");;
   debugWindow.on();
   CommandWindow commandWindow;
   
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
