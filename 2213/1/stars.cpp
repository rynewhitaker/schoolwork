///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program #1
//  Due: 02/04/2019
//
//  Description:
//  This program is supposed to recursively print a star pattern in descending 
//  order first, then print it in ascending pattern again.  If the user enters
//  the positive integer 5, the program should print 5 stars, 4 stars,
//  all the way down to 1 star, then back up to 5.
//
//  Input:
//  The user should input a positive integer which is how many stars the 
//  program will begin printing
//
//  Output:
//  The program should output a star pattern of n to 1, then to -n.  For
//  example, if the user inputs 5, it should print 5, 4, 3, 2, 1, 1, 2, 3,
//  4, and 5 stars
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
//  Function: print(int b, int og);
//
//  Description:
//  This function prints the star pattern that is the goal of the program.
//  It prints a pattern of n to 1 stars, then 1 to n stars. 
//
//  Preconditions:
//  b and og have positive int values assigned to them.  b is the number the
//  user entered, and og is the original number the user entered.  b changes
//  as the program runs, but og is used to compare b to
//
//  Postconditions:
//  og is unchanged, but b is equal to negative og.  The function doesn't
//  return anything, but it outputs the star pattern to the screen.
//
///////////////////////////////////////////////////////////////////////////////

void print(int b, int og) {
   if (b == -og-1) return;
   for (int i=0; i < abs(b); i++) {		   
      cout << '*' << ' ';
   }
   if (b != 0) {
      cout << endl;
   }
   print(b-1, og);
}

int main () {
   int b = -1, og = -1;
   while (b < 0) {
   cout << "Enter a non-negative integer: ";
   cin >> b;
   }
   og = b;
   print(b, og);
   return 0;
}

