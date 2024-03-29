/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 2 part 2
Course title:OOP244 NBB
Module:      DNA
Filename:    DNA.h
Version:     1
Author:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Jan 29th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/
#ifndef SDDS_DNA_H
#define SDDS_DNA

namespace sdds {
  
    struct DNA {
        int DNA_Num;
        char* DNA_String;
    };
    // function prototypes
     
    // the bool value will decide if the file opened successfully//
    bool beginSearch(const char* filename);
    // Implemented DMA//
    // Return true for record found
    bool read(const char* subDNA);
    // Sort the DMA arr based on ID num and in the ascending order//
    void sort();
    //Simply display the data based dynamic arr//
    void displayMatches();
    //deallocate the memory for DMA arr and its member//
    void deallocate();
    // End the program gracefully close .csv file 
    void endSearch();
}
#endif // !SDDS_DNA_H
