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
    const int DNA_Str_arr_increment = 20;
    const int storage_size_increment = 2;
    int DNA_Str_arr_size = 20;
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
        DNA temp_data_recorder = { {0} };
        matches_Storage = new DNA [storage_Arr_size];
        // Otherwise the search function can be only running once// 
        rewind(DNA_file_ptr);

        while (fscanf(DNA_file_ptr, "%d,", &temp_data_recorder.DNA_Num)!=EOF){
            bool read_str_crtl = true;
            temp_data_recorder.DNA_String = new char[DNA_Str_arr_size];
            // implement DMA for string recording //
            for (int i = 0;read_str_crtl; i++){
                if (i == (DNA_Str_arr_size - 1)) {
                    char* temp_Str_arr = new char[DNA_Str_arr_size + DNA_Str_arr_increment];
                    for (int j = 0; j < i; j++) {
                        temp_Str_arr[j] = temp_data_recorder.DNA_String[j];
                    }
                    delete[] temp_data_recorder.DNA_String;
                    temp_data_recorder.DNA_String = temp_Str_arr;
                    DNA_Str_arr_size += DNA_Str_arr_increment;
                }
                fscanf(DNA_file_ptr, "%c", &temp_data_recorder.DNA_String[i]);
                if (temp_data_recorder.DNA_String[i]=='\n'){
                    temp_data_recorder.DNA_String[i] = '\0';
                    read_str_crtl = false; 
                }
            }
            // citation (1): Calling prof.'s cstrtools function in the if condition//
            // implement DMA for matches storage//
            if (strStr(temp_data_recorder.DNA_String,subDNA)){
                if (matches_counter==storage_Arr_size){
                    DNA* temp_holder = new DNA[storage_Arr_size+storage_size_increment];
                    for (int i = 0; i < storage_Arr_size; i++){
                        temp_holder[i] = matches_Storage[i];
                    }
                    delete[] matches_Storage;
                    matches_Storage = temp_holder;
                    storage_Arr_size += storage_size_increment;
                }
                matches_Storage[matches_counter] = temp_data_recorder;
                matches_counter++;
            }
        }
        return matches_counter ? true : false;
    }

    void sort() {
        // using the traditional bubble sort learned from last year to acomplish this//
        int i, j;
        DNA temp = {{0}};
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
        for (int i = 0; i < matches_counter; i++){
            delete[] matches_Storage[i].DNA_String;
            matches_Storage[i].DNA_String = nullptr;            
        }
        delete[] matches_Storage;
        matches_Storage = nullptr;
    }

    // fclose file ptr and set it as nullptr to exit gracefully//
    void endSearch() {
        
        fclose(DNA_file_ptr);
        DNA_file_ptr = nullptr;
        cout << "DNA Search Program Closed." << endl;
    }

}