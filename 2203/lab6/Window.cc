#include "Window.h"

vector<Window *> Window::windowList;  //initialized to the empty vector
Window::Window () {}
// Create a window of size rows x cols at location (r,c) 
Window::Window (int rows, int cols, int r, int c, string initialContents) {
   window = newwin(rows, cols, r, c);
   contents = initialContents;
   waddstr(window,contents.c_str() );
   wrefresh(window);
   windowList.push_back(this);
}

// Write  string s  to the window at the current write position
void Window::write ( string s) {
   contents += s;
   refresh();
}

void Window::pause() {
   wgetch(window);
}

void Window::refresh() {
   //debug ("Refreshing a window");
   wmove(window,0,0);
   waddstr(window, contents.c_str());
   wrefresh(window);
}

// Write  double d  to the window at the current write position
void Window::write (double d) {
   stringstream ss;
   ss << d;
   string s = ss.str();
   write (s);   // call the string version
}  

// Write a  s:n  to the window at the current write position
void Window::write (string s, int n) {
   write(s);
   write(":");
   write(n);
}

// Clear the window from the screen but leave its contents intact
void Window::clear() {
   wclear(window);
   wmove(window,0,0);
}

// Pause in the current Window
void Window::pause();   // Prototype -- implementation moved to Window.cc

// Refresh the current window by redrawing its contents on the screen
void Window::refresh();  // Prototype -- implementation moved to Window.cc

// Refresh all the windows on the windowList
void Window::refreshAll() {
   for (auto w: windowList) {
      w->refresh();
   }
}

void Window::hideAll() {
   for (auto w: windowList) {
      w->hide();
   }
}

// Hide the current window by erasing it from windowList and clearing
// its screen 
void Window::hide() {
   int i;
   for (i=0; i < windowList.size() && windowList[i] != this; ++i);
    
   if (i < windowList.size()) { // found
      windowList.erase(windowList.begin() + i);
      //debug("Hiding window");
      wclear(window); wrefresh(window);
      //debug("Window is now hidden");
   }
  
   refreshAll ();
}
void Window::show() {
   int i;
   //  debug("Calling show");
   // for (i=0; i < windowList.size() && windowList[i] != this; ++i);
   // if (i >= windowList.size()) { // not found; add it
      windowList.push_back(this); 
   // }
   refreshAll(); 
   //   debug("Window is now shown");
}
WINDOW * Window::getWindow() {return window;}
   

