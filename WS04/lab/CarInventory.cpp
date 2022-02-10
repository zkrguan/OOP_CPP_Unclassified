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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "CarInventory.h"
using namespace std;

namespace sdds {
	// default constructor//
	CarInventory::CarInventory() {
		resetInfo();
	}
	// when the client code invoke the constructor when the aruguments//
	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
		// Create dynamic array for the char values//
		m_brand = new char[strlen(brand) + 1];
		m_model = new char[strlen(model) + 1];
		m_type = new char[strlen(type) + 1];
		// checking if information passed from the parameter validating// 
		bool valid = type && brand && model && year >= 1990 && code >= 100 && code <= 999 && price > 0;
		// if not validating, get rid off the dynamic array//
		if (!valid) {
			delete[] m_brand;
			delete[] m_type;
			delete[] m_model;
			resetInfo();
		}
		// otherwise copy the value into the class attributes//
		else {
			strcpy(m_brand, brand);
			strcpy(m_model, model);
			strcpy(m_type, type);
			m_year = year;
			m_code = code;
			m_price = price;
		}
	}
	// use desctrutor to clear the Dynamic memory allocation//
	CarInventory::~CarInventory() {
		delete[] m_brand;
		delete[] m_type;
		delete[] m_model;
		resetInfo();
	}
	// reset is only for resetting the values//
	void CarInventory::resetInfo() {
		m_brand = nullptr;
		m_type = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_price = 0;
		m_code = 0;
	}

	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
		// before setting the information getting rid off the existing info// 
		delete[] m_brand;
		delete[] m_type;
		delete[] m_model;
		resetInfo();
		//check the input info validation before transfered to the new info//
		bool valid = type && brand && model && year >= 1990 && code >= 100 && code <= 999 && price > 0;
		if (!valid) {
			resetInfo();
		}
		// if it is valid, just copy the input information to the class attribute//
		else {
			m_brand = new char[strlen(brand) + 1];
			m_model = new char[strlen(model) + 1];
			m_type = new char[strlen(type) + 1];
			strcpy(m_brand, brand);
			strcpy(m_model, model);
			strcpy(m_type, type);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		return *this;
	}
	// print out function// 
	void CarInventory::printInfo() const {
		cout << "| ";
		cout.setf(ios::left);
		cout.width(11);
		cout << m_type;
		cout << "| ";
		cout.width(17);
		cout << m_brand;
		cout << "| ";
		cout.width(17);
		cout << m_model;
		cout << "| ";
		cout << m_year << " | ";
		cout.unsetf(ios::left);
		cout.setf(ios::right);
		cout.width(4);
		cout << m_code << " |";
		cout.width(2);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout.width(10);
		cout << m_price << " |" << endl;
		cout.unsetf(ios::right);
		cout.unsetf(ios::fixed);
	}

	// simply checking the existing member attributes see if it is valid//
	bool CarInventory::isValid() const {
		return m_type && m_brand && m_model && m_year >= 1990 && m_price > 0 && m_code >= 100 && m_code <= 999;
	}

	// checking if the two variables similar//
	bool CarInventory::isSimilarTo(const CarInventory& car) const {
		return !strcmp(m_brand, car.m_brand) && !strcmp(m_model, car.m_model) && !strcmp(m_type, car.m_type) && m_year == car.m_year;
	}

	// the logic for checking if there is any elements similar to each other//
	bool find_similar(CarInventory car[], const int num_cars) {
		bool found = false;
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				// added for stopping the memory thrown//
				if (car[i].isValid() && (car[j]).isValid()) {
					if (car[i].isSimilarTo(car[j])) {
						found = true;
					}
				}
			}
		}
		return found;
	}

}