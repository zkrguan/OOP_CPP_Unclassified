/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 7 part 1
Course title:OOP244 NBB
Module:      Pack
Filename:    Pack.cpp
Version:     1
student:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Mar 15th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/
#include <iostream>
#include "Pack.h"
using namespace std;
namespace sdds {
    Pack::Pack(const char* name,int size, int unitSize, int numOfUnits): Container(name,size*unitSize,numOfUnits*unitSize) {
       m_unitSize = unitSize;
       m_numOfUnits = numOfUnits;
       // validate on the Pack size
       m_PackSize = size;
    }

    int Pack::operator+=(int addUnits){
       int result = 0;
       if (addUnits+m_numOfUnits<=m_PackSize){
          m_numOfUnits += addUnits;
          result = addUnits;
       }
       else{
          result = m_PackSize - m_numOfUnits;
          m_numOfUnits = m_PackSize;
       }
       this->Container::operator+=(result * m_unitSize);
       return result;
    }

    int Pack::operator-=(int deductUnits){
       int result = 0;
       if ((m_numOfUnits - deductUnits)>=0){
          result = deductUnits;
          m_numOfUnits -= deductUnits;
       }
       else{
          result = m_numOfUnits;
          m_numOfUnits = 0;
       }
       this->Container::operator-=(result * m_unitSize);
       return result;
    }

    int Pack::unit() const{
       return m_unitSize;
    }

    int Pack::numOfUnits() const{
       return m_numOfUnits;
    }

    int Pack::size() const{
       return capacity() / m_unitSize;
    }

    Pack& Pack::clear(int PackSize, int unitSize, const char* description){
       if (unitSize>0){
          Container::clear((PackSize*unitSize), description);
          m_unitSize = unitSize;
          m_PackSize = PackSize;
          m_numOfUnits = 0;
       }
       return *this;
    }

    std::ostream& Pack::print(std::ostream& ostr) const{
       if (m_PackSize>0){
          Container::print(ostr) << ", " << m_numOfUnits << " in a pack of " << m_PackSize;
       }
       return ostr;
    }

    std::istream& Pack::read(std::istream& istr) {
       int input = 0;
       bool flag = true;
       if (!bool(*this)) {
          std::cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
          while (istr.get() != '\n');
          flag = false;
       }
       else {
          do {
             if (m_numOfUnits < m_PackSize) {
                cout << "Add to ";
                print(std::cout);
                std::cout << "\n> ";
                if (!(istr >> input)) {
                   std::cout << "Invalid Integer, retry: ";
                   istr.clear();
                   istr.ignore(1000, '\n');
                }
                else {
                   int maxInput = m_PackSize - m_numOfUnits;
                   while (input < 1 || input>maxInput) {
                      std::cout << "Value out of range [1<=val<=" << maxInput << "]: ";
                      istr >> input;
                   }
                   std::cout << "Added " << ((*this) += input) << std::endl;
                   flag = false;
                }
             }
             else {
                std::cout << "Pack is full!, press <ENTER> to continue..." << std::endl;
                while (istr.get() != '\n');
                flag = false;
             }
          } while (flag);
       }
       return istr;
    }
}