#ifndef LISTTYPE_H
#define LISTTYPE_H
#include<iostream>

template <class T>
class ListType {
   public:
      ListType(size_t = 10);
      ListType(const ListType<T>&);
      virtual ~ListType();
      const ListType<T>& operator = (const ListType<T>&);
      virtual bool insert (const T&) = 0;
      virtual void eraseAll();
      virtual bool erase(const T&) = 0;
      virtual bool find(const T&) const = 0;
      size_t size() const;
      bool empty() const;
      bool full() const;
      template <class U>
      friend std::ostream& operator << (std::ostream&, const ListType<U>&);
   protected:
      T *list;
      size_t capacity;
      size_t count;
   private:
      void copy(const ListType<T>&);
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: ListType(size_t n) 
//
//  Description: Constructs a new instance of class ListType with an initial
//  size of n.  The count is set to 0 because it is initially empty.
//
//  Preconditions: size_t n must be passed into the constructor.
//
//  Postconditions: n is unchanged and the constructor does not return any
//  value.  A new instance of ListType with size n is created.  
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
ListType<T>::ListType(size_t n) {
   capacity = n;
   count = 0;
   list = new T[capacity];
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: ListType(const ListType<T>& src)
//
//  Description: Makes a new instance of ListType with the same contents as
//  ListType src.  
//
//  Preconditions: An instance of ListType should already exist and be passed
//  into the constructor.  This will be referred to as src in this constructor.
//
//  Postconditions: A new instance of ListType will exist with the same 
//  contents as what was passed into the constructor.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
ListType<T>::ListType(const ListType<T>& src) {
   copy(src);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: ~ListType()
//
//  Description: A destructor for the ListType class.
//
//  Preconditions: An instance of ListType that needs to be deleted must exist.
//
//  Postconditions: The ListType instance that had the destructor called on it
//  will no longer exist.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
ListType<T>::~ListType(){
   delete [] list;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: = operator 
//
//  Description: Replaces a list with another one by comparing the two to
//  see if they are the same or not.
//
//  Preconditions: Two instances of ListType must be used.
//
//  Postconditions: The two instances of ListType will remain the same if they
//  are both the same.  Otherwise, the list on the left-hand side will be
//  erased and replaced with the contents of the list on the righ-hand side.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
const ListType<T>& ListType<T>::operator=(const ListType<T>& src){
   if (this!=&src) {
      delete [] list;
      copy(src);
   }
   return *this;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: eraseAll()
//
//  Description: A function that erases all of the items in a list by setting
//  the count of items in the list to 0.
//
//  Preconditions: An instance of ListType that needs to have all of its items
//  erased must exist and have this member function called on it.
//
//  Postconditions: The instance of ListType that had this member function 
//  called on it will be "empty"
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void ListType<T>::eraseAll() {
   count = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: size()
//
//  Description: Returns the number of items in a list.
//
//  Preconditions: An instance of ListType must exist.
//
//  Postconditions: An integer count of the number of items in a list will be
//  returned.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
size_t ListType<T>::size() const {
   return count;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: empty()
//
//  Description: Determines whether or not a list is empty by comparing the
//  count of items in the list to 0.
//
//  Preconditions: An instance of ListType must exist.
//
//  Postconditions: A boolean value of true will be returned if the list is
//  empty and a boolean value of false will be returned if there are items in
//  the list.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
bool ListType<T>::empty() const{
   return count == 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: full()
//
//  Description: Determines whether or not a list is full by comparing the
//  current count of items in the list with the capacity of the list.
//
//  Preconditions: An instance of ListType must exist.
//
//  Postconditions: Returns a boolean value true if the list is full and a 
//  boolean value false if the list is not full.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
bool ListType<T>::full() const {
   return count == capacity;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: copy(const ListType<T>& src)
//
//  Description: Copies the list passed in to a new list.
//
//  Preconditions: An instance of ListType must exist.
//
//  Postconditions: A new instance of ListType will exist with the same
//  contents as the list passed into the function.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void ListType<T>::copy(const ListType<T>& src) {
   capacity = src.capacity;
   count = src.count;
   list = new T[capacity];
   for (size_t i = 0; i < count; ++i) {
      list[i] = src.list[i];
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: '<<' Operator 
//
//  Description: Outputs the contents of a non-empty list delimited with ", "
//
//  Preconditions: An instance of ListType must exist and an instance of 
//  ostream must exist.
//
//  Postconditions: The contents of the list will be output with ", " 
//  in-between unless there are no items in the list.
//
///////////////////////////////////////////////////////////////////////////////
template<class U>
std::ostream& operator << (std::ostream& out, const ListType<U>& src) {
   if (!src.empty()) {
      out << src.list[0];
      for (size_t i = 1; i < src.count; ++i) {
         out << ", " << src.list[i];
      }
   }
   return out;
}

#endif

