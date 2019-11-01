#ifndef WINDOW_H
#define WINDOW_H
// Window.h file -- 
#include <ncurses.h>
#include <sstream>
#include <string>
#include <vector>
#include "Debug.h"
// A generic window class
class Window {
protected:
   static vector<Window *> windowList;  //initialized to the empty vector
   string contents;   // contents of the window
   WINDOW *window ;   // screen representation of the window
public:
   Window ();  // Prototype -- implementation moved to Window.cc

/*
   // Create a window that is copy of Window w
   Window (Window &w) {
      window = w.window;
      contents = w.contents;
      w.hide();
      windowList.push_back(this);
   }
*/
   // Create a window of size rows x cols at location (r,c) 
   Window (int rows, int cols, int r, int c, string initialContents);
   // Write  string s  to the window at the current write position
   virtual void write ( string s);
   // Write  double d  to the window at the current write position
   virtual void write (double d);

   // Write a  s:n  to the window at the current write position
   void write (string s, int n);

   // Clear the window from the screen but leave its contents intact
   virtual void clear();

   // Pause in the current Window
   void pause();   // Prototype -- implementation moved to Window.cc

   // Refresh the current window by redrawing its contents on the screen
   virtual void refresh();  // Prototype -- implementation moved to Window.cc
   
   // Hide all the windows on the windowList
   void hideAll();

   // Refresh all the windows on the windowList
   void refreshAll();

   // Hide the current window by erasing it from windowList and clearing
   // its screen 
   virtual void hide();
   void show();

   // Return access to the underlying WINDOW
   WINDOW * getWindow();
   
};

#endif
