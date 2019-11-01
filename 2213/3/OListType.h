#ifndef OLISTTYPE_H
#define OLISTTYPE_H

#include "ListType.h"

template <class T>
class OListType:public ListType<T> {
   public:
      bool insert(const T&);
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: bool OListType<T>::insert(const T& item)
//
//  Description: Inserts item into OList by comparing it to the other items
//  in the list then placing it in its correct spot.
//
//  Preconditions: An instance of OListType must exist.
//
//  Postconditions: item is inserted into the list such that the item before it
//  is less than it and the item after it is greater than it.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
bool OListType<T>::insert(const T& item) {
    NodeType<T> *loc = this -> head, *prev = nullptr, *temp = new NodeType<T>;
    temp -> info = item;

    while (loc != nullptr && loc -> info < item) {
        prev = loc;
        loc = loc -> link;
    }
    if (prev == nullptr) {
        temp -> link = this -> head;
        this -> head = temp;
    }
    else {
        temp -> link = loc;
        prev -> link = temp;
    }
    ++this -> count;
    return true;
}

#endif


