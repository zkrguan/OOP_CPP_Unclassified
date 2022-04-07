/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 9 part 1
Course title:OOP244 NBB
Module:      Text
Filename:    Text.cpp
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
#include "Text.h"
namespace sdds {
   const char& sdds::Text::operator[](int index) const{
      return (m_content && unsigned(index) < strlen(m_content)? m_content[index]:'\0');
   }
   Text::Text(Text& src){
      *this = src;
   }
   Text& Text::operator=(const Text& src){
      if (this!=&src){
         delete[] m_content;
         m_content = new char[strlen(src.m_content) + 1];
         strcpy(m_content, src.m_content);
      }
      return *this;
   }
   std::istream& Text::read(std::istream& istr){
      delete[]m_content;
      m_content = new char[getFileLength(istr) + 1];
      istr.get(m_content, getFileLength(istr)+1,EOF);
      if (m_content){
         istr.clear();
      }
      return istr;
   }
  
   // This function is from the WS instruction//
   int Text::getFileLength(std::istream& is){
      int len{};
      if (is) {
         // save the current read position
         std::streampos cur = is.tellg();
         // go to the end
         is.seekg(0, std::ios::end);
         // let what is the positions (end position = size)
         len = is.tellg();
         // now go back to where you were.
         is.seekg(cur);
      }
      return len;
   }
   std::ostream& Text::write(std::ostream& ostr) const{
      if (m_content){
         ostr << m_content;
      }
      return ostr;
   }
   unsigned Text::contentLength() const{
      return strlen(m_content);
   }
   Text::~Text(){
      delete[] m_content;
   }
   std::istream& operator>>(std::istream& istr, Text& readOn){
     return readOn.read(istr);
   }

   std::ostream& operator<<(std::ostream& ostr, const Text& srcFrom){
      return srcFrom.write(ostr);
   }

}