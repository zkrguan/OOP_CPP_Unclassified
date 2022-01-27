/* ------------------------------------------------------
Workshop 2 part 1
Module:      Car
Filename:    Car.cpp
Version:     1
Author:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/

#include"cStrTools.h"
#include "Car.h"
#include <iostream>
#include <sstream>
using namespace std;


namespace sdds {
    //declare the file scope variables//
    int car_Array_size = 0;
    int allocation_Size = 0;
    Car* car_Ptr = nullptr;
    int car_Num = 0;
    

    // function definition //
    //Simply print out the title of the work//
    void VBPLE_Title() {
        cout << "Vehicle Border Passing Log Entry" << endl << "Enter the data in the following format:" << endl
            << "Make and model,LicensePlate,MilitaryTime<ENTER>" << endl << "Exit the program by entering the following:" << endl
            << "X,<ENTER>" << endl;
    }
    //Set those file scope values as instructed//
    void initialize(int allocSize) {
        car_Num = 0;
        allocation_Size = allocSize;
        car_Array_size = allocSize;
        car_Ptr = new Car[allocation_Size];
    }
    // For the future me
    // It is important to free the heap memory for the member of the car struct too// 
    void deallocate(Car& C) {     
        delete[] C.make_Model;
        C.make_Model = nullptr;
    }
    // Overloading the read function//
    bool read(Car& C) {
        // Declare some const values instead of pulling magic number out from no where.
        const int make_Model_str_size = 61;
        const int time_string_size = 5;

        bool flag = false;
        char temp_string_holder[make_Model_str_size]={0};
       
        read(temp_string_holder, make_Model_str_size, ',');
        if (strCmp(temp_string_holder, "X")) {
            char time_string[time_string_size] = { 0 };
            flag = true;
            // Missing that 1 extra space caused 2 hours debug for me
            // For the future me, always remember:
            // strLen won't return the size with the null terminator!!
            C.make_Model = new char[strLen(temp_string_holder)+1];
            strCpy(C.make_Model, temp_string_holder);
            read(C.license_Plate, license_Plate_size, ',');
            read(time_string, time_string_size);
            // used C++ method to convert str to int//
            stringstream intTime(time_string);
            intTime >> C.time;
        }

        else{
            flag = false;
        }
        return flag;
    }
    // Simply print out the member from the Car variable //
    void print(const Car& C) {
        cout << C.time << ": " << C.make_Model << "," << C.license_Plate << endl;
    }

    void record(const Car& C) {
        //A typical DMA practice
        //Beneficial to look back in the future
        if (car_Num==car_Array_size){
            // Allocate the memory, once allocate, must remember to delete//
            Car* temp = new Car[allocation_Size + car_Array_size];
            // Copy the val from the existing to the new//
            for (int i = 0; i < car_Array_size; i++){
                temp[i] = car_Ptr[i];
            }
            // delete the existing since it has been moved to new//
            delete[]car_Ptr;
            // make the ptr point to the new// 
            car_Ptr = temp;
            // Lastly increase the arr size tracker//
            car_Array_size += allocation_Size;

        }
        car_Ptr[car_Num] = C;
        car_Num++;
    }
    
    void endOfDay() {
        for (int i = 0; i < car_Num; i++){
            print(car_Ptr[i]);
            deallocate(car_Ptr[i]);
        }
        // For the future me
        // Always remember to delete the allocation 
        // And reset the pointer point to nullptr
        // This is like turning off the car and pull the handbrake when not driving
        delete[]car_Ptr;
        car_Ptr = nullptr;
    }


}