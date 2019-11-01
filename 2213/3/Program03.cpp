///////////////////////////////////////////////////////////////////////////////
//
//  Ryne Whitaker
//  Program #3
//  Due: 03/17/2019
//
//  Description:
//  This program tests the functions created in ListType through two different
//  lists: olist (an ordered list) and ulist (an unordered list).  This tests
//  inserting, erasing, finding, counting, testing for full/empty, etc.  The
//  first half of the program tests the functions for olist, and the second
//  half of the program tests the inputs for ulist.
//
//  Input:
//  No input is required because everything is handled inside the program by
//  itself.  The user simply executes the program and the output is made.
//
//  Output:
//  The program will output the results of the various tests performed on
//  the lists.  If a test was successful, it will output that it was successful
//  and otherwise will notify the user that that specific test failed.  It will
//  output the lists themselves, the size if the lists, whether or not the lists
//  are full/empty, etc.  Each test will be output on a new line, and the
//  first half of the output (that for olist) will be separated from the second
//  half of the output (that for ulist) by a blank line and header.
//
//  Assumptions:
//  I only put this leading description in Program03.cpp because at the top
//  we are supposed to put the program number.  Since the other files are not
//  separate programs, there is not another number to put for them.
//
//////////////////////////////////////////////////////////////////////////////

#include "UListType.h"
#include "OListType.h"
#include<iostream>

using namespace std;

