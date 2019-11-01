///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program 4 - queue.h
//  Due: 04/18/2019
//
//  Description:
//  Contains the functions used to create a first in first out (FIFO) queue for
//  use in storing expressions (in this use case, but can really be anything)
//  as they are found and accessed.  This contains functions for adding items
//  deleting items, accessing the front or back without knowing which specific
//  item is at which specific location, and fetching the number of items on the
//  queue.
//
//  Input: None
//
//  Output: None
//
//  Assumptions: None
//
//////////////////////////////////////////////////////////////////////////////
#ifndef QUEUE__H
#define QUEUE__H

#include "QNodeType.h"
#include <cstdlib>

template <class T>
class queue {
   public:
      queue();
      queue(const queue<T>&);
      virtual ~queue();
      const queue<T>& operator=(const queue<T>&);
      void push(const T&);
      void pop();
      const T& front() const;
      const T& back() const;
      size_t size() const;
      bool empty() const;
   private:
      QNodeType<T> *front_, *back_;
      size_t count;
      void destroy();
      void copy(const queue<T>&);
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: queue()
//
//  Description: An empty constructor for a queue.  Sets the front and back both
//  to nullptr because there are no items in the queue.  Sets count to zero because
//  there are no items.
//
//  Preconditions: None
//
//  Postconditions: An instance of queue exists with count 0 and two pointers.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
queue<T>::queue() {
   front_ = back_ = nullptr;
   count = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: front()
//
//  Description: A pointer that points to the front of the queue
//
//  Preconditions: An instance of queue must exist
//
//  Postconditions: Returns the pointer to the front of the queue
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
const T& queue<T>::front() const {
    return front_ -> item;

}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: back()
//
//  Description: A pointer that points to the back of the queue
//
//  Preconditions: An instance of queue must exist
//
//  Postconditions: Returns the pointer to the back of the queue
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
const T& queue<T>::back() const {
      return back_ -> item;

}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: size()
//
//  Description: Returns the current size of the queue
//
//  Preconditions: An instance of queue must exist
//
//  Postconditions: Returns the current size of the queue (count)
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
size_t queue<T>::size() const {
   return count;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: ~queue()
//
//  Description: A destructor for queue
//
//  Preconditions: An instance of queue must exist
//
//  Postconditions: An instance of queue is destroyed
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
queue<T>::~queue() {
   destroy();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: queue(const queue<T>& source)
//
//  Description: A constructor for queue that makes a new queue that is a copy
//  of an existing queue.
//
//  Preconditions: An instance of queue must exist and another instance of queue
//  must be passed in to be copied
//
//  Postconditions: Two duplicate instances of queue exist
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
queue<T>::queue(const queue<T>& source) {
   copy(source);
   count = source.count;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: queue<T>::operator=(const queue<T>& source)
//
//  Description: Sets two queues equal to each other.  If the current queue
//  doesn't equal the queue passed, the current one will be destroyed and the
//  source queue will be copied in
//
//  Preconditions: An instance of queue must exist and another instance of queue
//  must be passed in to be copied
//
//  Postconditions: Two duplicate instances of queue exist
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
const queue<T>& queue<T>::operator=(const queue<T>& source) {
   if (this != &source) {
      destroy();
      copy(source);
   }
   return *this;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: push(const T& item)
//
//  Description: Pushes a new item onto the queue by moving existing items in the
//  queue to make room for the new item
//
//  Preconditions: An instance of queue must exist
//
//  Postconditions: the item will be pushed to the back of the queue
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void queue<T>::push(const T& item) {
   if (front_ == nullptr) {
      front_ = new QNodeType<T>;
      front_ -> item = item;
      front_ -> next = nullptr;
      back_ = front_;
   }
   else {
      back_ -> next = new QNodeType<T>;
      back_ = back_ -> next;
      back_ -> item = item;
   }
   ++count;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: pop()
//
//  Description: Pops an item off of the queue.  If the queue isn't empty, it pops the
//  front item off, deleting it and moving all other items up in the queue.
//
//  Preconditions:
//
//  Postconditions:
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void queue<T>::pop() {
   if (!empty()) {
      QNodeType<T>* temp = front_;
      front_ = front_ -> next;
      delete temp;
      if (front_ == nullptr) {
         back_ = nullptr;
      }
      --count;
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: empty()
//
//  Description: Checks to see if queue is empty
//
//  Preconditions: An instance of queue must exist
//
//  Postconditions: A boolean will be returned based on whether the queue is empty or not
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
bool queue<T>::empty() const {
   return (front_ == nullptr);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: destroy()
//
//  Description: Destroys a queue by popping each item off the queue until the queue is empty
//
//  Preconditions: An instance of queue must exist
//
//  Postconditions: Queue will be empty
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void queue<T>::destroy() {
   while(!empty()) {
      pop();
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: copy(const queue<T>& source)
//
//  Description: Copies a queue from one queue to another queue.
//
//  Preconditions: An instance of queue must exist
//
//  Postconditions: Two identical copies of queue exist
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void queue<T>::copy(const queue<T>& source) {
   QNodeType<T>* temp = source.front_;
   front_ = back_ = nullptr;
   if (temp != nullptr) {
      front_ = new QNodeType<T>;
      front_ -> item = temp -> item;
      front_ -> next = nullptr;
      back_ = front_;
      temp = temp -> next;
      while (temp != nullptr) {
         back_ -> next = new QNodeType<T>;
         back_ = back_ -> next;
         back_ -> item = temp -> item;
         temp = temp -> next;
      }
      back_ -> next = nullptr;
   }
   else {
      front_ = back_ = nullptr;
   }
   count = source.count;
}
#endif
