/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 3 part 1
Course title:OOP244 NBB
Module:      Train
Filename:    Train.h
Version:     1
Author:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Feb 2nd 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H
namespace sdds {

	 const int MAX_NAME_LENGTH = 20;
	 const int MAX_PEOPLE = 1000;
	 const int MAX_SPEED = 320;

	 class Train {
		  char m_train_Name[MAX_NAME_LENGTH];
		  int  m_ppl_On_Board;
		  double  m_train_Speed;
	 
	 public:
		  //modifier functions//
		  void set(const char* train_name, int num_Of_Ppl, double speed);
		  // query functions//
		  int getNumberOfPeople() const;
		  const char* getName() const;
		  double getSpeed() const;
		  bool isSafeEmpty() const;
		  void display() const;
	 };
}
#endif // !SDDS_TRAIN_H

