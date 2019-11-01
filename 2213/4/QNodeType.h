///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 4 - QNodeType.h
//  Due: 04/18/2019
//
//  Description:
//  Sets up the QNodeType struct with T item which is the item that is located
//  at front or back etc and with a pointer next which is the next item after
//  an item.
//
//  Input: None
//
//  Output: None
//
//  Assumptions: None
//
//////////////////////////////////////////////////////////////////////////////
#ifndef QNODETYPE__H
#define QNODETYPE__H

///////////////////////////////////////////////////////////////////////////////
//
//  Function:
//
//  Description:
//
//  Preconditions:
//
//  Postconditions:
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
struct QNodeType {
   T item;
   QNodeType<T>* next;
};

#endif
