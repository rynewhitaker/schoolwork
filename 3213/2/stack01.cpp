///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 2 (a)
//  Due: 09/27/2019
//
//  Description: A program that reverses the items in stack S by using two 
//  additional stacks.
//
//  Input: None
//
//  Output: The program outputs the sizes and top elements of the stacks
//  throughout the process of reversing as well as dividers to distinquish
//  between different parts of the transfer process.
//
//  Assumptions: None
//
//  Special Processing Requirements: None
//
///////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stack>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void transfer(int num, stack<int>& a, stack<int>& b)
//
//  Description: The meat of the program.  The transfer function transfers the 
//  contents of one stack 'a' to another stack 'b'.  This is used to transfer
//  S to S1, S1 to S2, and S2 to S.  This results in a reversed stack S.
//
//  Preconditions: Two stacks 'a' and 'b' must exist, and 'a' must contain
//  items.  An int must also be passed in to indicate which transfer is taking
//  place.  This is just for improved readability, it has no effect on the
//  actual transfer process.
//
//  Postconditions: The contents of 'a' will be reversed into 'b' and 'a' will
//  no longer contain anything.
//
///////////////////////////////////////////////////////////////////////////////
void transfer(int num, stack<int>& a, stack<int>& b) {
  int stackSize = a.size();
  cout << endl << "Transfer #" << num << endl;
  for(int i=0; i < stackSize; i++) {
	  b.push(a.top());
	  if(i != stackSize) {
	    a.pop();
	  }
  }
}

int main() { 
  stack<int> S, S1, S2;
  
  // pushes integers 1-5 onto S
  for (int i = 1; i <= 5; i++) {
	S.push(i);  
  }
    
  cout << "S size:  " << S.size() << endl;
  cout << "S Top:   " << S.top() << endl;

  transfer(1, S, S1);
  
  cout << "S size:  " << S.size() << endl;
  cout << "S1 size: " << S1.size() << endl;
  cout << "S1 Top:  " << S1.top() << endl;


  transfer(2, S1, S2);
  
  cout << "S size:  " << S.size() << endl;
  cout << "S1 size: " << S1.size() << endl;
  cout << "S2 size: " << S2.size() << endl;
  cout << "S2 Top:  " << S2.top() << endl;

  
  transfer(3, S2, S);
  
  cout << "S size:  " << S.size() << endl;
  cout << "S1 size: " << S1.size() << endl;
  cout << "S2 size: " << S2.size() << endl;
  cout << "S Top:   " << S.top() << endl;

  return 0;

}