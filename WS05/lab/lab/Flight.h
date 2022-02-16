/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 5 part 1
Course title:OOP244 NBB
Module:      Flight
Filename:    Flight.h
Version:     1
student:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Feb 9th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/

//professor's remarks//

/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/




#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;

   //This variable is created by student//
   const int requiredFuelPerPassenger = 600;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;
      
      //the following parts are done by Zhaokai Guan//
      //type conversion operators//
      operator bool()const;
      operator int()const;
      operator double()const;
      operator const char*()const;

      //unary member operator//
      bool operator ~()const;
     
      //binary member operator//
      Flight& operator =(Flight& right_Operand);
      Flight& operator =(int assigning_Guests);
      Flight& operator =(double assigning_Fuel);
      Flight& operator +=(double adding_Fuel);
      Flight& operator +=(int adding_Guests);
      Flight& operator -=(double reducing_Fuel);
      Flight& operator -=(int reducing_Guests);
      Flight& operator <<(Flight& source_Flight);
      Flight& operator >>(Flight& destination_flight);
      // Non-required overloaded operator from the instruction//
      // In order to increase the readability//
      bool operator !=(Flight& second_flight)const;
   };

   //binary helper operator//
   int operator + (const Flight& first_Flight, const Flight& second_Flight);
   int operator += (int& passenger_Sum, Flight& source_Flight);
}

#endif // SDDS_FLIGHT_H