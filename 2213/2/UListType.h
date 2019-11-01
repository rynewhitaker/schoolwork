#ifndef ULISTTYPE_H
#define ULISTTYPE_H
#include "ListType.h"
#include<iostream>

template <class T>
class UListType: public ListType<T> {
   public:
      UListType(size_t = 10);
      virtual bool insert (const T&);
      virtual bool erase (const T&);
      virtual bool find (const T&) const;
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: bool UListType<T>::insert(const T& item)
//
//  Description: Inserts item into UList by inserting the item at the end of
//  the list.
//
//  Preconditions: An instance of UListType must exist.
//
//  Postconditions: item is inserted into the list at the end and count is
//  incremented by one.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
bool UListType<T>::insert(const T& item) {
   bool result = false;
   bool goodtogo = true;

   if (this -> full()) {
      try {
         T *temp = new T[2 * this -> capacity];
	 this -> capacity = 2 * this -> capacity;
	 for (size_t i = 0; i < this -> count; ++i) {
            temp[i] = this -> list[i];
	 }
	 delete [] this -> list;
	 this -> list = temp;
      }
      catch (std::bad_alloc) {
         goodtogo = false;
      }
   }
   if (goodtogo) {
      this -> list[this -> count++] = item;
      result = true;
   }
   return result;
}

template <class T>
UListType<T>::UListType(size_t n): ListType<T>(n) {
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: bool UListType<T>::erase(const T& item)
//
//  Description: A function for erasing a single item from a list. This is done
//  by searching through the list for the item and erasing it if it is found.
//
//  Preconditions: An instance of UListType must exist.
//
//  Postconditions: If item is found in UListType, it will be erased.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
bool UListType<T>::erase(const T& item) {
   bool result = false;

   if (!this -> empty()) {
      size_t i = 0;
      while (i < this -> count && item != this -> list[i]) {
         ++i;
      }
      if (i < this -> count) {
         this -> list[i] = this -> list[--this -> count];
	 result = true;
      }
   }
   return result;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: bool UListType<T>::find(const T& item) const
//
//  Description: A function that finds item in list by following pointers
//  through the list and comparing them to item and returns true if it is found.
//
//  Preconditions: An instance of UListType must exist.
//
//  Postconditions: A boolean value is returned based on whether or not a value
//  was found in the list.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
bool UListType<T>::find(const T& item) const {
   size_t i = 0;
   while (i < this -> count && item != this -> list[i]) {
      ++i;
   }
   return (i < this -> count);
}

#endif
