///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 1
//  Due: 09/04/2019
//
//  Description: Header file for personal.cpp that contains declarations for
//  a new instance of the Personal class.  
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

#ifndef PERSONAL
#define PERSONAL

#include <fstream>
#include <cstring>
#include <iostream>
using namespace std; 

class Personal {
  public: 
	Personal();
	Personal(char * , char * , char * , int, long);
	void writeToFile(fstream&) const;
	void readFromFile(fstream&);
	void readKey();
	int size() const {
		return 9 + nameLen + cityLen + sizeof(year) + sizeof(salary);
	}
	bool operator == (const Personal& pr) const {
		return strncmp(pr.SSN, SSN, 9) == 0;
	}
  protected:
    const int nameLen, cityLen;
	char SSN[10], * name, * city;
	int year;
	long salary;
	ostream& writeLegibly(ostream&);
	friend ostream& operator << (ostream& out, Personal& pr) {
		return pr.writeLegibly(out);
	}
	istream& readFromConsole(istream&);
	friend istream& operator >> (istream& in, Personal& pr) {
		return pr.readFromConsole(in);
	}
};
#endif
