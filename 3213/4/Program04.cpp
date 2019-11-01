///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program #4
//  Due: 11/01/2019
//
//  Description:
//  Driver program for testing the the binary search tree functions.  This tests
//  inserting items into an instance of BSTType and printing them out in Preorder,
//  Postorder, and in-order.
//
//  Input: None
//
//  Output: Prints the BSTType list in preorder, postorder, and in-order.
//
//  Assumptions: None
//
//////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include "BTNodeType.h"
#include "BSTType.h"

using namespace std;

int main() {

   BSTType<int> btlist;

   if (btlist.empty()) {
      while (btlist.size() < 10) {
        int item = rand() % 500;
        if (!btlist.find(item)) {
           btlist.insert(item);
        }
      }
   }
   if (!btlist.empty()) {
      cout << "Preorder: ";
      btlist.traverse(cout, PRE);
      cout << endl;
      cout << "Postorder: ";
      btlist.traverse(cout, POST);
      cout << endl;
      cout << "In order: ";
      btlist.traverse(cout, IN);
   }


   return 0;
}
