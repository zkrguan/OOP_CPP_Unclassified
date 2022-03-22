/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 7 part 1
Course title:OOP244 NBB
Module:      Container
Filename:    Container.h
Version:     1
student:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Mar 15th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
namespace sdds {
	class Container{
		char m_content[50]{};
		int m_capacity{};
		int m_contentVolume{};
	public:
		Container(const char*srcContent, int srcCapacity=0);
		Container(const char*srcContent, int srcCapacity, int srcContentVolume);
	protected:
		Container& setEmpty() ;
		int capacity() const;
		int volume() const;
	public:
		virtual int operator += (int srcVolume);
		virtual int operator -=(int dstVolume);
		operator bool()const;
		void clear(const int capacity, const char* content);
		virtual std::ostream& print(std::ostream& ostr) const;
		virtual std::istream& read(std::istream& istr);
	};
	std::ostream& operator << (std::ostream& ostr, const Container& ctnerToPrint);
	std::istream& operator >> (std::istream& istr, Container& ctnerToSet);
}
#endif // !SDDS_CONTAINER_H