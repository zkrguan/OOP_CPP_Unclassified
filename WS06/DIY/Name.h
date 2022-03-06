/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 6 part 2
Course title:OOP244 NBB
Module:      Name
Filename:    Name.h
Version:     1
student:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Feb 15th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/
#ifndef SDDS_NAME_H
#define SDDS_NAME_H
namespace sdds{
	
	class Name{	
		char* m_firstName=nullptr;
		char* m_middleName=nullptr;
		char* m_lastName=nullptr; 
		// private methods //
		Name& setSafeAndEmpty();
		bool validateEmpty(const char* Name)const;
		void deallocate();
	public:
		// constructors //
		Name();
		Name(const char* firstName);
		Name(const char* firstName, const char* lastName);
		Name(const char* firstName, const char* middleName,const char* lastName);
		// rule of three //
		Name(const Name& copySrc);
		Name& operator =(const Name& asnFrom);
		~Name();
		// queriers//
		operator bool();
		// modifers//
		Name& setShort(bool flag);
		Name& operator += (const char* incomingString);
		std::istream& read(std::istream& istr);
		std::ostream& display(std::ostream& ostr)const;
		Name& set(const char* fN, const char* mN, const char* lN);
		Name& set(const char* FN, const char* LN);
		Name& set(const char* FN);
	};
	std::istream& operator >> (std::istream& istr, Name& name);
	std::ostream& operator << (std::ostream& ostr, const Name& name);
	
	


}

#endif // !SDDS_NAME_H

