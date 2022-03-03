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
      int counter = 0;
      for (int i = 0; isalpha(sNumber[i]); i++) {
         counter++;
      }
      bool flag = counter == MaxSNumberLength ? true : false;
      return name &&
         number > 999999999 &&
         number < 9999999999 &&
         isalpha(vCode[1]) &&
         isalpha(vCode[2]) &&
         flag;
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
      ostr << m_number<<"-";
      for (int i = 0; i < MaxVcodeLength; i++) {
         ostr << m_vCode[i];
      }
      ostr << ",";
      for (int i = 0; i < MaxSNumberLength; i++){
         ostr << m_sNumber[i];
      }
      ostr << endl;
      return ostr;
   }

   void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]){
      if (validID(name, number, vCode, sNumber)) {
         allocateAndCopy(name);
         m_number = number;
         for (int i = 0; i < MaxVcodeLength; i++){
            m_vCode[i] = vCode[i];
         }
         for (int i = 0; i < MaxSNumberLength; i++) {
            m_sNumber[i] = sNumber[i];
         }
      }
      else{
         delete[]m_name;
         setEmpty();
      }
   }

   HealthCard::HealthCard() {
      m_name = nullptr;
   }

   HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
      set(name,number,vCode,sNumber);
   }

   HealthCard::HealthCard(const HealthCard& hc){
      if (validID(hc.m_name,hc.m_number,hc.m_vCode,hc.m_sNumber)){
         set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
      }
   }

   HealthCard& HealthCard::operator=(const HealthCard& hc){
      if (m_name!=hc.m_name){
         if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) {
            set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
         }
      }
      return *this;
   }

   HealthCard::~HealthCard(){
      delete[] m_name;
      m_name = nullptr;
   }

   HealthCard::operator bool() const{
      return !m_name;
   }

   ostream& HealthCard::print(ostream& ostr, bool toFile) const{
      if (toFile){
         for (int i = 0; m_name[i]!=0 ;i++){
            ostr << m_name[i];
         }
         ostr << ",";
         printIDInfo(ostr);
      }
      else{
         ostr.width(50);
         ostr.setf(ios::left);
         ostr.fill('.');
         for (int i = 0; m_name[i] != 0; i++) {
            ostr << m_name[i];
         }
         printIDInfo(ostr);
      }
      return ostr;
   }

   std::istream& HealthCard::read(std::istream& istr){
      char tempName[MaxNameLength]{};
      long long tempNumber{};
      char tempVCode[3]{};
      char tempSNumber[10]{};
      istr.get(tempName,MaxNameLength, ',');
      extractChar(istr, ',');
      istr >> m_number;
      extractChar(istr, '-');
      istr.get(tempVCode, MaxVcodeLength, ',');
      extractChar(istr, ',');
      istr.get(tempSNumber, MaxSNumberLength, '\n');
      extractChar(istr, '\n');
      if (!istr.fail()){
         set(tempName, tempNumber, tempVCode, tempSNumber);
      }
      return istr;
   }

   std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc){
      if (bool(hc)){
         hc.print(ostr, false);
      }
      else{
         ostr << "Invalid Card Number" << endl;
      }
      return ostr;
   }

   std::istream& operator>>(std::istream& istr, HealthCard& hc){
      return hc.read(istr);
   }

}
