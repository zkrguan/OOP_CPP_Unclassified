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
#include"Text.h"
#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
namespace sdds {
   class HtmlText : public Text {
      char* m_title{};
   public:
      HtmlText() {};
      HtmlText(const char* title);
      HtmlText(const HtmlText& src);
      HtmlText& operator = (const HtmlText& src);
      std::ostream& write(std::ostream& ostr) const;
      ~HtmlText();
   };
}
#endif // !SDDS_HTMLTEXT_H
