/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 5 part 2
Course title:OOP244 NBB
Module:      Portfolio
Filename:    Portfolio.cpp
Version:     1
student:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Feb 16th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/

//professor's remarks//

/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

   public:
      Portfolio();
      Portfolio(double value, const char* stock, char type);
      void emptyPortfolio();
      std::ostream& display()const;
      void dispPortfolio() const;

      // type conversion overload//
      operator double() const;
      operator const char* () const;
      operator char()const;
      operator bool()const;
      
      // operator overload//
      Portfolio& operator+=(double adding_Value);
      Portfolio& operator-=(double reducing_Value);
      bool operator~() const;
      Portfolio& operator<<(Portfolio& src_Portfolio);
      Portfolio& operator>>(Portfolio& dst_Portfolio);
      
      bool operator!=(const Portfolio& comparing_Portfolio)const;
   };
   // Binary helper operators overload//
   double operator + (const Portfolio& first_Portfolio, const Portfolio& second_Portfolio);
   double operator +=(double& sum_Value, const Portfolio& src_Portfolio);

}
#endif // SDDS_Portfolio_H_