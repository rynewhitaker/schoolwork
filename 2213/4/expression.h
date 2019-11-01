///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 4 - expression.h
//  Due: 04/18/2019
//
//  Description:
//  The declarations for the functions found in expression.cpp are found in this
//  header file.  These are the functions used to read and write expressions to
//  and from inputfile and outputfile.
//
//  Input: None
//
//  Output: None
//
//  Assumptions:
//
//////////////////////////////////////////////////////////////////////////////
#ifndef EXPRESSION__H
#define EXPRESSION__H

#include <iostream>
#include <string>

///////////////////////////////////////////////////////////////////////////////
//
//  Function: class expression
//
//  Description: Declares the expression class and its members as either public
//  or private.
//
//  Preconditions: None
//
//  Postconditions: None
//
///////////////////////////////////////////////////////////////////////////////

class expression {
   public:
      bool last;
      expression();
      friend std::istream& operator >> (std::istream&, expression&);
      friend std::ostream& operator << (std::ostream&, const expression&);
   private:
      std::string ifix, pfix;
      void convertToPostfix();
      bool precedence(char, char) const;
};

#endif
