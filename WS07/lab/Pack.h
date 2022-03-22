/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 7 part 1
Course title:OOP244 NBB
Module:      Pack
Filename:    Pack.h
Version:     1
student:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Mar 15th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/
#ifndef SSDS_PACK_H
#define SDDS_PACK_H
#include "Container.h"
namespace sdds {
   class Pack : public Container {
      int m_unitSize{};
      int m_PackSize {};
      int m_numOfUnits{};
   public:
      Pack(const char* name,int size, int unitSize=330, int numOfUnits=0);
      int operator += (int addUnits);
      int operator -= (int deductUnits);
      int unit()const;
      int numOfUnits() const;
      int size() const;
      Pack& clear(int PackSize, int unitSize, const char* description);
      std::ostream& print(std::ostream& ostr)const;
      std::istream& read(std::istream& istr);
   };
}
#endif // !SSDS_PACK_H
