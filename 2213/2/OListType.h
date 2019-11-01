#ifndef OLISTTYPE_H
#define OLISTTYPE_H
#include "ListType.h"
#include<iostream>

template <class T>
class OListType: public ListType<T> {
   public:
      OListType(size_t = 10);
      virtual bool insert (const T&);
      virtual bool erase (const T&);
      virtual bool find (const T&) const;
};

template <class T>
OListType<T>::OListType(size_t n): ListType<T>(n) {
}

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
   bool result = false;
   bool goodtogo = true;

   if (this -> full()) {
      try {
         T *temp = new T[2*this -> capacity];
	 this -> capacity = 2*this -> capacity;
	 for (size_t i = 0; i < this -> count; ++i) {
            temp[i] = this -> list[i];
	 }
	 delete[] this -> list;
	 this -> list = temp;
      }
      catch(std::bad_alloc) {
         goodtogo = false;
      }
   }
   if (goodtogo) {
      size_t j = this -> count;
      while((j > 0) && (item < this -> list[j-1])) {
         this -> list[j] = this -> list[j-1];
	 --j;
      }
      this -> list[j] = item;
      ++this -> count;
      result = true;
   }

   return result;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: bool OListType<T>::erase(const T& item)
//
//  Description: A function for erasing a single item from a list. This is done
//  by searching through the list for the item and erasing it if it is found.
//
//  Preconditions: An instance of OListType must exist.
//
//  Postconditions: If item is found in OListType, it will be erased.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
bool OListType<T>::erase(const T& item) {
   bool result = false;

   if (!this -> empty()) {
      size_t i = 0;
      while (i < this -> count && item != this -> list[i]) {
         ++i;
      }
   if (i < this -> count) {
      while (i < this -> count-1) {
         this -> list[i] = this -> list[i+1];
         ++i;
      }
      --this -> count;
      //this -> list[i] = this -> list[--this->count];
      result = true;
      }
   }
   return result;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: bool OListType<T>::find(const T& item) const
//
//  Description: A function for finding item in list.  This is done by starting
//  in the middle of the list and going up or down depending on whether the item
//  is greater than or less than the middle item.
//
//  Preconditions: An instance of OListType must exist.
//
//  Postconditions: If item is found in OListType, true will be returned.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
bool OListType<T>::find(const T& item) const {
   int i = 0, j = this -> count-1, mid;
   bool found = false;
   while ((i <= j) && !found) {
      mid = ((i + j)/2);
      if (item == this -> list[mid]) {
         found = true;
      } else {
         if (item < this -> list[mid]) j = mid-1;
	 else (i = mid+1);
      }
   }
   return found;
}

#endif
