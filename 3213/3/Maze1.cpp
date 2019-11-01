///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 3 (1)
//  Due: 10/27/2019
//
//  Description: A program that allows the user to create a maze line by line,
//  then have it solved by the program.
//
//  Input: The user should draw a maze line by line using the characters listed
//  in the beginning prompt
//
//  Output: The program will solve the maze and output the steps that it took to
//  get to the end.
//
//  Assumptions: None
//
//  Special Processing Requirements: None
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
//  Function: class Stack : public stack<T>
//
//  Description: Creates the Stack class which inherits from the STL stack
//
//  Preconditions: None
//
//  Postconditions: None
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
class Stack : public stack<T> {
public:
  T pop() {
    T tmp = stack<T>::top();
	stack<T>::pop();
	return tmp;
  }
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: class Cell
//
//  Description: Creates the Cell class which is used throughout the program
//  to refer to a single spot or "cell" in the maze: whether it be entryCell, 
//  exitCell, etc.
//
//  Preconditions: None
//
//  Postconditions: None
//
///////////////////////////////////////////////////////////////////////////////
class Cell {
public:
  Cell(int i = 0, int j = 0) {
    x = i;
	y = j;
  }
  bool operator == (const Cell& c) const {
    return x == c.x && y == c.y;
  }
private:
  int x, y;
  friend class Maze;
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: class Maze
//
//  Description: Creates the Maze class which is used to create everything that 
//  relates to the maze that is entered and traversed.  It declares the maze cell 
//  references and main functions that will be used with the maze.
//
//  Preconditions: None
//
//  Postconditions: None
//
///////////////////////////////////////////////////////////////////////////////
class Maze {
public:
  Maze();
  void exitMaze();
private:
  Cell currentCell, exitCell, entryCell;
  const char exitMarker, entryMarker, visited, passage, wall;
  Stack<Cell> mazeStack;
  char **store;
  void pushUnvisited(int,int);
  friend ostream& operator << (ostream&, const Maze&);
  int rows, cols;
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: Maze::Maze() : exitMarker('e'), entryMarker('m'), visited('.'), 
//  passage('0'), wall('1')
//
//  Description: This function accepts input from the user and builds the maze 
//  based on what is input.  It also creates a border around the maze the user 
//  inputs.
//
//  Preconditions: The Stack, Cell, and Maze classes must be created.
//
//  Postconditions: A maze is created from the info that the user inputs, but 
//  the finished maze is not output to the screen.
//
///////////////////////////////////////////////////////////////////////////////
Maze::Maze() : exitMarker('e'), entryMarker('m'), visited('.'), passage('0'), wall('1') {
  Stack<char*> mazeRows;
  char str[80], *s;
  int col, row = 0;
  cout << "Enter a rectangular maze using the following " 
    << "characters: \nm = entry\ne - exit\n1 - wall\n0 - passage\n" 
    << "Enter one line at a time; end with Ctrl-z:\n";
  while (cin >> str) {
    row++;
	cols = strlen(str);
	s = new char[cols+3];
	mazeRows.push(s);
	strcpy(s+1, str);
	s[0] = s[cols+1] = wall;
	s[cols+2] = '\0';
	if (strchr(s, exitMarker) != 0) {
	  exitCell.x = row;
	  exitCell.y = strchr(s, exitMarker) - s;
	}
	if (strchr(s, entryMarker) != 0) {
	  entryCell.x = row;
	  entryCell.y = strchr(s, entryMarker) - s;
	}
  }
  rows = row;
  store = new char*[rows+2];
  store[0] = new char[cols+3];
  for ( ; !mazeRows.empty(); row--) {
    store[row] = mazeRows.pop();
  }
  store[rows+1] = new char[cols+3];
  store[0][cols+2] = store[rows+1][cols+2] = '\0';
  for (col = 0; col <= cols+1; col++) {
    store[0][col] = wall;
	store[rows+1][col] = wall;
  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void Maze::pushUnvisited(int row, int col)
//
//  Description: This function pushes every cell that is visited onto a mazeStack
//  so that the program knows which cells have been visited.
//
//  Preconditions: A cell is not in mazeStack
//
//  Postconditions: A cell is in mazeStack
//
///////////////////////////////////////////////////////////////////////////////
void Maze::pushUnvisited(int row, int col) {
  if (store[row][col] == passage || store[row][col] == exitMarker) {
    mazeStack.push(Cell(row, col));
  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void Maze::exitMaze()
//
//  Description: The heart of the program.  This runs through the maze and solves it.
//  This is done by comparing the current cell with the entry and exit cells and navigating
//  through the maze while pushing things onto the mazeStack.  If the program was able
//  to solve the maze, it will ouput success at the end.  Otherwise, it will output 
//  failure.
//
//  Preconditions: A maze must be input by the user
//
//  Postconditions: The maze will either be solved or not and the success or failure 
//  of the solving will be output to the screen. Snapshots of the maze will also 
//  be output while it is being solved.
//
///////////////////////////////////////////////////////////////////////////////
void Maze::exitMaze() {
  int row, col;
  currentCell = entryCell;
  while (!(currentCell == exitCell)) {
    row = currentCell.x;
	col = currentCell.y;
	cout << *this;
	if (!(currentCell == entryCell)) {
	  store[row][col] = visited;
	}
	pushUnvisited(row-1, col);
	pushUnvisited(row+1, col);
	pushUnvisited(row, col-1);
	pushUnvisited(row, col+1);
	if (mazeStack.empty()) {
	  cout << *this;
	  cout << "Failure\n";
	  return;
	}
	else currentCell = mazeStack.pop();
  }
  cout << *this;
  cout << "Success\n";
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: ostream& operator << (ostream& out, const Maze& maze)
//
//  Description: This overloads the output operator so that when a Maze is output, 
//  it will output the contents of the maze row by row
//
//  Preconditions: A maze and output stream must be passed
//
//  Postconditions: The Maze is output row by row.
//
///////////////////////////////////////////////////////////////////////////////
ostream& operator << (ostream& out, const Maze& maze) {
  for (int row = 0; row <= maze.rows+1; row++) {
    out << maze.store[row] << endl;
  }
  out << endl;
  return out;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: int main()
//
//  Description: This runs the whole program.
//
//  Preconditions: None
//
//  Postconditions: Outputs from the Maze functions are output to the screen
//
///////////////////////////////////////////////////////////////////////////////
int main() {
  Maze().exitMaze();
  return 0;
}
