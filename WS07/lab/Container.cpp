/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 7 part 1
Course title:OOP244 NBB
Module:      Container
Filename:    Container.cpp
Version:     1
student:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Mar 15th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Container.h"

namespace sdds {
   Container::Container(const char* srcContent, int srcCapacity){
      if (!srcContent){
         m_capacity = -1;
      }
      else{
         strcpy(m_content, srcContent);
         m_capacity = srcCapacity;
      }
   }

   Container::Container(const char* srcContent, int srcCapacity, int srcContentVolume){
      if (!srcContent||srcContentVolume>srcCapacity){
         m_capacity = -1;
      }
      else{
         m_capacity = srcCapacity;
         m_contentVolume = srcContentVolume;
         strcpy(m_content, srcContent);
      }
   }

   Container& Container::setEmpty() {
      // invalid state defined//
      m_capacity = -1;
      return *this;
   }

   int Container::capacity() const{
      return m_capacity;
   }

   int Container::volume() const{
      return m_contentVolume;
   }

   int Container::operator+=(int srcVolume){
      int result = 0;
      if (m_contentVolume!=m_capacity){
         if ((srcVolume+m_contentVolume)<=m_capacity){
            m_contentVolume += srcVolume;
            result = srcVolume;
         }
         else{
            result = m_capacity-m_contentVolume;
            m_contentVolume += result;
         }
      }
      return result;
   }

   int Container::operator-=(int deductVolume){
      int result = 0;
      if (m_contentVolume){
         if ((m_contentVolume-deductVolume)>=0){
            m_contentVolume -= deductVolume;
            result = deductVolume;
         }
         else{
            result = m_contentVolume;
            m_contentVolume = 0;
         }
      }
      return result;
   }

   Container::operator bool() const{
      return (m_capacity != -1);
   }

   void Container::clear(const int capacity, const char* content) {
      if (capacity && content){
         strcpy(m_content, content);
         m_capacity = capacity;
      }
   }

   std::ostream& Container::print(std::ostream& ostr) const{
      if (this->operator bool()){
         ostr << m_content << ": (" << m_contentVolume << "cc/" << m_capacity << ")";
         return ostr;
      }
      else{
         ostr << "****: (**cc/***)";
      }
      return ostr;
   }

   std::istream& Container::read(std::istream& istr){
      int input = 0;
      bool flag = true;
      do {
         if (!bool(*this)){
            std::cout << "Broken Container, adding aborted! Press <ENTER> to continue...."<<std::endl;
            while (istr.get() != '\n');
            flag = false;
         }
         else{
            std::cout << "Add to ";
            print(std::cout);
            std::cout << "\n> ";
            if (!(istr >> input)) {
               std::cout << "Invalid Integer, retry: ";
               istr.clear();
               istr.ignore(1000, '\n');
            }
            else{
               if (input<1||input>999){
                  std::cout << "Value out of range [1<=val<=999]: ";
               }
               else {
                  std::cout << "Added " << ((*this) += input) << " CCs" << std::endl;
                  flag = false;
               }
            }             
         }  
      } while (flag);
      return istr;
   }

   std::ostream& operator<<(std::ostream& ostr, const Container& ctnerToPrint){
      ctnerToPrint.print(ostr);
      return ostr;
   }

   std::istream& operator>>(std::istream& istr, Container& ctnerToSet){
      ctnerToSet.read(istr);
      return istr;
   }

}