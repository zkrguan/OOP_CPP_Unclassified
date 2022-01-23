/* ------------------------------------------------------
Workshop 1 part 2

Module:   Phone
Filename: Phone.h
Version:  1
Author:   Zhaokai Guan

Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H
namespace sdds {

	const int MAX_NAME_SIZE = 50;
	

	struct phone_Logs {
		char name [MAX_NAME_SIZE];
		char area_code[4];
		char  prefix_code[4];
		char  phone_number[7];
	};
	
	
	
	
	
	// function prototypes//
	
	// runs the phone directory appication
	void phoneDir(const char* programTitle, const char* fileName);
	// print out the title of the program//
	void displayTitle(const char* programTitle);
	// Read the file info from the txt file and store it at the same time
	// Return the number of records read by this funciton//
	int readFiledata(const char* fileName);
	//Display the matched record in a specific format//
	void displayRecord(const phone_Logs* transfered_data_from_txt, int* search_index_recorder,int match_counter);
	// The main menu of the program//
	void mainmenu(const phone_Logs* transfered_data_from_txt, int total_num_of_records);
	// Print out the thank you words//
	void displayEndwords(const char* programTitle);


}



#endif // !SDDS_PHONE_H

