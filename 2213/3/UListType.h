#ifndef ULISTTYPE_H
#define ULISTTYPE_H

#include "ListType.h"

template <class T>
class UListType:public ListType<T> {
   public:
      bool insert(const T&);
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: bool UListType<T>::insert(const T& item)
//
//  Description: Inserts item into UList by inserting it at the beginning of
//  the list.
//
//  Preconditions: An instance of UListType must exist.
//
//  Postconditions: item is inserted into the list by inserting it at the beginning
//  and returning true if the insert was successful and false if it failed.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
bool UListType<T>::insert(const T& item) {
   NodeType<T> *temp;
   try {
      temp = new NodeType<T>;
   }
   catch (std::bad_alloc be) {
      return false;
   }
   temp -> info = item;
   temp -> link = this -> head;
   this -> head = temp;
   ++this -> count;
   return true;
}

#endif
