#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "CarInventory.h"
using namespace std;

namespace sdds {

	CarInventory::CarInventory() {
		resetInfo();
	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
		m_brand = new char[strlen(brand) + 1];
		m_model = new char[strlen(model) + 1];
		m_type = new char[strlen(type) + 1];
		bool valid = type && brand && model && year >= 1990 && code >= 100 && code <= 999 && price > 0;
		if (!valid) {
			delete[] m_brand;
			delete[] m_type;
			delete[] m_model;
			resetInfo();
		}

		else {
			strcpy(m_brand, brand);
			strcpy(m_model, model);
			strcpy(m_type, type);
			m_year = year;
			m_code = code;
			m_price = price;
		}
	}

	CarInventory::~CarInventory() {
		delete[] m_brand;
		delete[] m_type;
		delete[] m_model;
		resetInfo();
	}

	void CarInventory::resetInfo() {

		m_brand = nullptr;
		m_type = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_price = 0;
		m_code = 0;
	}

	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
		delete[] m_brand;
		delete[] m_type;
		delete[] m_model;
		resetInfo();
		bool valid = type && brand && model && year >= 1990 && code >= 100 && code <= 999 && price > 0;
		if (!valid) {
			resetInfo();
		}

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

	bool CarInventory::isValid() const {
		return m_type && m_brand && m_model && m_year >= 1990 && m_price > 0 && m_code >= 100 && m_code <= 999;
	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const {
		return !strcmp(m_brand, car.m_brand) && !strcmp(m_model, car.m_model) && !strcmp(m_type, car.m_type) && m_year == car.m_year;
	}

	bool find_similar(CarInventory car[], const int num_cars) {
		bool found = false;
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
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