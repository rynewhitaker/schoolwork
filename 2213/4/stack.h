///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 4 - stack.h
//  Due: 04/18/2019
//
//  Description:
//  Contains the functions used to create a last in first out (LIFO) stack for
//  use in storing expressions (in this use case, but can really be anything)
//  as they are found and accessed.  This contains functions for adding items
//  deleting items, accessing the top without knowing which specific
//  item is at that location, and fetching the number of items on the
//  stack.
//
//  Input: None
//
//  Output: None
//
//  Assumptions: None
//
//////////////////////////////////////////////////////////////////////////////
#ifndef STACK__H
#define STACK__H

#include <vector>
#include <cstdlib>

template <class T>
class stack {
   public:
      stack(size_t = 10);
      stack(const stack<T>&);
      void push(const T&);
      void pop();
      size_t size() const;
      bool empty() const;
      const T& top() const;
   private:
      std::vector<T> items;
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: stack(size_t n)
//
//  Description: Makes a stack of size n
//
//  Preconditions: none
//
//  Postconditions: A new stack of size n exists
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
stack<T>::stack(size_t n) {
   items.reserve(n);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: stack(const stack<T>& source)
//
//  Description: Makes a copy of an existing source stack into a new copy of stack
//
//  Preconditions: An instance of stack must exist and a stack that wants to be copied over must exist
//
//  Postconditions: Two duplicate copies of stack exist
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
stack<T>::stack(const stack<T>& source) {
   items = source.items;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: push(const T& item)
//
//  Description: Pushes an item onto the stack
//
//  Preconditions: An instance of stack must exist
//
//  Postconditions: The new item is located at the back of the stack
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void stack<T>::push(const T& item) {
   items.push_back(item);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: pop()
//
//  Description: Removes an item from the stack by popping it off (deleting it)
//
//  Preconditions: An instance of stack must exist
//
//  Postconditions: Pops the back item on the stack off, aka the newest item
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void stack<T>::pop() {
   items.pop_back();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: size()
//
//  Description: Returns the size of the stack
//
//  Preconditions: An instance of stack must exist
//
//  Postconditions: The size_t of the stack is returned
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
size_t stack<T>::size() const {
   return items.size();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: empty()
//
//  Description: Determines whether or not the stack is empty
//
//  Preconditions: An instance of stack must exist
//
//  Postconditions: Returns a boolean based on whether or not the stack is empty
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
bool stack<T>::empty() const {
   return items.empty();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: top()
//
//  Description: Returns the top item in the stack by returning the back item or the newest item in the stack
//
//  Preconditions: An instance of stack must exist
//
//  Postconditions: The back item is returned
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
const T& stack<T>::top() const {
   return items.back();
}

#endif
