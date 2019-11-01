///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 1
//  Due: 09/04/2019
//
//  Description: Header file that contains the declarations for all the variables
//  needed for a new instance of the Student class
//
//  Input: None
//
//  Output: None
//
//  Assumptions: None
//
//  Special Processing Requirements: None
//
///////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT
#define STUDENT
#include <iostream>
#include "personal.h"
using namespace std;

class Student : public Personal
{
public:
    Student();
    Student(char*, char*, char*, int, long, char*);
    void writeToFile(fstream&) const;
    void readFromFile(fstream&);
    int size() const {
	  return Personal::size() + majorLen;
	}
protected:
    char *major;
    const int majorLen;
    ostream& writeLegibly(ostream&);
    friend ostream& operator<<(ostream& out, Student& sr) {
	  return sr.writeLegibly(out);
	}
    istream& readFromConsole(istream&);
    friend istream& operator>>(istream& in, Student& sr) {
      return sr.readFromConsole(in);
	}
};

#endif
