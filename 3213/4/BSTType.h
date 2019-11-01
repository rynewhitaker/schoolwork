///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program #4 (BSTType.h)
//  Due: 11/01/2019
//
//  Description:
//  Header file that defines the BSTType class that provides the functions
//  and declarations necessary for doing everything that regards a binary
//  search tree.  This includes inserting, deleting, traversing, and checking
//  size.
//
//  Input: None
//
//  Output: None - just includes the functions.
//
//  Assumptions: None
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BSTTYPE__H
#define BSTTYPE__H

#include "BTNodeType.h"
#include <iostream>

enum TravType {PRE, POST, IN};

template <class T>
class BSTType {
   public:
      BSTType();
      BSTType(const BSTType<T>&);
      const BSTType<T>& operator = (const BSTType<T>&);
      virtual ~BSTType();
      bool empty() const;
      void erase(const T&);
      bool find(const T&) const;
      void insert(const T&);
      size_t size() const;
      void traverse(std::ostream&, TravType) const;
   protected:
      BTNodeType<T> *root;
      size_t count;
   private:
      void copy(BTNodeType<T>*& node, BTNodeType<T>* source);
      void destroy(BTNodeType<T>*& node);
      void erase(const T& item, BTNodeType<T>*&node);
      bool find(const T& item, BTNodeType<T>* node) const;
      void inorder(std::ostream& out, BTNodeType<T>* node) const;
      void insert(const T& item, BTNodeType<T>*& node);
      void postorder(std::ostream& out, BTNodeType<T>* node) const;
      const T& predecessor(BTNodeType<T>* node);
      void preorder(std::ostream& out, BTNodeType<T>* node) const;
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: BSTType()
//
//  Description: Default constructor for BSTType
//
//  Preconditions: None
//
//  Postconditions: root will be null and the count of number of items in the tree
//  will be 0.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
BSTType<T>::BSTType() {
   root = nullptr;
   count = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: BSTType(const BSTType<T>& source)
//
//  Description: Constructor for BSTType that copies an existing BSTType into
//  the new BSTType
//
//  Preconditions: An instance of BSTType must exist
//
//  Postconditions: A new instance of BSTType exists which is the same as the
//  original instance of BSTType.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
BSTType<T>::BSTType(const BSTType<T>& source) {
   copy(root, source.root);
   count = source.count;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: BSTType<T>::operator=(const BSTType<T>& source
//
//  Description: Assignment operator for assigning an existing BSTType to
//  another instance of BSTType.
//
//  Preconditions: Two instances of BSTType must exist.
//
//  Postconditions: Both instances of BSTType contain the same things and are
//  exact duplicates apart from their names.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
const BSTType<T>& BSTType<T>::operator=(const BSTType<T>& source) {
   if (this != &source) {
      destroy(root);
      count = source.count;
      copy(root, source.root);
   }
   return *this;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: ~BSTType()
//
//  Description: Destructor for an instance of BSTType.
//
//  Preconditions: An instance of BSTType must exist.
//
//  Postconditions: The instance of BSTType does not exist anymore.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
BSTType<T>::~BSTType() {
   destroy(root);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: empty()
//
//  Description: Checks if BSTType is empty by checking if the pointer is a nullptr.
//
//  Preconditions: An instance of BSTType must exist.
//
//  Postconditions: A boolean value of true is returned if BSTType is empty
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
bool BSTType<T>::empty() const {
   return root == nullptr;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: erase(const T& item)
//
//  Description: Erases an item from the binary search tree.
//
//  Preconditions: An instance of BSTType must exist with items in it.
//
//  Postconditions: The item specified will be removed from the tree.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void BSTType<T>::erase(const T& item) {
   erase(item, root);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: find(const T& item)
//
//  Description: Finds a specified item in BSTType by checking if it is in the
//  root node, and going through the rest of the list to try to find it if else.
//
//  Preconditions: An instance of BSTType must exist
//
//  Postconditions: Determines whether or not an item is in BSTType by traversing
//  through the list beginning with the root node.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
bool BSTType<T>::find(const T& item) const {
   return find(item, root);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: insert(const T& item)
//
//  Description: Inserts an item into the binary tree by inserting the item
//  at the location of root.
//
//  Preconditions: An instance of BSTType must exist.
//
//  Postconditions: item is inserted into BSTType at location root
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void BSTType<T>::insert(const T& item) {
   insert(item, root);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: size()
//
//  Description: Returns the number of items in BSTType
//
//  Preconditions: An instance of BSTType must exist
//
//  Postconditions: size_t is returned as the number of items in the tree
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
size_t BSTType<T>::size() const {
   return count;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: traverse(std::ostream& out, TravType traverse)
//
//  Description: Outputs the tree in preorder, postorder, or in order depending
//  on what is requested.  Calls preorder, postorder, or inorder depending on which
//  is requested.
//
//  Preconditions: An instance of BSTType must exist
//
//  Postconditions: preorder, inorder, or postorder is called to print the tree
//  depending on which is called in main.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void BSTType<T>::traverse(std::ostream& out, TravType traverse) const {
   switch (traverse) {
      case PRE: preorder(out, root);
                break;
      case IN:  inorder(out, root);
                break;
      case POST:postorder(out, root);
                break;
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: copy(BTNodeType<T>*& node, BTNodeType<T>* source)
//
//  Description: Copies an instance of BSTType into another instance of BSTType
//  by assigning each item to its corresponding location on the other BSTType.
//
//  Preconditions: One instance of BSTType must exist.
//
//  Postconditions: Two identical instances of BSTType exist (aside from their names)
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void BSTType<T>::copy(BTNodeType<T>*& node, BTNodeType<T>* source) {
   if (source != nullptr) {
      node = new BTNodeType<T>;
      node -> item = source -> item;
      copy(node -> left, source -> left);
      copy(node -> right, source -> right);
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: destroy(BTNodeType<T>*& node)
//
//  Description: Destroys a node in the binary tree by deleting anything to the
//  left or right of the node and then deleting the node itself.
//
//  Preconditions: An instance of BSTType must exist
//
//  Postconditions: The designated node in the binary tree and its children are
//  deleted.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void BSTType<T>::destroy(BTNodeType<T>*& node) {
   if (node != nullptr) {
      destroy(node -> left);
      destroy(node -> right);
      delete node;
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: erase(const T& item, BTNodeType<T>*& node)
//
//  Description: Erases an item from the binary tree and decrements the count
//
//  Preconditions: An instance of BSTType must exist
//
//  Postconditions: The designated node is removed from the tree
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void BSTType<T>::erase(const T& item, BTNodeType<T>*& node) {
   if (node != nullptr) {
      if (item == node -> item) {
         if (node -> right == nullptr) {
            BTNodeType<T>* temp = node;
            node = node -> left;
            delete temp;
            --count;
          }
          else if (node -> left == nullptr) {
             BTNodeType<T>* temp = node;
             node = node -> right;
             delete temp;
             --count;
           }
       else {
          node -> item = predecessor(node -> left);
          erase(node -> item, node -> left);
       }
    }
    else if (item < node-> item) {
       erase(item, node -> left);
    }
    else {
       erase(item, node -> right);
    }
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: find(const T& item, BTNodeType<T>* node)
//
//  Description: Finds a specified item in BSTType by checking if it is in the
//  specified node, and going through the rest of the list to try to find it if else.
//
//  Preconditions: An instance of BSTType must exist
//
//  Postconditions: Determines whether or not an item is in BSTType by traversing
//  through the list.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
bool BSTType<T>::find(const T& item, BTNodeType<T>* node) const {
   if (node != nullptr) {
      if (item == node -> item) {
         return true;
      }
      else if (item < node -> item) {
         return find(item, node -> left);
      }
      else {
         return find(item, node -> right);
      }
   }
   else {
      return false;
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: inorder(std::ostream& out, BTNodeType<T>* node)
//
//  Description: Prints the binary tree in order from least to greatest in terms
//  of value
//
//  Preconditions: An instance of BSTType must exist
//
//  Postconditions: The binary tree is printed in order from least to greatest
//  in terms of value
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void BSTType<T>::inorder(std::ostream& out, BTNodeType<T>* node) const {
   if (node != nullptr) {
      inorder(out, node -> left);
      out << node -> item << " ";
      inorder(out, node -> right);
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: insert(const T& item, BTNodeType<T>*& node)
//
//  Description: Inserts an item into a binary tree in its respective place
//
//  Preconditions: An instance of BSTType must exist
//
//  Postconditions: item is inserted into BSTType at its respective place in terms
//  of value.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void BSTType<T>::insert(const T& item, BTNodeType<T>*& node) {
   if (node == nullptr) {
      node = new BTNodeType<T>;
      node -> item = item;
      node -> left = nullptr;
      node -> right = nullptr;
      ++count;
   }
   else {
      if (item < node -> item) {
         insert(item, node -> left);
      }
   else {
      insert(item, node -> right);
   }
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: postorder(std::ostream& out, BTNodeType<T>* node)
//
//  Description: Prints the binary tree in postorder format.  This means that left
//  will be printed first, then the right, then the root.
//
//  Preconditions: An instance of BSTType must exist
//
//  Postconditions: The binary tree is printed postorder format.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void BSTType <T>::postorder(std::ostream& out, BTNodeType<T>* node) const {
   if (node != nullptr) {
      postorder(out, node -> left);
      postorder(out, node -> right);
      out << node -> item << " ";
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: predecessor(BTNodeType<T>* node)
//
//  Description: Assigns the previous item's value to the specified node
//
//  Preconditions: An instance of BSTType must exist.
//
//  Postconditions: The previous item's value is assigned to the specified node
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
const T& BSTType<T>::predecessor(BTNodeType<T>* node) {
   while (node -> right != nullptr) {
       node = node -> right;
   }
   return node -> item;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: preorder(std::ostream& out, BTNodeType<T>* node)
//
//  Description: Prints the binary tree in preorder format.  This means that root
//  will be printed first, then the left, then the right.
//
//  Preconditions: An instance of BSTType must exist
//
//  Postconditions: The binary tree is printed preorder format.
//
///////////////////////////////////////////////////////////////////////////////
template <class T>
void BSTType<T>::preorder(std::ostream& out, BTNodeType<T>* node) const {
   if (node != nullptr) {
      out << node -> item << " ";
      preorder(out, node -> left);
      preorder(out, node -> right);
   }
}

#endif
