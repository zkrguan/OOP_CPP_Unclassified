#include <iostream>
#include <cstring>
#include "Container.h"

namespace sdds {
   container::container(const char* srcContent, int srcCapacity){
      if (!srcContent){
         m_capacity = 0;
      }
      else{
         strcpy(m_content, srcContent);
         m_capacity = srcCapacity;
      }
   }
   container::container(const char* srcContent, int srcCapacity, int srcContentVolume){
      if (!srcContent||srcContentVolume>srcCapacity){
         //To set invalid//
      }
      else{
         m_capacity = srcCapacity;
         m_contentVolume = srcContentVolume;
         strcpy(m_content, srcContent);
      }
   }

   container::~container(){

   }
   
   container& container::setEmpty() {
      // invalid state //
      m_capacity = -1;
      m_contentVolume = -2;
   }

   int container::capacity() const{
      return m_capacity;
   }

   int container::volume() const{
      return m_contentVolume;
   }

   int container::operator+=(int srcVolume){
      int result = 0;
      if (m_contentVolume!=m_capacity){
         if ((srcVolume+m_contentVolume)<=m_capacity){
            m_contentVolume += srcVolume;
            result = srcVolume;
         }
         else{
            result = srcVolume - m_capacity;
            m_contentVolume += result;
         }
      }
      return result;
   }

   int container::operator-=(int deductVolume){
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

   container::operator bool() const{
      return (m_contentVolume != -2 || m_capacity != -1);
   }

   void container::clear(const int capacity, const char* content) {
      if (capacity && content){
         strcpy(m_content, content);
         m_capacity = capacity;
      }
   }

   std::ostream& container::print(std::ostream& ostr) const{
      if (this->operator bool()){
         ostr << m_content << ": (" << m_contentVolume << "cc/" << m_capacity << ")" << std::endl;
         return ostr;
      }
      else{
         ostr << "****: (**cc/***)" << std::endl;
      }
   }

   std::istream& container::read(std::istream& istr){
      
         int input = 0;
         bool flag = true;
         
         do {
            if (!bool(*this)){
               std::cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << std::endl;
               istr.get();
            }
            else
            {
               print(std::cout);
               std::cout << ">";
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
                     std::cout << "Added " << ((*this) += input) << "CCs" << std::endl;
                     flag = false;
                  }
               }             
            }  
         } while (flag);
   }




}