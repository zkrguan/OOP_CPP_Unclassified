#include"cStrTools.h"
#include "Car.h"
#include <iostream>
using namespace std;


namespace sdds {
    int car_Array_size = 2;
    int allocation_Size = 3;
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
        


        delete[]car_Ptr->make_Model;
        car_Ptr->make_Model = nullptr;

    }

    bool read(Car& C) {
        bool flag = false;
        char temp_string_holder[61]={0};
       
        // problem might come from this line, overloading??? right???///
        read(temp_string_holder, 60, ',');
        if (!(strCmp(temp_string_holder, "X"))) {
            flag = true;
            C.make_Model = new char[allocation_Size];
            C.make_Model = temp_string_holder;
            // might be extra, shall be tested by the debugger//
            C.make_Model[strLen(temp_string_holder) + 1] = '\0';
            read(C.license_Plate, 9, ',');
           
        }

    }
}