///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 4 - expression.cpp
//  Due: 04/18/2019
//
//  Description:
//  Contains the functions that are used for parsing the expressions found in
//  the inputfile.  This searches through the whitespace and extra lines to find
//  the expressions.  It also divides expressions when it finds a ; so that a
//  new expression can be started.  This handles the reading and writing of
//  expressions.
//
//  Input: A valid inputfile has to be supplied in order for this file to
//  work as designed.
//
//  Output: An output file of the designated name will be output containing the
//  expressions parsed from the inputfile.
//
//  Assumptions:
//
//////////////////////////////////////////////////////////////////////////////
#include "expression.h"
#include "stack.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Function: expression::expression()
//
//  Description: Empty constructor for expression.  Since there are no items
//  in the expression at the beginning, last is set to false until objects are
//  added.
//
//  Preconditions: None
//
//  Postconditions: ifix and pfix are set to "" and last is set to false
//
///////////////////////////////////////////////////////////////////////////////
expression::expression() {
   ifix = pfix = "";
   last = false;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void expression::convertToPostfix()
//
//  Description: Converts the expressions read in from inputfile from infix
//  to postfix by analyzing operators to determine precedence.
//
//  Preconditions: exp must have been read in from inputfile using istream
//
//  Postconditions: exp will be converted to postfix and will be stored as pfix
//
///////////////////////////////////////////////////////////////////////////////
void expression::convertToPostfix() {
   stack<char> st;

   st.push('$');
   pfix = "";
   for (size_t n = 0; n < ifix.size()-1; ++n) {
      switch(ifix[n]) {
         case '(' : st.push(ifix[n]);
         break;
         case ')' : while (st.top() != '(') {
                           pfix += st.top();
                           st.pop();
                           }
                           st.pop();
                           break;
         case '+'  :
         case '-'  :
         case '*'  :
         case '/'  : while (precedence(st.top(), ifix[n])) {
                        pfix += st.top();
                        st.pop();
                     }
                     st.push(ifix[n]);
                     break;
         default   : pfix += ifix[n];
      }
   }
   while (st.top() != '$') {
      pfix += st.top();
      st.pop();
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: bool expression::precedence(char s, char c) const
//
//  Description: Determines operator precedence for expressions.  * and / get
//  precedence while ( and $ do not.  Additionally if c is a + or a -, it will
//  be given precedence.
//
//  Preconditions: char s and char c must exist
//
//  Postconditions: true or false will be returned based on whether or not the
//  input char(s) get precedence.
//
///////////////////////////////////////////////////////////////////////////////
bool expression::precedence(char s, char c) const {
   if (s == '*' || s == '/') return true;
   if (s == '(' || s == '$') return false;
   return (c == '+' || c == '-');
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: std::istream& operator >> (std::istream& in, expression& exp)
//
//  Description: Determines how expressions will be read in from inputfile.
//  While sym isn't a ; or a . symbols are read in from the file.  If it reaches
//  a . it sets last to true which indicates that the end of the inputfile has
//  been reached.  It then converts the expressions to postfix.
//
//  Preconditions: A valid inputfile must be supplied by the user
//
//  Postconditions: The expressions read in from inputfile will be converted to
//  postfix to be used later in output.
//
///////////////////////////////////////////////////////////////////////////////
std::istream& operator >> (std::istream& in, expression& exp) {
   char sym;

   exp.ifix = "";
   do {
      in >> sym;
      exp.ifix += sym;
   } while (sym!= ';' && sym != '.');
   if (sym == '.') exp.last = true;
   exp.convertToPostfix();
   return in;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: std::ostream& operator << (std::ostream& out, const expression& exp)
//
//  Description: Outputs individual expressions to outputfile and divides them
//  between their infix versions and their postfix versions.  Each new expression
//  is printed on a new line.
//
//  Preconditions: A valid output file must be supplied by the user.
//
//  Postconditions: The expressions will be written to output file in infix and
//  postfix versions.
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& out, const expression& exp) {
   out << "Infix:    " << exp.ifix << std::endl;
   out << "Postfix:  " << exp.pfix << std::endl;
   return out;
}
