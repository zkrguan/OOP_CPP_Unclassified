#include"cStrTools.h"
#include "Car.h"
#include <iostream>
#include <sstream>
using namespace std;


namespace sdds {
    int car_Array_size = 0;
    int allocation_Size = 0;
    Car* car_Ptr = nullptr;
    int car_Num = 0;
    

    // function definition //
    void VBPLE_Title() {
        cout << "Vehicle Border Passing Log Entry" << endl << "Enter the data in the following format:" << endl
            << "Make and model,LicensePlate,MilitaryTime<ENTER>" << endl << "Exit the program by entering the following:" << endl
            << "X,<ENTER>" << endl;
    }

    void initialize(int allocSize) {
        car_Num = 0;
        allocation_Size = allocSize;
        car_Array_size = allocSize;
        car_Ptr = new Car[allocation_Size];
    }

    void deallocate(Car& C) {     
        delete[] C.make_Model;
        C.make_Model = nullptr;
    }

    bool read(Car& C) {
        bool flag = false;
        char temp_string_holder[61]={0};
       
        read(temp_string_holder, 61, ',');
        if (strCmp(temp_string_holder, "X")) {
            char time_string[5] = { 0 };
            flag = true;
            // Missing that 1 extra space caused 2 hours debug for me//
            C.make_Model = new char[strLen(temp_string_holder)+1];
            strCpy(C.make_Model, temp_string_holder);
            read(C.license_Plate, 9, ',');
            read(time_string, 5);
            // There could be better way//
            stringstream intTime(time_string);
            intTime >> C.time;
        }

        else{
            flag = false;
        }
        return flag;
    }

    void print(const Car& C) {
        cout << C.time << ": " << C.make_Model << "," << C.license_Plate << endl;
    }

    void record(const Car& C) {
        if (car_Num==car_Array_size){
            Car* temp = new Car[allocation_Size + car_Array_size];
            for (int i = 0; i < car_Array_size; i++){
                temp[i] = car_Ptr[i];
            }
            delete[]car_Ptr;
            car_Ptr = temp;
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
        delete[]car_Ptr;
        car_Ptr = nullptr;
    }


}