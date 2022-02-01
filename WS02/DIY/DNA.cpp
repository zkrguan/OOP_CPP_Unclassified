/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 2 part 2
Course title:OOP244 NBB
Module:      DNA
Filename:    DNA.cpp
Version:     1
Author:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Jan 29th 2022


Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "DNA.h"
#include "cStrTools.h"
using namespace std;

namespace sdds {
    const int storage_size_increment = 2;
    const int max_DNA_str_size = 1001;
    int storage_Arr_size = 2; 
    int matches_counter = 0;
    FILE* DNA_file_ptr = nullptr;
    DNA* matches_Storage = nullptr;
    
    bool beginSearch(const char* filename){
        DNA_file_ptr = fopen(filename, "r");
        return DNA_file_ptr ? true : false;
    }

    bool read(const char* subDNA) {
        // reset the counter and the temp_recorder every time when the function gets called//
        matches_counter = 0;
        storage_Arr_size = 2;
        int temp_DNA_num = 0;
        char temp_String_holder[max_DNA_str_size] = { 0 };
        matches_Storage = new DNA[storage_Arr_size];
        // Otherwise the search function can be only running once// 
        rewind(DNA_file_ptr);
        while (fscanf(DNA_file_ptr, "%d,%s\n", &temp_DNA_num,temp_String_holder) != EOF) {
            // Calling prof.'s cstrtools function "strStr"//
            // implement DMA for matches storage//
            if (strStr(temp_String_holder,subDNA)){
                if (matches_counter==storage_Arr_size){
                    DNA* temp_holder = new DNA[storage_Arr_size+storage_size_increment];
                    for (int i = 0; i < storage_Arr_size; i++){
                        temp_holder[i] = matches_Storage[i];
                    }
                    delete[] matches_Storage;
                    matches_Storage = temp_holder;
                    storage_Arr_size += storage_size_increment;
                }
                matches_Storage[matches_counter].DNA_Num = temp_DNA_num;
                // Calling prof.'s cstrtools functions strLen and strCpy//
                matches_Storage[matches_counter].DNA_String = new char[strLen(temp_String_holder)+1];
                strCpy(matches_Storage[matches_counter].DNA_String, temp_String_holder);
                matches_counter++;
            }
        }
        return matches_counter ? true : false;
    }

    void sort() {
        // using the traditional bubble sort learned from last year to acomplish this//
        int i, j;
        DNA temp = {0};
        // Will not use i to access each element. //
        // i is more like a round counter in order to run enough times for the sorting..//
        for ( i = matches_counter-1; i > 0 ; i--){
            // each round, j will access every arr element to compare from the left to the right// 
            for ( j = 0; j < i; j++){
                // if the left element is bigger than the one from right//
                // shift it to the right by one index//
                if (matches_Storage[j].DNA_Num > matches_Storage[j + 1].DNA_Num) {
                    temp.DNA_Num = matches_Storage[j].DNA_Num;
                    matches_Storage[j].DNA_Num = matches_Storage[j + 1].DNA_Num;
                    matches_Storage[j + 1].DNA_Num = temp.DNA_Num;
                }
            }
        }
    }

    // Simply display the matches records//
    void displayMatches() {
        for (int i = 0; i < matches_counter; i++){
            cout << i + 1 << ") " << matches_Storage[i].DNA_Num << ":" << endl;
            cout << matches_Storage[i].DNA_String << endl;
            cout << "======================================================================" << endl;
        }

    }

    // Not only deallocate the struct arr, but also deallocate each member from each arr element//
    void deallocate() {
        if (matches_counter){
            for (int i = 0; i < matches_counter; i++) {
                delete[] matches_Storage[i].DNA_String;
                matches_Storage[i].DNA_String = nullptr;
            }
            delete[] matches_Storage;
            matches_Storage = nullptr;
        }
    }

    // fclose file ptr and set it as nullptr to exit gracefully//
    void endSearch() {
        fclose(DNA_file_ptr);
        DNA_file_ptr = nullptr;
        cout << "DNA Search Program Closed." << endl;
    }

}