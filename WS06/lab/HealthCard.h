/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 6 part 1
Course title:OOP244 NBB
Module:      HealthCard 
Filename:    HealthCard.h
Version:     1
student:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Feb 15th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/

#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

namespace sdds {
   const int MaxNameLength = 55;
   //A file scope variable created by Student//
   const int MaxSNumberLength = 9;
   const int MaxVcodeLength = 2;
   class HealthCard {
      //added {} beside each member variable to make compiler shut up//
      char* m_name{};
      long long m_number{};
      char m_vCode[3]{};
      char m_sNumber[10]{};
      //private method//
      bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
      void setEmpty();
      void allocateAndCopy(const char* name);
      void extractChar(std::istream& istr, char ch) const;
      std::ostream& printIDInfo(std::ostream& ostr)const;
      void set(const char* name, long long number, const char vCode[], const char sNumber[]);
   public:
      //constructors//
      HealthCard();
      HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]);
      HealthCard(const HealthCard& hc);
      HealthCard& operator=(const HealthCard& hc);
      ~HealthCard();
      operator bool()const;
      std::ostream& print(std::ostream& ostr, bool toFile = true) const;
      std::istream& read(std::istream& istr);
     
      //Default state is 
      // m_name is nullptr 
      // m_number is not between >999999999 and <9999999999
      // version number less than two chars
      // snum has less than 9 chars
       
      
      // type conversion overload
      //


   };

   std::ostream& operator <<(std::ostream& ostr, const HealthCard& hc);
   std::istream& operator >>(std::istream& istr, HealthCard& hc);
}
#endif // !SDDS_HealthCard_H


