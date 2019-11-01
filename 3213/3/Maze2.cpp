///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 3 (2)
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
  int numDirections(Cell);
  int detectChanges(Cell, Cell);
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
//  through the maze while pushing things onto the mazeStack.  Once it has done this,
//  it goes back through and pops everything off of the mazeStack while outputting it
//  to the screen so that the user can see what path was taken to solve the maze.
//
//  Preconditions: A maze must be input by the user
//
//  Postconditions: The maze will either be solved or not, and if it is, the path 
//  that was taken will be output to the screen.  Snapshots of the maze will also 
//  be output while it is being solved.
//
///////////////////////////////////////////////////////////////////////////////
void Maze::exitMaze() {
  int row, col;
  int changes = 10;
  currentCell = entryCell;
  Stack<Cell> pathStack, tmpStack;
  Cell tempCell, a, b;
  while (!(currentCell == exitCell)) {
	pathStack.push(currentCell);
	// store last cell with multiple possible paths in case we hit a dead end
	if(numDirections(currentCell) >= 2) {
		pathStack.push(Cell(-1,-1));
	}
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
	  cout << "Failure" << endl;
	  return;
	}
	else currentCell = mazeStack.pop();
  }
  pathStack.push(exitCell);
  cout << *this;
  cout << "Success" << endl;

  a = pathStack.pop();
  tmpStack.push(a);
  b = pathStack.pop();	
  changes = detectChanges(a, b);
  while(!(pathStack.empty())) {
	changes = detectChanges(a, b);
	while (changes != 1) {
	  b = pathStack.pop();
	  changes = detectChanges(a, b);
	}
	if (b.x != -1 && b.y != -1 && changes == 1) {
		tmpStack.push(b);
	}
	a = b;
	if (pathStack.size() > 0) { b = pathStack.pop(); }
  }

  cout << "Path from exit to mouse: ";
  while (!(tmpStack.empty())) {
	tempCell = tmpStack.pop();
	pathStack.push(tempCell);
  }
  while (!(pathStack.empty())) {
	  tempCell = pathStack.pop();
	  cout << "[" << tempCell.x << " " << tempCell.y << "] ";
  }
  cout << endl;

}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: int Maze::detectChanges(Cell a, Cell b)
//
//  Description: This function detects how many x and y changes there are between
//  two cells.  This is done because if the x and y coordinates both change
//  between the two cells, the cells are therefore not next to each other.  This
//  indicates a detour, which is to be left out of the end path.
//
//  Preconditions: Two cells must be passed into the function.
//
//  Postconditions: An integer is returned indicating how many changes there are
//  between the two cells.  If one of the cells is a numDirections flag (-1, -1)
//  -1 is returned so the program will pop it off.
//
///////////////////////////////////////////////////////////////////////////////
int Maze::detectChanges(Cell a, Cell b) {
	int changes = 0;
	if (a.x != -1 && a.y != -1 && b.x != -1 && b.y != -1) {
	  if (a.x > b.x) { changes = changes + (a.x - b.x); }
	  if (a.x < b.x) { changes = changes + (b.x - a.x); }
	  if (a.y > b.y) { changes = changes + (a.y - b.y); }
	  if (a.y < b.y) { changes = changes + (b.y - a.y); }
	} else { changes = -1; }
	return changes;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: int Maze::numDirections(Cell current)
//
//  Description: This function counts how many open passages there are surrounding
//  a cell.  If there are multiple paths that can be taken, a flag (-1, -1) is
//  pushed onto the stack so that if the program runs into a dead end, it can
//  backtrack to the last cell that had multiple paths that could be taken.
//
//  Preconditions: A cell needs to be passed in
//
//  Postconditions: The number of possible paths around a cell is returned.
//
///////////////////////////////////////////////////////////////////////////////
int Maze::numDirections(Cell current) {
	int directions = 0;
 	int row = current.x;
	int col = current.y;
	if(store[row-1][col] == passage) {directions++;}
	if(store[row+1][col] == passage) {directions++;}
	if(store[row][col-1] == passage) {directions++;}
	if(store[row][col+1] == passage) {directions++;}
	return directions;
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
