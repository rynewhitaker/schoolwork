#ifndef DEBUG_H
#define DEBUG_H
#include <ncurses.h>
#include <string>
using namespace std;
extern bool dbg;
void debug(string message);
int numRows();
int numCols();
#endif
