
/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 9 part 1
Course title:OOP244 NBB
Module:      HtmlText
Filename:    HtmlText.h
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
#include "HtmlText.h"

namespace sdds {
   sdds::HtmlText::HtmlText(const char* title) {
      m_title = new char [strlen(title) + 1];
      strcpy(m_title, title);
   }

   HtmlText::HtmlText(const HtmlText& src){
      *this = src;
   }

   HtmlText& HtmlText::operator=(const HtmlText& src){
      if (this!=&src){
         m_title = new char[strlen(src.m_title) + 1];
         strcpy(m_title, src.m_title);
         Text::operator = (src);
      }
      return *this;
   }

   std::ostream& HtmlText::write(std::ostream& ostr) const{
      bool MS = false;
      ostr << "<html><head><title>";
      // use tenary to make it concise //
      ostr << (m_title ? "m_title" : "No Title");
      ostr << "</title></head>\n<body>\n";
      if (m_title){
         ostr << "<h1>" << m_title << "</h1>\n";
         for (unsigned i = 0;i<this->contentLength(); i++) {
            switch (this->operator[](i)) {
            case' ':
               if (MS) {
                  ostr << "&nbsp;";
               }
               else {
                  MS = true;
                  ostr << ' ';
               }
               break;
            case'<':
               ostr << "&lt;";
               MS = false;
               break;
            case'>':
               ostr << "&gt;";
               MS = false;
               break;
            case '\n':
               ostr << "<br />\n";
               MS = false;
               break;
            default:
               ostr << this->operator[](i);
               MS = false;
               break;
            }
         }
      }
      ostr << "</body>\n</html>";
      return ostr;
   }

   HtmlText::~HtmlText(){
      delete[]m_title;
   }

   

}

