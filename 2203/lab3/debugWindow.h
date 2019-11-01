/* 
   debugWindow.h  -- Program to  ... (Fill this in) ...

   Author: Ryne Whitaker

   Modification History
   Date        Action
   10/17/18  -- Original version

   ID code: 5Ajt7FvyGJVdw
*/
using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
#include <ncurses.h>

class DebugWindow {
private:
   WINDOW *debug;      //  ncurses window
   string contents;
   bool dodebug;       
   //int r, c;   
public:
   int r, c;   
   // Create a Debug window at the bottom of the screen (last line, full width)
   DebugWindow() {
   if (dodebug == true) {
      getmaxyx(stdscr, r, c);
      debug = newwin(1, c, r-1, 0);
      wmove(debug, 0, 0);
   }
   }
  
   // Turn debugging off
   void off() {
   dodebug = false;
   }
  
   // Turn debugging on
   void on() {
   dodebug = true;
   }
  
   // Print a string to the debug window
   void write (string s) {
   if (dodebug == true) {
      wmove(debug, r-1, 7);
      //waddstr(debug, "Debug: ");
      contents = s.c_str();
      waddstr(debug, contents.c_str());
      //waddstr(debug, s.c_str());
      contents = "Debug: ";
      wrefresh(debug); 
   }
   }
  
   // Print a character to the debug window
   void write (char ch) {
   if (dodebug == true) {
      wmove(debug, r-1, 7);
      //waddstr(debug, "Debug: ");
      //waddstr(debug, contents.c_str());
      waddch(debug, ch); 
      wrefresh(debug); 
   }
   }  
  
   // Print an integer to the debug window
   void write (int n) {
   if (dodebug == true) {
      wmove(debug, r-1, 7);
      //waddstr(debug, "Debug: ");
      string nStr = to_string(n);
      contents = nStr;
      waddstr(debug, contents.c_str());
      //waddstr(debug, nStr.c_str());
      //contents = "Debug: ";
      wrefresh(debug); 
   }
   }  
  
   // Print a string followed by an integer to the debug window
   void write (string s, int n) {
   if (dodebug == true) {
      wmove(debug, r-1, 7);
      //waddstr(debug, "Debug: ");
      string nStr = to_string(n);
      contents = s + " " + nStr.c_str();
      waddstr(debug, contents.c_str());
      wrefresh(debug); 
   }
   }
   
   // Clear the debug window (and its string buffer)
   void clear() {
   werase(debug);
   wmove(debug, r-1, 0);
   waddstr(debug, "Debug: ");
   wrefresh(debug);
   } 
  
   // Pause the program by waiting for input
   void pause() {
   wgetch(debug);
   } 
};

