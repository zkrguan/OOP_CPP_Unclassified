/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 4 part 1
Course title:OOP244 NBB
Module:      CarInventory
Filename:    CarInventory.cpp
Version:     1
Author:	     Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Feb 9th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/

#ifndef SDDS_CARINVENTORY_H
#define SDDS_CARINVENTORY_H
namespace sdds {
	


	class CarInventory
	{

	private:
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		//This function should be private//
		void resetInfo();

	public:
		// constructor and destructors//
		CarInventory();
		~CarInventory();
		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1.0);
		// public functions//
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory& car) const;
		
	};
	//Global function as the instruction requested//  
	bool find_similar(CarInventory car[], const int num_cars);
}


#endif // !SDDS_CARINVENTORY_H
