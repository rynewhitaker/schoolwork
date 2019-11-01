/* 
   stars.cpp  -- Program to  ... (Fill this in) ...

   Author: Ryne Whitaker

   Modification History
   Date        Action
   01/26/19  -- Original version

   ID code: 5Ajt7FvyGJVdw
*/
using namespace std;
#include <iostream>
#include <string>

void print(int b) {
   if (b == 0) return;
   for (int i = 0; i < b; ++i) {
	   cout << '*' << ' ';
   }
   cout << endl;
   print(b-1);
}

int main () {
   int b = 0;
   cout << "Enter a positive integer: ";
   cin >> b;
   print(b);
   return 0;
}

