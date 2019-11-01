///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program #4 - in2post.cpp
//  Due: 04/18/2019
//
//  Description:
//  This program takes one input file and one output file as arguments.  It uses
//  functions from files such as expression.cpp, QNodeType.h, queue.h, and stack.h
//  to read in an input file with infix notation and convert it to postfix notation
//  and output it into the designated output file.  If the arguments passed to the
//  program at runtime are wrong, the user will be given an error message.  The
//  correct way to run the program is with "a.out inputfile outputfile" where
//  "inputfile" is the name of the file to be converted to postfix, and "outputfile"
//  is the name of the file that the converted calculations will be output to.
//
//  Input:
//  An input file must be supplied to the program when it is run, and in the case of
//  my testing, its name was in2post.cpp.  This file had a series of calculations in
//  infix notation with white space and extra lines added in for garbage.
//
//  Output:
//  This program will convert the calculations included in the input file to postfix
//  notation and output them to the designated output file.
//
//  Assumptions:
//
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "queue.h"
#include "expression.h"

using namespace std;

int main(int argc, char *argv[]) {
   // Declarations
   expression e;
   ifstream fin;
   ofstream fout;
   queue<expression> q;

   // If user tries to run the program without inputfile and/or outputfile, an error will be displayed
   if (argc != 3) {
      cerr << "Error in call. Should be " << argv[0] << " inputfile outputfile" << endl;
      return -1;
   }

   // Open the input and output files for reading and writing
   fin.open(argv[1]);
   fout.open(argv[2]);

   // Read in the calculations from inputfile and push them onto q
   do {
      fin >> e;
      q.push(e);
   } while (!e.last);

   // Close the inputfile
   fin.close();

   // Output the converted calculations to the designated outputfile
   while (!q.empty()) {
      fout << q.front();
      q.pop();
   }

   // Close the outputfile
   fout.close();

   return 0;
}
