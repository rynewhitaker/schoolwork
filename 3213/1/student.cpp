///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 1
//  Due: 09/04/2019
//
//  Description: The cpp file that imports student.h and deals with entering
//  student records into the database.  This has all the functions
//  for reading/writing student data to/from the database.  This also has the
//  iostreams for reading in and writing out data to/from the screen.
//
//  Input: Student data is entered into the functions contained in this file
//  to be entered into the database.
//
//  Output: Can output the student data entered/found in the database but
//  doesn't necessariy have an output.
//
//  Assumptions: None
//
//  Special Processing Requirements: Needs to be compiled at the same time as 
//  personal.cpp and database.cpp
//
///////////////////////////////////////////////////////////////////////////////

#include "student.h"
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
//  Function: Student::Student() : majorLen(10)
//
//  Description: Default constructor for Personal that sets name, city, and major
//
//  Preconditions: None
//
//  Postconditions: Name, city, and major have values
//
///////////////////////////////////////////////////////////////////////////////
Student::Student() : majorLen(10) {
    Personal();
    major = new char[majorLen + 1];
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: Student::Student(char *ssn, char *n, char *c, int y, long s, char *m) : majorLen(11)
//
//  Description: Constructor for Personal that takes SSN, name, city, year and major
//  and sets their variables to them
//
//  Preconditions: None
// 
//  Postconditions: The data passed in is stored in their respective variables.
//
///////////////////////////////////////////////////////////////////////////////
Student::Student(char *ssn, char *n, char *c, int y, long s, char *m) : majorLen(11) {
    Personal(ssn, n, c, y, s);
    major = new char[majorLen + 1];
    strcpy(major, m);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void Student::writeToFile(fstream& out) const
//
//  Description: Writes all the data the user input into the database specified
//  using the Personal writeToFile function and the regular write function
//
//  Preconditions: A database must exist
//
//  Postconditions: The data the user input now exists in the specified database.
//
///////////////////////////////////////////////////////////////////////////////
void Student::writeToFile(fstream& out) const {
    Personal::writeToFile(out);
    out.write(major, majorLen);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void Student::readFromFile(fstream& in)
//
//  Description: Reads all the stored data in from the database specified.
//
//  Preconditions: The necessary data must exist in the database specified.
//
//  Postconditions: The data read in from the database will be stored in their
//  respective variables.
//
///////////////////////////////////////////////////////////////////////////////
void Student::readFromFile(fstream& in) {
    Personal::readFromFile(in);
    in.read(major, majorLen);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: ostream& Student::writeLegibly(ostream& out)
//
//  Description: Outputs SSN, name, city, year, and major to the screen,
//  labeled with their variable name and delimeted by commas
//
//  Preconditions: SSN, name, city, year, and major must all have values
//
//  Postconditions: SSN, name, city, year, and major are output to the screen
//
///////////////////////////////////////////////////////////////////////////////
ostream& Student::writeLegibly(ostream& out) {
    Personal::writeLegibly(out);
    major[majorLen] = '\0';
    out << ", major = " << major;
    return out;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: istream& Student::readFromConsole(istream& in)
//
//  Description: Reads in values for SSN, name, city, year, and major from
//  the command line as the user inputs them and stores them in their respective
//  variables.
//
//  Preconditions: SSN, name, nameLen, city, cityLen, year, and major must exist
//
//  Postconditions: SSN, name, nameLen, city, cityLen, year, and major all have
//  values
//
///////////////////////////////////////////////////////////////////////////////
istream& Student::readFromConsole(istream& in) {
    Personal::readFromConsole(in);
    char s[80];
    cout << "Major: ";
    in.getline(s, 80);
    strncpy(major, s, 9);
    return in;
}
