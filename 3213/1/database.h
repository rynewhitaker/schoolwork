///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 1
//  Due: 09/04/2019
//
//  Description: Header file that contains the declarations for all the variables
//  needed for a new instance of the Database class
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

#ifndef DATABASE
#define DATABASE
#include <iostream>
#include <fstream>
#include "personal.h"
using namespace std;

template <class T>
class Database {
public:
    Database();
    void run();
private:
    fstream database;
    char fName[20];
    ostream& print(ostream&);
    void add(T&);
    bool find(const T&);
    void modify(const T&);
    friend ostream& operator<<(ostream & out, Database & db) {
	  return db.print(out);
	}
};
#endif
