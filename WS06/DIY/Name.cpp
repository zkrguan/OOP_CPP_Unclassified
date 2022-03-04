/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 6 part 2
Course title:OOP244 NBB
Module:      Name
Filename:    Name.cpp
Version:     1
student:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Feb 15th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Name.h"
using namespace std;

namespace sdds {
	Name::Name(){
		setSafeAndEmpty();
	}

	Name::Name(const char* firstName){
		if (!validateEmpty(firstName)){
			setSafeAndEmpty();
		}
		else{
			this->allocAndCopy(firstName);
		}
	}

	Name::Name(const char* firstName, const char* lastName){
		if (!validateEmpty(firstName)||!validateEmpty(lastName)){
			setSafeAndEmpty();
		}
		else{
			this->allocAndCopy(firstName).allocAndCopy(lastName);
		}
	}

	Name::Name(const char* firstName, const char* middleName, const char* lastName){
		if (!validateEmpty(firstName)||!validateEmpty(middleName)||!validateEmpty(lastName)){
			setSafeAndEmpty();
		}
		else{
			this->allocAndCopy(firstName).
				   allocAndCopy(middleName).
				   allocAndCopy(lastName);
		}
	}

	Name& Name::setSafeAndEmpty() {
		m_firstName = nullptr;
		m_middleName = nullptr;
		m_lastName = nullptr;
		return *this;
	}

	bool Name::validateEmpty(const char* Name)const{
		return !Name || !strcmp(Name, " ");
	}

	Name& Name::allocAndCopy(const char* Name){
		m_firstName = new char[strlen(Name) + 1];
		strcpy(m_firstName, Name);
		return *this;
	}


	Name::Name(const Name& copySrc){
		*this = copySrc;
	}

	Name& Name::operator=(const Name& asnFrom){
		if (this!=&asnFrom){
			if (validateEmpty(asnFrom.m_firstName)||validateEmpty(asnFrom.m_middleName)||validateEmpty(asnFrom.m_lastName)){
				this->allocAndCopy(asnFrom.m_firstName).
					   allocAndCopy(asnFrom.m_middleName).
					   allocAndCopy(asnFrom.m_lastName);
			}
			else {
				setSafeAndEmpty();
			}
		}
		return *this;
	}

	Name::~Name() {
		delete[] m_firstName;
		delete[] m_lastName;
		delete[] m_middleName;
		setSafeAndEmpty();
	}

	Name& Name::setShort(bool flag){
		if (flag){
			if (validateEmpty(m_middleName)){
				char tempInitial[3]{};
				// 1 or 0!!!!!!!!!!!!!!!!!!!!!!!//
				strncpy(tempInitial, m_middleName, 1);
				delete[] m_middleName;
				// might need a file scope var for size//
				m_middleName = new char[3];
				strcpy(m_middleName,tempInitial);
				strcat(m_middleName, ".\0");
			}
		}
		return *this;
	}





}