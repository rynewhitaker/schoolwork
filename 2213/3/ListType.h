#ifndef LISTTYPE_H
#define LISTTYPE_H

#include "NodeType.h"
#include<iostream>
#include<cstddef>

template <class T>
class ListType {
   public:
      ListType();
      ListType(const ListType<T>&);
      virtual ~ListType();
      const ListType<T>& operator = (const ListType<T>&);
      virtual bool insert(const T&) = 0;
      virtual void eraseAll();
      bool erase(const T&);
      bool empty() const;
      bool find (const T&) const;
      size_t size() const;
   protected:
      NodeType<T>* head;
      size_t count;
   private:
      void destroy();
      void copy(const ListType<T>&);
      template <class U>
      friend std::ostream& operator << (std::ostream&, const  ListType<U>&);
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: ListType<T>::ListType()
//
//  Description:  An empty constructor for ListType that initializes head to
//  nullptr and count to 0. This means that there is nothing in the list.
//
//  Preconditions: None
//
//  Postconditions: A new instance of ListType with a head of nullptr and a
//  count of 0 will be created
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
ListType<T>::ListType() {
   head = nullptr;
   count = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: ListType<T>::ListType(const ListType<T>& src)
//
//  Description: A constructor for ListType that copies the list passed into it
//  into the new instance of ListType.  It duplicates whatever list is passed to
//  it.
//
//  Preconditions: An instance of ListType must exist.
//
//  Postconditions: A duplicate of the list passed into the constructor will exist.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
ListType<T>::ListType(const ListType<T>& src) {
   head = nullptr;
   copy(src);
   count = src.count;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: ListType<T>::~ListType()
//
//  Description: A destructor for the ListType class.
//
//  Preconditions: An instance of ListType must exist.
//
//  Postconditions: The instance of ListType no longer exists.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
ListType<T>::~ListType() {
   destroy();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: bool ListType<T>::empty()
//
//  Description: Checks whether or not a list is empty by comparing the number
//  of contents it contains to 0.
//
//  Preconditions: An instance of ListType must exist.
//
//  Postconditions: A boolean value is returned based on whether or not the list
//  that is passed into it is empty.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
bool ListType<T>::empty() const {
   return count == 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void ListType<T>::copy(const ListType<T>& src)
//
//  Description: A copy function that copies the list passed into it into a new
//  copy of the list.
//
//  Preconditions: An instance of ListType must exist.
//
//  Postconditions: The original list passed into the function remains unchanged
//  and a new copy of the list exists.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void ListType<T>::copy(const ListType<T>& src) {
   NodeType<T> *newNode, *current;

   if (head != nullptr) {
      destroy();
   }

   if (src.head == nullptr) {
      head = nullptr;
      count = 0;
   }
   else {
      current = src.head;
      count = src.count;
      head = new NodeType<T>;
      head -> info = current -> info;
      head -> link = nullptr;
      newNode = head;
      current = current -> link;
      while (current != nullptr) {
         newNode -> link = new NodeType<T>;
	     newNode = newNode -> link;
	     newNode -> info = current -> info;
	     newNode -> link = nullptr;
	     current = current -> link;
      }
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void ListType<T>::eraseAll()
//
//  Description: A function that erases all items in a List.
//
//  Preconditions: An instance of ListType must exist.
//
//  Postconditions: The original list now contains no items and has a count of 0.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void ListType<T>::eraseAll() {
   destroy();
   head = nullptr;
   count = 0;
   return;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: bool ListType<T>::erase(const T& item)
//
//  Description: A function for erasing a single item from a list.
//
//  Preconditions: An instance of ListType must exist.
//
//  Postconditions: If item is found in ListType, it will be erased.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
bool ListType<T>::erase(const T& item) {
   NodeType<T> *loc = head, *prev = nullptr;
   while (loc != nullptr && loc -> info != item) {
      prev = loc;
      loc = loc -> link;
   }
   if (loc != nullptr && loc -> info == item) {
      if (prev == nullptr) {
         head = head -> link;
	     delete loc;
      }
      else {
         prev -> link = loc -> link;
	     delete loc;
      }
      --count;
   }
   return true;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: bool ListType<T>::find(const T& item)
//
//  Description: A function that finds item in list by following pointers
//  through the list and comparing them to item and returns true if it is found.
//
//  Preconditions: An instance of ListType must exist.
//
//  Postconditions: A boolean value is returned based on whether or not a value
//  was found in the list.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
bool ListType<T>::find (const T& item)const {
   NodeType<T> *curr = head;
   while (curr!=nullptr && curr->info!= item){
       curr = curr->link;
   }
   return curr!=nullptr;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: size_t ListType<T>::size()
//
//  Description: A function that returns the number of elements in a list.
//
//  Preconditions: An instance of ListType must exist.
//
//  Postconditions: A size_t is returned with the number of items in the list.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
size_t ListType<T>::size() const {
   return count;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: void ListType<T>::destroy()
//
//  Description: Destroys a list by deleting each of the elements until it
//  reaches the nullptr.
//
//  Preconditions: An instance of ListType must exist.
//
//  Postconditions: The instance of ListType is empty and has a count of 0.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void ListType<T>::destroy() {
   NodeType<T>* temp;
   while(head != nullptr) {
      temp = head;
      head = head -> link;
      delete temp;
   }
count = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: std::ostream& operator << (std::ostream& out, const ListType<U>& list)
//
//  Description: Allows instances of ListType to be output to the screen with commas in-between
//  each of the elements.
//
//  Preconditions: An instance of ListType must exist.
//
//  Postconditions: The elements of the list will be output to the screen with ", "
//  separating them.
//
///////////////////////////////////////////////////////////////////////////////

template <class U>
std::ostream& operator << (std::ostream& out, const ListType<U>& list){
   if(list.count > 0){
       NodeType<U>* temp = list.head;
       out << temp -> info;
       temp = temp -> link;
       while (temp != nullptr) {
          out << ", " << temp -> info;
          temp = temp -> link;
       }
   }
   return out;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: const ListType<T>& ListType<T>::operator = (const ListType<T>& src)
//
//  Description: Overloads the = operator so that two instances of ListType can be
//  set equal by using the syntax: list1 = list2;
//
//  Preconditions: Two instances of ListType must exist.
//
//  Postconditions: The list on the left-hand side of the = is set equal to the list
//  on the right side of the = if they are not already equal.
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
const ListType<T>& ListType<T>::operator = (const ListType<T>& src){
   if (this!= &src){
       copy(src);
   }
   return *this;
}


#endif
