/* ------------------------------------------------------
I have done all the coding by myself and 
only copied the code that my professor provided 
to complete my workshops and assignments.

Workshop 2 part 2
Module:      N/A
Filename:    main.cpp
Version:     1
Author:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca

-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#include <iostream>
#include "cStrTools.h"
#include "DNA.h"
using namespace std;
using namespace sdds;
int main() {
   bool done = false;
   char dna[101];
   char filename[256];
   cout << "Enter DNA data file name: ";
   cin >> filename;
   if (beginSearch(filename)) {
      while (!done) {
         cout << "Enter a DNA squence (max 100 chars)" << endl << "> ";
         read(dna, 100);
         if (strCmp(dna, "!") == 0) {
            done = true;
         }
         else {
            if (read(dna)) {
               sort();
               displayMatches();
               deallocate();
            }
            else {
               cout << "No match found!" << endl;
            }
         }
      }
      endSearch();
   }
   return 0;
}