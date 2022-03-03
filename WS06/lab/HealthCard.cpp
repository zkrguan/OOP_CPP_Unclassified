/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 6 part 1
Course title:OOP244 NBB
Module:      HealthCard
Filename:    HealthCard.cpp
Version:     1
student:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Feb 15th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "HealthCard.h"
using namespace std;
namespace sdds {
   bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
      return name &&
             (number > 999999999 &&
             number < 9999999999) &&
             strlen(vCode)==2 &&
             strlen(sNumber)==9;
   }

   void HealthCard::setEmpty() {
      m_name = nullptr;
   }

   void HealthCard::allocateAndCopy(const char* name) {
      delete[] m_name;
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);
   }

   void HealthCard::extractChar(istream& istr, char ch) const{
      char nextChar;
      nextChar = istr.peek();
      if (nextChar==ch){
         istr.ignore();
      }
      else{
         istr.ignore(1000, ch);
         istr.setstate(ios::failbit);
      }
   }

   ostream&HealthCard::printIDInfo(ostream& ostr)const{
      ostr << m_number;
      ostr <<"-";
      ostr << m_vCode;
      ostr << ", ";
      ostr << m_sNumber;
      return ostr;
   }

   void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]){
      if (validID(name, number, vCode, sNumber)) {
         allocateAndCopy(name);
         m_number = number;
         strcpy(m_vCode, vCode);
         strcpy(m_sNumber,sNumber); 
      }
      else{
         delete[]m_name;
         setEmpty();
      }
   }

   HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
      set(name,number,vCode,sNumber);
   }

   HealthCard::HealthCard(const HealthCard& hc){
      if (validID(hc.m_name,hc.m_number,hc.m_vCode,hc.m_sNumber)){
         *this = hc;
      }
   }

   HealthCard& HealthCard::operator=(const HealthCard& hc){
      if (m_name!=hc.m_name){
          set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
      }
      return *this;
   }

   HealthCard::~HealthCard(){
      delete[] m_name;
      m_name = nullptr;
   }

   HealthCard::operator bool() const{
      return m_name;
   }

   ostream& HealthCard::print(ostream& ostr, bool toFile) const{
      if (validID(m_name, m_number, m_vCode, m_sNumber)) {
         if (toFile) {
            ostr << m_name;
            ostr << ",";
            printIDInfo(ostr)<<endl;
         }
         else {
            ostr.width(50);
            ostr.setf(ios::left);
            ostr.fill('.');
            ostr << m_name;
            printIDInfo(ostr);
         }
      }
      return ostr;
   }

   istream& HealthCard::read(istream& istr){
      char tempName[MaxNameLength]{};
      long long tempNumber{};
      char tempVCode[3]{};
      char tempSNumber[10]{};
      istr.get(tempName,MaxNameLength, ',');
      extractChar(istr, ',');
      istr >> tempNumber;
      extractChar(istr, '-');
      istr.get(tempVCode,3 ,',');
      extractChar(istr, ',');
      istr.get(tempSNumber, 10,'\n');
      extractChar(istr, '\n');
      if (istr.fail()){
         istr.clear();
         istr.ignore(1000, '\n');
      }
      else{
         set(tempName, tempNumber, tempVCode, tempSNumber);
      }
      return istr;
   }

   ostream& operator<<(ostream& ostr, const HealthCard& hc){
      if (bool(hc)){
         hc.print(ostr, false);
      }
      else{
         ostr << "Invalid Health Card Record";
      }
      return ostr;
   }

   istream& operator>>(istream& istr, HealthCard& hc){
      return hc.read(istr);
   }

}
