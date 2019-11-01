#ifndef DEBUG_WINDOW
#define DEBUG_WINDOW
#include "Window.h"
using namespace std;
class DebugWindow: public Window {
private:
   bool dodebug;
   string label;

public:

   DebugWindow(): 
     Window(1,numCols(),numRows()-1,0, "Debug: ") 
   {
     label = "Debug:";
     dodebug = true; 
   }

   DebugWindow(int rows, int cols, int r, int c, string label): 
      Window(rows,cols,r,c ,label) 
   {
      dodebug = true; 
      this->label = label; 
      wmove(window,0,0);
      write("");
   }


   using Window::write;
   void off() { dodebug = false;}
   void on() { dodebug = true;}
   void write ( string s) {
      if (dodebug) {   // ignore if window is off
         Window::write(s);
      }
   }
   void write (double d) {
      if (! dodebug) return;   // ignore if window is off
      Window::write(d);
   }  
   void write (string s, double n) {
      if (! dodebug) return;   // ignore if window is off
      Window::write(s,n);
   }
   void clear() {
      Window::clear();
      write(label);
   }
};
#endif
