/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 5 part 1
Course title:OOP244 NBB
Module:      Flight
Filename:    Flight.cpp
Version:     1
student:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Feb 15th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/


// professor's remarks//
/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.cpp
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
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {
    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    //The following function or method defintions are made by Zhaokai Guan
    
    Flight::operator bool() const{
       return m_passengers > 0 && m_fuel >= m_passengers * requiredFuelPerPassenger ? true : false;
    }

    Flight::operator int() const{
       return m_passengers;
    }

    Flight::operator double() const{
       return m_fuel;
    }

    Flight::operator const char* () const{
       return m_title;
    }

    bool Flight::operator~() const{
       return !m_passengers ? true : false;
    }

    Flight& Flight::operator=(Flight& right_Operand){
       strcpy(m_title, right_Operand.m_title);
       m_passengers = right_Operand.m_passengers;
       m_fuel = right_Operand.m_fuel;
       right_Operand.emptyPlane();
       return *this;
    }

    Flight& Flight::operator=(int assigning_Guests){
       if (assigning_Guests && assigning_Guests<=Boen747Capacity){
          (*this).m_passengers = assigning_Guests;
       }
       return *this;
    }

    Flight& Flight::operator=(double assigning_Fuel){
       if (assigning_Fuel>0 && assigning_Fuel<FuelTankCapacity){
          (*this).m_fuel = assigning_Fuel;
       }
       return *this;
    }

    Flight& Flight::operator+=(double adding_Fuel){
       if (adding_Fuel>0 && m_fuel<FuelTankCapacity){
          if ((m_fuel+adding_Fuel)<FuelTankCapacity){
             m_fuel += adding_Fuel;
          }
          else{
             m_fuel = FuelTankCapacity;
          }
       }
       return *this;
    }

    Flight& Flight::operator+=(int adding_Guests){
       if (adding_Guests>0 && m_passengers<Boen747Capacity){
          if ((m_passengers+adding_Guests)<Boen747Capacity){
             m_passengers += adding_Guests;
          }
          else{
             m_passengers = Boen747Capacity;
          }
       }
       return *this;
    }

    Flight& Flight::operator-=(double reducing_Fuel){
       if (reducing_Fuel>0.0){
          if ((m_fuel-reducing_Fuel)>0.0){
             m_fuel -= reducing_Fuel;
          }
          else{
             m_fuel = 0.0;
          }
       }
       return *this;
    }

    Flight& Flight::operator-=(int reducing_Guests){
       if (reducing_Guests>0){
          if ((m_passengers - reducing_Guests) > 0) {
             m_passengers -= reducing_Guests;
          }
          else{
             m_passengers = 0;
          }
       }
       return *this;
    }

    Flight& Flight::operator<<(Flight& source_Flight) {
       //overloaded != operator to check if the two flights are the same//
       if (!( *this != source_Flight)) {
          if ((m_passengers+source_Flight.m_passengers)<Boen747Capacity){
             m_passengers += source_Flight.m_passengers;
             source_Flight.m_passengers = 0;
          }
          else{
             source_Flight.m_passengers -= (Boen747Capacity - m_passengers);
             m_passengers = Boen747Capacity;             
          }
       }
       return *this;
    }

    Flight& Flight::operator>>(Flight& destination_Flight){
       //overloaded != operator to check if the two flights are the same//
       if (!(*this!=destination_Flight)){
          if ((destination_Flight.m_passengers+m_passengers)<Boen747Capacity){
             destination_Flight.m_passengers += m_passengers;
             m_passengers = 0;
          }
          else{
             m_passengers -= (Boen747Capacity - destination_Flight.m_passengers);
             destination_Flight = Boen747Capacity;
          }
       }
       return *this;
    }

    // build to increase the readbility and avoid the repeatition//
    // Otherwise there will be a super long condition inside << and >> methods//
    bool Flight::operator!=(Flight& second_Flight)const{
       
       // Professor Fardad gave me the advice on this block of code//
       /*bool result = false;
       if (!(strcmp(m_title, second_Flight.m_title))){
          if (m_passengers==second_Flight.m_passengers){
             if (m_fuel==second_Flight.m_fuel)
             {
                result = true;
             }
          }
       }
       return result;*/

       // professor's suggestion// 
       // It is very elegant and consise//
       /* return !(strcmp(m_title, second_Flight.m_title)) &&
          (m_passengers == second_Flight.m_passengers) &&
          (m_fuel == second_Flight.m_fuel); */

       // I implemented in this way since I am more used to tenary expression.//
       // I don't want to just copy paste whatever professor said//
       // Although it is slower than professor's, but it is developed by myself//
       bool result;
       return result = (!(strcmp(m_title, second_Flight.m_title)) &&
          (m_passengers == second_Flight.m_passengers) &&
          (m_fuel == second_Flight.m_fuel)) ?
          true : false;
    }
    
    // binary helper operators//
    int operator+(const Flight& first_Flight, const Flight& second_Flight){
       int result;
       return result = (bool(first_Flight) && bool(second_Flight)) ? int(first_Flight) + int(second_Flight) : 0;
    }

    int operator+=(int& passenger_Sum, Flight& source_Flight){
       return passenger_Sum += int(source_Flight);
    }

}