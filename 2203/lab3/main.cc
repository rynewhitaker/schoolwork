/* 
   main.cc  -- Program to  ... (Fill this in) ...

   Author: Ryne Whitaker

   Modification History
   Date        Action
   10/17/18  -- Original version

   ID code: 5Ajt7FvyGJVdw
*/
using namespace std;
#include <string>
#include "debugWindow.h"
#include "commandWindow.h"
  
DebugWindow debugWindow;
int main () {
   initscr();
   cbreak(); 
   debugWindow = DebugWindow(); 
   debugWindow.on();
   CommandWindow commandWindow = CommandWindow();
   
   debugWindow.clear();
   commandWindow.clear();

   string command = commandWindow.readString();
   while ( ! (command == "q" or command == "Q" )) {
      debugWindow.write (command);
      commandWindow.write(command);
      commandWindow.clear();
      command = commandWindow.readString();
      debugWindow.clear();
   }
   endwin();
}
