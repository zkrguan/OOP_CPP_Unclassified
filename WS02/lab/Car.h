#ifndef SDDS_CAR_H
#define SDDS_CAR
namespace sdds {

	 const int license_Plate_size = 9;

	 struct Car{
		  char license_Plate[license_Plate_size];
		  char* make_Model;
		  int time;
	 };

	 // Function prototypes//

	 //Simply print out the title and prompt the user to enter//
	 void VBPLE_Title();
	 // Prepare the data before the actual DMA implementation//
	 void initialize(int allocSize);
	 // Clean the memory//
	 void deallocate(Car& C);
	 // Overloaded function to read the info from the input buffer DMA involved//
	 bool read(Car& C);
	 // print out the car in a format//;
	 void print(const Car& C);
	 // Adding the info into the Car arr//
	 void record(const Car& C);
	 // Print and deallocate each member from the Car arr//
	 void endOfDay();
}

#endif // !SDDS_CAR_H
