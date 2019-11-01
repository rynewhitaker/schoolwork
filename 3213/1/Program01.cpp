///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 1
//  Due: 09/04/2019
//
//  Description: Header file for personal.cpp that contains declarations for
//  a new instance of the Personal class.  The define statements have been
//  taken out because I have combined all the files into one and so it no
//  longer needs them. 
//
//  Input: None
//
//  Output: None
//
//  Assumptions: None
//
//  Special Processing Requirements: A database file needs to be made before 
//  running the program.
//
///////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <cstring>
#include <iostream>
using namespace std; 

class Personal {
  public: 
	Personal();
	Personal(char* , char* , char* , int, long);
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
	char SSN[10], *name, *city;
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

///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 1
//  Due: 09/04/2019
//
//  Description: The cpp file that deals with entering
//  non-student (personal) records into the database.  This has all the functions
//  for reading/writing personal data to/from the database.  This also has the
//  iostreams for reading in and writing out data to/from the screen.
//
//  Input: Personal data is entered into the functions contained in this file
//  to be entered into the database.
//
//  Output: Can output the personal data entered/found in the database but
//  doesn't necessariy have an output.
//
//  Assumptions: None
//
//  Special Processing Requirements:  A database file needs to be made before 
//  running the program. Needs to be compiled at the same time as 
//  student.cpp and database.cpp
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Function: Personal::Personal() : nameLen(10), cityLen(10)
//
//  Description: Default constructor for Personal that sets name and city
//
//  Preconditions: None
//
//  Postconditions: Name and city have values
//
///////////////////////////////////////////////////////////////////////////////
Personal::Personal() : nameLen(10), cityLen(10){
  name = new char[nameLen+1];
  city = new char[cityLen+1];
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: Personal::Personal(char *ssn, char *n, char *c, int y, long s) : nameLen(10), cityLen(10)
//
//  Description: Constructor for Personal that takes SSN, name, city, year and salary
//  and sets their variables to them
//
//  Preconditions: SSN, name, city, year, and salary must be passed into the constructor
//  with their respective types.
//
//  Postconditions: The data passed in is stored in their respective variables.
//
///////////////////////////////////////////////////////////////////////////////
Personal::Personal(char *ssn, char *n, char *c, int y, long s) : nameLen(10), cityLen(10) {
  name = new char[nameLen+1];
  city = new char[cityLen+1];
  strcpy(SSN,ssn);
  strcpy(name,n);
  strcpy(city,c);
  year = y;
  salary = s;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void Personal::writeToFile(fstream& out) const
//
//  Description: Writes all the data the user input into the database specified.
//
//  Preconditions: SSN, name, nameLen, city, cityLen, year, and salary must
//  all have values
//
//  Postconditions: SSN, name, nameLen, city, cityLen, year, and salary are 
//  written into the database
//
///////////////////////////////////////////////////////////////////////////////
void Personal::writeToFile(fstream& out) const {
  out.write(SSN,9);
  out.write(name,nameLen);
  out.write(city,cityLen);
  out.write(reinterpret_cast<const char*>(&year),sizeof(int));
  out.write(reinterpret_cast<const char*>(&salary),sizeof(long));
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void Personal::readFromFile(fstream& in)
//
//  Description: Reads all the stored data in from the database specified.
//
//  Preconditions: SSN, name, nameLen, city, cityLen, year, and salary must
//  all have values
//
//  Postconditions: SSN, name, nameLen, city, cityLen, year, and salary are
//  read in from the database and stored into their respective variables
//
///////////////////////////////////////////////////////////////////////////////
void Personal::readFromFile(fstream& in) {
  in.read(SSN,9);
  in.read(name,nameLen);
  in.read(city,cityLen);
  in.read(reinterpret_cast<char*>(&year),sizeof(int));
  in.read(reinterpret_cast<char*>(&salary),sizeof(long));
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void Personal::readKey()
//
//  Description: Reads in the SSN from the user
//
//  Preconditions: SSN must exist
//
//  Postconditions: a 9 digit value entered by the user is copied into SSN
//
///////////////////////////////////////////////////////////////////////////////
void Personal::readKey() {
  char s[80];
  cout << "Enter SSN: ";
  cin.getline(s,80);
  strncpy(SSN,s,9);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: ostream& Personal::writeLegibly(ostream& out)
//
//  Description: Outputs SSN, name, city, year, and salary to the screen,
//  labeled with their variable name and delimeted by commas
//
//  Preconditions: SSN, name, city, year, and salary must all have values
//
//  Postconditions: SSN, name, city, year, and salary are output to the screen
//
///////////////////////////////////////////////////////////////////////////////
ostream& Personal::writeLegibly(ostream& out) {
  SSN[9] = name[nameLen] = city[cityLen] = '\0';
  out << "SSN = " << SSN << ", name = " << name << ", city = " << city << ", year = " << year << ", salary = " << salary;
  return out;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: istream& Personal::readFromConsole(istream& in)
//
//  Description: Reads in values for SSN, name, city, year, and salary from
//  the command line as the user inputs them and stores them in their respective
//  variables.
//
//  Preconditions: SSN, name, nameLen, city, cityLen, year, and salary must exist.
//
//  Postconditions: SSN, name, nameLen, city, cityLen, year, and salary all have
//  values
//
///////////////////////////////////////////////////////////////////////////////
istream& Personal::readFromConsole(istream& in) {
    SSN[9] = name[nameLen] = city[cityLen] = '\0';
    char s[80];
    cout << "SSN: ";
    in.getline(s, 80);
    strncpy(SSN, s, 9);
    cout << "Name: ";
    in.getline(s, 80);
    strncpy(name, s, nameLen);
    cout << "City: ";
    in.getline(s, 80);
    strncpy(city, s, cityLen);
    cout << "Birth year: ";
    in >> year;
    cout << "Salary: ";
    in >> salary;
    in.ignore();
    return in;
}

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
//  Special Processing Requirements: A database file needs to be made before 
//  running the program.
//
///////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 1
//  Due: 09/04/2019
//
//  Description: The cpp file that deals with entering
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
//  Special Processing Requirements: A database file needs to be made before 
//  running the program. Needs to be compiled at the same time as 
//  personal.cpp and database.cpp
//
///////////////////////////////////////////////////////////////////////////////

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
//  Special Processing Requirements: A database file needs to be made before 
//  running the program.
//
///////////////////////////////////////////////////////////////////////////////

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
    friend ostream& operator<<(ostream& out, Database& db) {
	  return db.print(out);
	}
};

///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 1
//  Due: 09/04/2019
//
//  Description: The cpp file that brings all the other files together to make
//  a functioning database interface.  This writes and reads to/from the database
//  and accepts input that is used to determine what the program will do.  Also
//  handles finding and modifying data in a database.
//
//  Input:  The user inputs what mode they would like to use (Modify, Add, etc)
//  and the other input is from a database that should be created beforehand
//  by the user.
//
//  Output: Writes to the database file if something is added or modified
//  and outputs prompts to the screen to tell the user what to do.
//
//  Assumptions: None
//
//  Special Processing Requirements: A database file needs to be made before
//  running the program. Needs to be compiled at the same time as 
//  student.cpp and personal.cpp
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Function: Database<T>::Database() {}
//
//  Description: Creates an instance of Database
//
//  Preconditions: None
//
//  Postconditions: An instance of Database exists
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
Database<T>::Database() {}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void Database<T>::add(T& d)
//
//  Description: Writes new data to a specified database
//
//  Preconditions: A database must exist
//
//  Postconditions: The database now contains the new data
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void Database<T>::add(T& d) {
    database.open(fName, ios::in | ios::out | ios::binary);
    database.seekp(0, ios::end);
    d.writeToFile(database);
    database.close();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void Database<T>::modify(const T& d)
//
//  Description: Modifies a database entry
//
//  Preconditions: A database must exist
//
//  Postconditions: The specified entry d is overwritten by the data in tmp
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void Database<T>::modify(const T& d)
{
    T tmp;
    database.open(fName, ios::in | ios::out | ios::binary);
    while (!database.eof()) {
        tmp.readFromFile(database);
        if (tmp == d) {
            cin >> tmp;
            database.seekp(-d.size(), ios::cur);
            tmp.writeToFile(database);
            database.close();
            return;
        }
    }
    database.close();
    cout << "The record to be modified is not in the database\n";
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: bool Database<T>::find(const T& d)
//
//  Description: Used for determining whether or not something d is in the database.
//
//  Preconditions: A database must exist and data must be entered for d
//
//  Postconditions: Returns true if d was found in database and false otherwise
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
bool Database<T>::find(const T& d) {
    T tmp;
    database.open(fName, ios::in | ios::binary);
    while (!database.eof()) {
        tmp.readFromFile(database);
        if (tmp == d) {
            database.close();
            return true;
        }
    }
    database.close();
    return false;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: ostream& Database<T>::print(ostream& out)
//
//  Description: Outputs the data read from the database file using the format
//  defined in personal/student.cpp (delimeted by commas and labels)
//
//  Preconditions: Data must exist in the database file.
//
//  Postconditions: The data from the database file is output to the console 
//  neatly formatted with labels and commas
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
ostream& Database<T>::print(ostream& out) {
    T tmp;
    database.open(fName, ios::in | ios::binary);
    while (true) {
        tmp.readFromFile(database);
        if (database.eof())
            break;
        out << tmp << endl;
    }
    database.close();
    return out;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void Database<T>::run()
//
//  Description: The main menu for the program that has the user enter the
//  database file name, an option for modifying/adding/finding a record in the
//  database.
//
//  Preconditions: A database file must exist
//
//  Postconditions: The operation corresponding to the number the user inputs
//  will be run, and the program can be exit by entering the number 4.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void Database<T>::run() {
    cout << "File name: ";
    cin >> fName;
    char option[5];
    T rec;
    cout << "1. Add 2. Find 3. Modify a record 4. Exit\n";
    cout << "Enter an option: ";
    cin.getline(option, 4);
    while (cin.getline(option, 4)) {
        if (*option == '1') {
            cin >> rec;
            add(rec);
        }
        else if(*option == '2') {
            rec.readKey();
            cout << "The record is ";
            if (find(rec) == false)
                cout << "not ";
            cout << "in the database\n";
        }
        else if(*option == '3') {
            rec.readKey();
            modify(rec);
        }
        else if(*option != '4')
			cout << "Wrong option\n";
        else return;
        cout << *this;
        cout << "Enter an option: ";
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: int main()
//
//  Description: The main function
//
//  Preconditions: None
//
//  Postconditions: Runs The Personal database system if Personal is uncommented
//  and runs the Student database system if Student is uncommented
//
///////////////////////////////////////////////////////////////////////////////
int main() {
        Database<Personal>().run(); 
	// Database<Student>().run();
	return 0;
}
