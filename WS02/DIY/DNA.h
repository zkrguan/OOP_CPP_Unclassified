/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 2 part 2
Module:      DNA
Filename:    DNA.h
Version:     1
Author:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/


#ifndef SDDS_DNA_H
#define SDDS_DNA

namespace sdds {
    // declare variables and struct
    const int arr_size = 2; // Changes to a bigger num after success
    const int size_Increment = 2;
    
    struct DNA {
    private:
        char* DNA_String;

    public:

        // function prototypes

        // Read the csv file and initialize the values for DMA//
        // the bool value will decide if the file opened successfully//
        bool beginSearch(const char* filename);

        // DMA function to create the DNA record arr,
        // True for record found
        bool read(const char* subDNA);

        // Sort the DMA arr based on ID num and in the ascending order//
        void sort();

        //Simply display the data based dynamic arr//
        void displayMatches();

        //deallocate the memory for DMA arr and its member//
        void deallocate();

        // End the program gracefully close .csv file 
        // Need to consider the other aspects too
        void endSearch();

    };




    


}


#endif // !SDDS_DNA_H
