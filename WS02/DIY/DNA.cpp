/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 2 part 2
Module:      DNA
Filename:    DNA.cpp
Version:     1
Author:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
#include "DNA.h"

namespace sdds {
    

    // fopen, rewind or not? 
    // DMA for DNA arr,
    // DMA for DNA char string
    bool DNA::beginSearch(const char* filename){
        bool result = false;
        // Setting ini vals, build another function? //
        DNA* matches_Storage = nullptr;
        int matches_counter = 0;
        FILE* fp = nullptr;
        fp = fopen(filename, "r");
        if (fp){  
            result = true;
        }
        else{
            // Display the error message before the program exits//
            cout << "If this line shows, there must be an error during the fopen or the file name is wrong" << endl;
        }
        return result;
    }



    // conduct the search for loop /and only keep the matches  
    // str str to achieve the search?
    // fscanf to accept read the file??
    // Then store the text into the temp 
    // Then check?
    bool read(const char* subDNA) {
        bool result = false;
        while (!EOF){
                    

        }
       
        

    }

}