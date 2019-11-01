///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 2 (c)
//  Due: 09/27/2019
//
//  Description: A program that reverses the items in stack S by using one 
//  additional stack and one int.
//
//  Input: None
//
//  Output: The program prints the elements in stack S before and after
//  reversing, the sizes of the stacks, and the elements on the top of the
//  stacks throughout the process.
//
//  Assumptions: Assuming that swap() function is allowed.
//
//  Special Processing Requirements: None
//
///////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stack>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void populate(stack<int>& S) 
//
//  Description: The populate function simply populates a stack S with integers.
//  It is currently set to insert numbers 1-5 into S, but can be changed to insert
//  however many elements are desired.  It also prints the elements as well as 
//  'bottom' and 'top' to display the contents of S and indicate which side is
//  the top and which is the bottom.
//  indicate 
//
//  Preconditions: An empty stack must exist and be passed into the function
//
//  Postconditions: Integers 1-5 are inserted into S, and they are printed out
//  as they are inserted along with 'S bottom' and 'S top' to indicate which
//  side is which.
//
///////////////////////////////////////////////////////////////////////////////
void populate(stack<int>& S) {
  cout << "S bottom" << endl;
  for (int i = 1; i <= 5; i++) {
	cout << i << endl;
	S.push(i);  
  }
  cout << "S top" << endl << endl;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void reverse(int stackSize, stack<int>& a, stack<int>& b)
//
//  Description: The reverse function is the heart of this program.  This is
//  where the stack S is reversed.  This is done by swapping the contents of
//  stack a into stack b, creating an exact copy of stack 'a' in stack 'b' and 
//  emptying stack  'a'.  One by one, the elements of stack 'b' are popped off and
//  into an integer 'temp' where they are then pushed onto stack 'a'.  This 
//  reverses stack S.
//
//  Preconditions: Two stacks 'a' and 'b' must exist and be passed in.  Stack 'a'
//  must contain elements, and therefore stack 'a' must have a size stackSize
//  which is also passed in.
//
//  Postconditions: All the contents of stack 'a' are reversed.
//
///////////////////////////////////////////////////////////////////////////////
void reverse(int stackSize, stack<int>& a, stack<int>& b) {
  a.swap(b);
  for (int i = 0; i < stackSize; i++) {
    int temp = b.top();
	b.pop();
	a.push(temp);
  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void print(int stackSize, stack<int>& a)
//
//  Description: The print function prints out the elements of a stack as it
//  pops off the elements.  This should only be used at the end of the program
//  because it pops all the elements off, meaning that the stack will be empty
//  at the end of the function.
//
//  Preconditions: The size of the stack and the stack itself are passed into
//  the function.  The stack should have elements, and therefore a size.
//
//  Postconditions: The elements of the stack are printed to the console along
//  with 'S top' and 'S bottom' to indicate which side is which.
//
///////////////////////////////////////////////////////////////////////////////
void print(int stackSize, stack<int>& a) {
  cout << "S top" << endl;
  for (int i = 0; i < stackSize; i++) {
    cout << a.top() << endl;
    a.pop();	
  }
  cout << "S bottom" << endl;
}

int main() {
  stack<int> S, S1;
  
  populate(S);
  
  int stackSize = S.size();

  cout << "Before transfer: " << endl;
  cout << "S size     :  " << S.size() << endl; 
  cout << "S top item :  " << S.top() << endl; 
   
  reverse(stackSize, S, S1);
  
  cout << endl << "After transfer: " << endl;
  cout << "S size     :  " << S.size() << endl; 
  cout << "S top item :  " << S.top() << endl; 
  cout << "S1 size    :  " << S1.size() << endl << endl; 
  
  print(stackSize, S);
  
  return 0;
}