int main() {
   // Declaration of lists that inherit from ListType.h
   OListType<int> olist;
   UListType<int> ulist;

   //////////////////////////////////
   // Ordered List Testing Section //
   //////////////////////////////////
   cout << "Ordered List: " << endl;

   // Testing inserting items into the list
   for (int i = 11; i >= 1; i = i - 10) {
      if (olist.insert(i)) {
         cout << "Insert of " << i << " in ordered list succeeded" << endl;
      } else {
         cout << "Insert of " << i << " in ordered list failed" << endl;
      }
   }
   cout << olist << endl;
   olist.insert(115);
   cout << olist << endl;

   cout << "Currently, the size of the ordered list is " << olist.size() << "." << endl;

   // Testing finding items
   for (size_t items = 1; items <= 11; ++items) {
      if (olist.find(items)) {
         cout << items << " is in the ordered list." << endl;
      } else {
         cout << items << " is not in the ordered list." << endl;
      }
   }

   cout << olist << endl;

   if (olist.find(0)) {
      cout << "0 is in the ordered list." << endl;
   }

   // Testing erasing an item
   if(olist.erase(11)) {
      cout << "Erase of 11 from the ordered list succeeded." << endl;
      cout << olist << endl;
   } else {
      cout << "Erase of 11 from the ordered list failed." << endl;
   }

   // Is the list empty?
   if (olist.empty()) {
      cout << "olist is empty." << endl;
   } else {
      cout << "olist is not empty." << endl;
   }

   // Testing erasing all the items in a list and checking size after
   olist.eraseAll();

   if(olist.size() == 0) {
      cout << "Erase of the entire ordered list succeeded." << endl;
      cout << "olist elements: " << olist << endl;
      cout << "olist size: " << olist.size() << endl;
   } else {
      cout << "Erase of the entire ordered list failed." << endl;
   }

   // Is list empty after having all items erased from it?
   if (olist.empty()) {
      cout << "olist is empty." << endl;
   } else {
      cout << "olist is not empty." << endl;
   }

   // Testing order of list by inserting items out of order
   olist.insert(92);
   olist.insert(1);
   olist.insert(5);
   olist.insert(23);
   olist.insert(53);
   olist.insert(4);
   olist.insert(94);
   olist.insert(12);
   olist.insert(42);
   olist.insert(0);
   cout << olist << endl;

   cout << "The size of olist is " << olist.size() << "." << endl;

   // Testing erasing items
   for (size_t items = 0; items <= 100; ++items) {
      if (olist.erase(items)) {
         cout << items << " was successfully erased from olist." << endl;
      }
   }

   cout << "Elements in olist: " << olist << endl;

   OListType<int> olist2;

   olist2.insert(5);
   olist2.insert(3);
   olist2.insert(12);
   olist2.insert(14);
   olist2.insert(7);
   cout << "olist2 elements: " << olist2 << endl;

   olist.insert(0);
   olist.insert(3);
   olist.insert(2);
   olist.insert(74);
   olist.insert(17);
   cout << "olist elements: " << olist << endl;

   cout << "Replacing olist2 with olist..." << endl;

   olist2 = olist;
   cout << "olist2 elements: " << olist2 << endl;
   cout << "olist elements: " << olist << endl;

   ////////////////////////////////////
   // Unordered List Testing Section //
   ////////////////////////////////////
   cout << endl << "Unordered List: " << endl;

   // Testing inserting items into the list
   for (int i = 1; i <= 11; i = i + 10) {
      if (ulist.insert(i)) {
         cout << "Insert of " << i << " in unordered list succeeded" << endl;
      } else {
         cout << "Insert of " << i << " in unordered failed" << endl;
      }
   }

   cout << ulist << endl;
   ulist.insert(115);
   cout << ulist << endl;

   // Testing function that displays size of list
   cout << "Currently, the size of the unordered list is " << ulist.size() << "." << endl;

   // Testing finding items in list
   for (size_t items = 1; items <= 11; ++items) {
      if (ulist.find(items)) {
         cout << items << " is in the unordered list." << endl;
      } else {
         cout << items << " is not in the unordered list." << endl;
      }
   }

   cout << ulist << endl;

   if (ulist.find(0)) {
      cout << "0 is in the unordered list." << endl;
   }

   // Testing erasing an item from list
   if(ulist.erase(11)) {
      cout << "Erase of 11 from the unordered list succeeded." << endl;
      cout << ulist << endl;
   } else {
      cout << "Erase of 11 from the unordered list failed." << endl;
   }

   // Is list empty?
   if (ulist.empty()) {
      cout << "ulist is empty." << endl;
   } else {
      cout << "ulist is not empty." << endl;
   }

   // Erase all items in list and test size
   ulist.eraseAll();

   if(ulist.size() == 0) {
      cout << "Erase of the entire unordered list succeeded." << endl;
      cout << "ulist elements: " << ulist << endl;
      cout << "ulist size: " << ulist.size() << endl;
   } else {
      cout << "Erase of the entire unordered list failed." << endl;
   }

   // Is list empty after erasing all items in the list?
   if (ulist.empty()) {
      cout << "ulist is empty." << endl;
   } else {
      cout << "ulist is not empty." << endl;
   }

   // Testing list order by inserting items out of order
   ulist.insert(92);
   ulist.insert(1);
   ulist.insert(5);
   ulist.insert(23);
   ulist.insert(53);
   ulist.insert(4);
   ulist.insert(94);
   ulist.insert(12);
   ulist.insert(42);
   ulist.insert(0);
   cout << ulist << endl;

   cout << "The size of ulist is " << ulist.size() << "." << endl;

   // Erasing all items in list
   for (size_t items = 0; items <= 100; ++items) {
      if (ulist.erase(items)) {
         cout << items << " was successfully erased from ulist." << endl;
      }
   }

   // Which elements are in list after erasing all items?
   cout << "Elements in ulist: " << ulist << endl;

   UListType<int> ulist2;

   ulist2.insert(5);
   ulist2.insert(3);
   ulist2.insert(12);
   ulist2.insert(14);
   ulist2.insert(7);
   cout << "ulist2 elements: " << ulist2 << endl;

   ulist.insert(0);
   ulist.insert(3);
   ulist.insert(2);
   ulist.insert(74);
   ulist.insert(17);
   cout << "ulist elements: " << ulist << endl;

   cout << "Replacing ulist2 with ulist..." << endl;

   ulist2 = ulist;
   cout << "ulist2 elements: " << ulist2 << endl;
   cout << "ulist elements: " << ulist << endl;



   return 0;
}





















