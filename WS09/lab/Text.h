/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 9 part 1
Course title:OOP244 NBB
Module:      Text
Filename:    Text.h
Version:     1
student:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Mar 15th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/
#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

namespace sdds {
	class Text{
	private:
		char* m_content{};
	protected:
		const char& operator[](int index) const;
	public:
		Text() {};
		Text(Text& src);
		Text& operator = (const Text& src);
		std::istream& read(std::istream& istr);
		int getFileLength(std::istream& is);
		virtual std::ostream& write(std::ostream& ostr) const;
		unsigned contentLength() const;
		virtual ~Text();
	};
	std::istream& operator >> (std::istream& istr, Text& readOn);
	std::ostream& operator << (std::ostream& ostr, const Text& srcFrom);


}
#endif // !SDDS_TEXT_H
