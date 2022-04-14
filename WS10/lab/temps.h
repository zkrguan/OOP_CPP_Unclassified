/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 10 part 1
Course title:OOP244 NBB
Module:      temps
Filename:    temps.h
Version:     1
student:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Apl 08 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/
#ifndef SDDS_TEMPS_H
#define SDDS_TEMPS_H
#include <iostream>
#include "Collection.h"
namespace sdds {

   /// <summary>
   /// type's requirement:
   /// for the compound type:
   /// type's == operator must be overloaded for comparing both types of the values. 
   /// type's =  (assignment) operator must be overloaed for copying values.
   /// for primaritive type: 
   /// the type must be able to be compared by == and assigned by using =. 
   /// e.g int double float etc can be compared by == and assigned by =. 
   /// 
   /// Collection's requirement:
   /// Collection needs the default constructor for creating instance of the collection.
   /// Collection must have the subscribe operator [] overloaded to return an 
   /// modifiable type reference element back. ( so the type's assignment operator can be used 
   /// to assign right oppnent's value onto the left oppnent's value. 
   /// 
   /// </summary>
   template <typename type>
   Collection<type> select(const type* arr, int size, const type& cmpTo ) {
      int matches=0;
      for (int i = 0; i<size; i++){
         if (arr[i]==cmpTo){
            matches++;
         }
      }
      Collection <type> temp(matches);
      int counter = 0;
      for (int i = 0; i < size; i++){
         if (arr[i]==cmpTo){
            temp[counter]=arr[i];
            counter++;
         }
      }
      return temp;
   }

   /// <summary>
   /// t's requirement 
   /// 
   /// for the compound type:
   /// The insertion operator (<<) must be overloaded, 
   /// so the function can use cout to directly invoke the type's 
   /// display method. ( implemented by inherited from the interface 
   /// displayable )
   /// 
   /// for the primaritive type:
   /// there is no specific requirements . 
   /// 
   /// Collection's requirement 
   /// Again the subscribe operator must be overloaded to return an 
   /// CONST type reference in order to inovke the display method. 
   /// 
   /// </summary>
   template <typename t>
   void printCollection(const Collection<t>& src, const char* title) {
      std::cout << title << std::endl;
      for (unsigned i = 0; i < src.size(); i++) {
         std::cout << src[i] << std::endl;
      }
   }
   
}
#endif // !SDDS_TEMPS_H
