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
Filename: Portfolio.cpp
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }

    void Portfolio::dispPortfolio () const{
       cout << " ";
       cout.width(10);
       cout << (const char*)(*this);
       cout << " | ";
       cout << "Value: ";
       cout.width(10);
       cout << double(*this);
       cout << " | ";
       cout << " Type: ";
       cout << char(*this);
    }
   
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    // the student code starts from here//
    // type conversion operator overload//
    Portfolio::operator double() const {
       return m_value;
    }

    Portfolio::operator const char* () const {
       return m_stock;
    }
   
    Portfolio::operator char()const {
       return m_type;
    }

    Portfolio:: operator bool()const {
       return m_type == 'G' || m_type == 'V' || m_type == 'I';
    }

    //binary member operator overload//
    Portfolio& Portfolio::operator+=(double adding_Value) {
       if (bool(*this) && adding_Value>0){
          m_value += adding_Value;
       }
       return *this;
    }

    Portfolio& Portfolio::operator-=(double reducing_Value) {
       if (bool(*this) && reducing_Value>0){
          m_value -= reducing_Value;
       }
       return *this;
    }

    // Built by myself, in order to enhance the readability//
    bool Portfolio::operator!=( const Portfolio& comparing_Portfolio)const {
       return strcmp(m_stock, comparing_Portfolio.m_stock);
    }

    Portfolio& Portfolio::operator<<(Portfolio& src_Portfolio){
       if ( *this != src_Portfolio) {
          m_value += src_Portfolio.m_value;
          src_Portfolio.emptyPortfolio();
       }
       return *this;
    }

    Portfolio& Portfolio::operator>>(Portfolio& dst_Portfolio) {
       if ( *this != dst_Portfolio) {
          dst_Portfolio.m_value += m_value;
          (*this).emptyPortfolio();
       }
       return *this;
    }
    
    //unary member operator overload//
    bool Portfolio::operator~() const {
       return m_value < 0;
    }
    
    // Binary helper operator overload//
    double operator + (const Portfolio& first_Portfolio, const Portfolio& second_Portfolio) {
       double result = 0.0;
       return result = (bool(first_Portfolio) && bool(second_Portfolio)) ?
          double(first_Portfolio) + double(second_Portfolio) :
          0;
    }

    double operator +=(double& sum_Value, const Portfolio& src_Portfolio) {
       sum_Value += double(src_Portfolio);
       return sum_Value;
    }
}

