/* ------------------------------------------------------
Workshop 2 part 1
Module:      cStrTools
Filename:    cStrTools.h
Version:     1
Author:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/


#ifndef SDDS_CSTRTOOLS_H
#define SDDS_CSTRTOOLS
namespace sdds {
	// function prototypes//
	// Using asiic num to determine and swap the letter from upper to lower//
	char toLower(char ch);
	// Compare two strings and return an int value to indicate the result//
	int strCmp(const char* s1, const char* s2);
	// Compare two strings upto certain length of the characters and return a int//
	int strnCmp(const char* s1, const char* s2, int len);
	// if the string find is found in the string str, it will return the address
	// of the match. Otherewise it will return a nullptr.
	const char* strStr(const char* str, const char* find);
	//copy the string from source (src) to the destination (des)//
	void strCpy(char* des, const char* src);
	// it will return the length of the str//
	int strLen(const char* str);
	// return 1 if the ch is alphabetical letter, otherwise it will return a 0//
	int isAlpha(char ch);
	// return 1 if ch is a white space character, otherwise it will return a 0//
	int isSpace(char ch);
	// remove the non-alphabetical characters from the begining and the end of a word//
	void trim(char word[]);
	//copies the lower case version of the source into the destination string// 
	void toLowerCaseAndCopy(char des[], const char source[]);
	// Function given by professor for WS02P1
	void read(char* cString, unsigned int maxSize, char delimiter='\n');
	
}



#endif // SDDS_CSTRTOOLS_H

