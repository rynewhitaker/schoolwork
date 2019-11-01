#ifndef BORDEREDWINDOW_H
#define BORDEREDWINDOW_H
#include "Window.h"
using namespace std;
class BorderedWindow: public Window {
private:
   WINDOW *frame;
   Window win;  // The contained window
public:
   BorderedWindow(Window &win) : Window (win) {
      this->win = win; 
      WINDOW *w = win.getWindow();
      int rows, cols, r, c;
      getmaxyx(w,rows,cols);    // get size
      wmove(w,0,0);
      getbegyx(w,r,c);    // of the window on the screen
      mvwin(w,r+1,c+1);
      frame = newwin(rows+2, cols +2, r,c);
      box (frame,0,0);
      debug("showing frame");
      wrefresh(frame);
/*
      win.write(rows); win.write(" ");
      win.write(cols); win.write(" ");
      win.write(r); win.write(" ");
      win.write(c); win.write(" ");
      win.refresh();
*/
   }
   void pause() { wmove(frame,1,1); wgetch(frame); }
   void write(string s) { win.write(s);}
   void refresh() { 
      debug("Refreshing a bordered window");
      box(frame,0,0); wrefresh (frame); 
      win.refresh ();
   }
   void hide() {
      int i;
      for (i=0; i < windowList.size() && windowList[i] != this; ++i);
       
      if (i < windowList.size()) { // found
         windowList.erase(windowList.begin() + i);
         debug("Hiding bordered window");
         wclear(frame); wrefresh(frame);
         debug("Bordered Window is now hidden");
      }
      refreshAll ();
   }
};
#endif
