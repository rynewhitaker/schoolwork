///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program #5 (BTNodeType.h)
//  Due: 05/01/2019
//
//  Description:
//  Defines the BTNodeType struct which creates the pointers used for traversing
//  the BSTType list.  It also declares 'item' which is the current node.
//
//  Input: None
//
//  Output: None
//
//  Assumptions: None
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BTNODETYPE__H
#define BTNODETYPE__H

template <class T>
struct BTNodeType {
   T item;
   BTNodeType<T> *left, *right;
};

#endif // BTNODETYPE__H
