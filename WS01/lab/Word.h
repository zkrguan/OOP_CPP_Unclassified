/* ------------------------------------------------------
Workshop 1 part 1

Module:   Word
Filename: Word.h
Version:  1
Author:	  Zhaokai Guan 

Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/

#ifndef SDDS_WORD_H
#define SDDS_WORD_H

namespace sdds {
    // because the class Word needs this const, so it has to be in the header//
    const int MAX_WORD_LEN = 21; 
    // the struct needed for the functions from Word.cpp file//
    struct Word {
        char letters[MAX_WORD_LEN];
        int count;
    };
    // function prototypes//
    // This function will return a index of the word array, otherwise the index would be -1//
    int searchWords(const Word words[], int num, const char word[]);
    // This function is made for reading the file//
    int readWord(char* word, FILE* fptr, int maxLen);
    // This function is made to store the newitem into the Word arr//
    void addWord(Word words[], int* index, const char newWord[]);
    // Simply print out the title//
    void title(const char* value, int len);
    // print out some important facts about the of file//
    void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
    // print out the count of the letter and letters//
    void print(const Word* w, int gotoNextLine, int len);
    // this will find the longest of the string from the word arr//
    int findMaxLen(const Word words[], int noOfWords);
    // This will print out the title of the file and find the longest of the word// 
    void listWords(const Word words[], int noOfWords, const char* theTitle);
    // made for swaping 2 word arr's address, useful for sorting function//
    void swap(Word* p1, Word* p2);
    // Sort the word arr in the occurance order or alphabetical order//
    void sort(Word words[], int cnt, int sortType);
    // sum up the count under the class Word//
    int totalCount(const Word* words, int num);
    // intergrate the above functions and generate some stats info// 
    void wordStats(const char* filename);
    // Simply print out the title//
    void programTitle();

}



#endif // SDDS_WORD_H

