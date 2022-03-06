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
#include <string>
#include <cstring>
#include "Name.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Name::Name(){
		setSafeAndEmpty();
	}

	Name::Name(const char* firstName){
		if (validateEmpty(firstName)){
			setSafeAndEmpty();
		}
		else{
			delete[] m_firstName;
			m_firstName = new char[strlen(firstName) + 1];
			strcpy(m_firstName, firstName);
		}
	}

	Name::Name(const char* firstName, const char* lastName){
		if (validateEmpty(firstName)&&validateEmpty(lastName)){
			setSafeAndEmpty();
		}
		else{
			delete[] m_firstName;
			m_firstName = new char[strlen(firstName) + 1];
			strcpy(m_firstName, firstName);
			delete[] m_lastName;
			m_lastName = new char[strlen(lastName) + 1];
			strcpy(m_lastName, lastName);
		}
	}

	Name::Name(const char* firstName, const char* middleName, const char* lastName){
		if (validateEmpty(firstName)&&validateEmpty(middleName)&&validateEmpty(lastName)){
			setSafeAndEmpty();
		}
		else{
			set(firstName, middleName, lastName);
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

	void Name::deallocate(){
		delete[] m_firstName;
		delete[] m_middleName;
		delete[] m_lastName;
		setSafeAndEmpty();
	}

	Name::Name(const Name& copySrc){
		*this = copySrc;
	}

	Name& Name::operator=(const Name& asnFrom){
		if (this!=&asnFrom){
			if (validateEmpty(asnFrom.m_firstName)&&validateEmpty(asnFrom.m_middleName)&&validateEmpty(asnFrom.m_lastName)){
				setSafeAndEmpty();
			}
			else if(validateEmpty(asnFrom.m_lastName)&&validateEmpty(asnFrom.m_middleName)){
				set(asnFrom.m_firstName);
			}
			else if (validateEmpty(asnFrom.m_middleName)){
				set(asnFrom.m_firstName, asnFrom.m_lastName);
			} 
			else{
				set(asnFrom.m_firstName, asnFrom.m_middleName, asnFrom.m_lastName);
			} 
		}
		return *this;
	}

	Name::~Name() {
		deallocate();
	}

	Name& Name::setShort(bool flag){
		if (flag){
			if (!validateEmpty(m_middleName)){
				char tempInitial[3]{};
				strncpy(tempInitial, m_middleName, 1);
				strcat(tempInitial, ".\0");
				delete[] m_middleName;
				m_middleName = new char[3];
				strcpy(m_middleName,tempInitial);
			}
		}
		return *this;
	}

	Name& Name:: operator+= (const char* stringIn) {
		if (stringIn[0]!= '\0') {
			int couter = 0;
			for (unsigned int i = 0; i < strlen(stringIn); i++) {
				couter += isspace(stringIn[i]) ? 1 : 0;
			}
			if (!couter)
			{
				if (!m_firstName) {
					m_firstName = new char[strlen(stringIn) + 1];
					strcpy(m_firstName, stringIn);
				}
				else if (!m_middleName) {
					m_middleName = new char[strlen(stringIn) + 1];
					strcpy(m_middleName, stringIn);
				}
				else if (!m_lastName) {
					m_lastName = new char[strlen(stringIn) + 1];
					strcpy(m_lastName, stringIn);
				}
				else {
					deallocate();
				}
			}
		}
		return *this;
	}

	std::istream& Name::read(std::istream& istr){
		char whole[100]{};
		int spaceCounter = 0;
		// I know this is dumb, but the main code flushes the buffer//
		// if I use the getline, nothing will be inside buffer, and the cin.ignore will// 
		// promopt me again for input//
		// Intentionally leave some chars inside the buffer to cope with the main code//
		istr.get(whole, 1000, '\n');
		string wholeLine(whole);
		for (unsigned int i = 0; i < wholeLine.length(); i++){
			spaceCounter += wholeLine[i] == ' ';
		}
		//Use switch cases to find the proper input// 
		int position = 0;
		int position2 = 0;
		string firstNameTemp;
		string middleNameTemp;
		string lastNameTemp;
		deallocate();
		switch (spaceCounter)
		{
		case 0:
			set(wholeLine.c_str());
			istr.ignore(1000, '\n');
			break;
		case 1:
			position = wholeLine.find(" ");
			firstNameTemp = wholeLine.substr(0, position);
			lastNameTemp = wholeLine.substr(position + 1);
			set(firstNameTemp.c_str(), lastNameTemp.c_str());
			istr.ignore(1000, '\n');
			break;
		case 2:
			position = wholeLine.find(" ");
			position2 = wholeLine.find(" ", position + 1);
			firstNameTemp = wholeLine.substr(0, position);
			middleNameTemp = wholeLine.substr(position + 1, (position2-position-1));
			lastNameTemp = wholeLine.substr(position2 + 1);
			set(firstNameTemp.c_str(), middleNameTemp.c_str(), lastNameTemp.c_str());
			istr.ignore(1000, '\n');
			break;
		default:
			deallocate();
			break;
		}
		
		return istr;
	}

	std::ostream& Name::display(std::ostream& ostr)const{
		if (m_firstName && m_middleName && m_lastName) {
			ostr << m_firstName << " " << m_middleName << " " << m_lastName;
		}
		else if (!m_middleName && m_firstName && m_lastName) {
			ostr << m_firstName << " " << m_lastName;
		}
		else if (!m_middleName && !m_lastName && m_firstName) {
			ostr << m_firstName;
		}
		else if (!m_lastName&&m_firstName&&m_middleName){
			ostr << m_firstName<<" "<< m_middleName;
		}
		else {
			ostr << "Bad Name";
		}
		return ostr;
	}

	// set fn,ln and mn//
	Name& Name::set(const char* fN, const char* mN, const char* lN){
		set(fN, lN);
		delete[]m_middleName;
		m_middleName = new char[strlen(mN) + 1];
		strcpy(m_middleName, mN);
		return *this;
	}

	//Designed to set FN and LN //
	Name& Name::set(const char* FN, const char* LN){
		set(FN);
		delete[] m_lastName;
		m_lastName = new char[strlen(LN) + 1];
		strcpy(m_lastName, LN);
		return *this;
	}

	//Designed to set FN only//
	Name& Name::set(const char* FN){
		delete[]m_firstName;
		m_firstName = new char[strlen(FN) + 1];
		strcpy(m_firstName, FN);
		return *this;
	}

	// Queriers //
	Name::operator bool() {
		return m_firstName;
	}

	std::istream& operator>>(std::istream& istr, Name& name){
		return name.read(istr);
	}

	std::ostream& operator<<(std::ostream& ostr, const Name& name){
		return name.display(ostr);
	}
}