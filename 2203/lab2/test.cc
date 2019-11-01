/* 
   test.cc  -- Program to  ... (Fill this in) ...

   Author: Ryne Whitaker

   Modification History
   Date        Action
   09/30/18  -- Original version

   ID code: 5Ajt7FvyGJVdw
*/
using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
#include <ncurses.h>
#include <vector>

vector <int> buffer;

void print(){
   cout << "buffer contains: ";
   for (int i = 0; i < buffer.size(); i++)
        cout << ' ' << buffer[i];
   cout << endl;
}

int main () {
   for (int i = 0; i < 10; i++)
	buffer.push_back(i);
   print();
   
   buffer.erase(buffer.size());
   print();
   return 0;
}

