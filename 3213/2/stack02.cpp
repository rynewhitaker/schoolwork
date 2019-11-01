///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 2 (b)
//  Due: 09/27/2019
//
//  Description: A program that reverses the items in stack S by using one 
//  additional stack and a queue.
//
//  Input: None
//
//  Output: The program outputs the sizes and top/front elements of the stack
//  and queue throughout the process of reversing.
//
//  Assumptions: None
//
//  Special Processing Requirements: None
//
///////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main() { 
  // one stack and one queue
  stack<int> S;
  queue<int> Q;
  
  // pushing integers 1-5 onto S
  for (int i = 1; i <= 5; i++) {
	S.push(i);  
  }
    
  int stackSize = S.size();
  
  // prints size of S and the top element from S
  cout << "S size:  " << stackSize << endl;
  cout << "S top:   " << S.top() << endl << endl;
  
  // pushes all the elements into Q and pops them off S
  for (int i = 0; i < stackSize; i++) {
    Q.push(S.top());
	S.pop();
  }
  
  // prints size of S and Q and the front element from Q
  cout << "S size:  " << S.size() << endl;
  cout << "Q size:  " << Q.size() << endl;
  cout << "Q front: " << Q.front() << endl << endl;
  
  // pushes all the elements onto S and pops them off Q
  for (int i = 0; i < stackSize; i++) {
    S.push(Q.front());
	Q.pop();
  }
  
  // prints final sizes of S and Q and the top element from S
  cout << "S size:  " << S.size() << endl;
  cout << "S top:   " << S.top() << endl;
  cout << "Q size:  " << Q.size() << endl;

  return 0;

}