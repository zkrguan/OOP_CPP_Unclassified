#ifndef SDDS_CAR_H
#define SDDS_CAR
namespace sdds {

	 struct Car{
		  char license_Plate[9];
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


}

#endif // !SDDS_CAR_H
