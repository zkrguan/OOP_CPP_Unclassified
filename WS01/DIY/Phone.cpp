/* ------------------------------------------------------
Workshop 1 part 2

Module:   Phone
Filename: Phone.cpp
Version:  1
Author:   Zhaokai Guan

Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Phone.h"
#include "cStrTools.h"


namespace sdds {
	 // Use const to define the max amount of logs can be entered// 
	 const int MAX_LOG_SIZE = 50;
	 // Use this struct array to arrange store the data when reading the file//
	 phone_Logs log_Storage[MAX_LOG_SIZE] = { {0} };
	 // Read the file info from the txt file and store it at the same time//


	 // Functions definitions //
	 int readFiledata(const char* fileName) {
		  int record_counter = 0;
		  FILE* fptr = NULL;
		  fptr = fopen(fileName, "r");


		  if (fptr != NULL) {
				for (int i = 0; !feof(fptr); i++) {
					 fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", log_Storage[i].name, log_Storage[i].area_code, log_Storage[i].prefix_code, log_Storage[i].phone_number);
					 record_counter++;
				}
				fclose(fptr);
				fptr = NULL;
		  }

		  else {
				cout << fileName << " file not found!" << endl;
							  }

		  return(record_counter);
	 }


	 // print out the title of the program//
	 void displayTitle(const char* programTitle) {
		  cout << programTitle << " phone direcotry search" << endl;
		  cout << "-------------------------------------------------------" << endl;
	 }

	 void displayRecord(const phone_Logs* data, int* index_recorder, int match_counter) {

		  for (int i = 0; i < match_counter; i++)
		  {
				//Make it readable, split one statement into two//  
				cout << data[index_recorder[i]].name << ": (" << data[index_recorder[i]].area_code << ") ";
				cout << data[index_recorder[i]].prefix_code << "-" << data[index_recorder[i]].phone_number << endl;

		  }



	 }

	 void displayEndwords(const char* programTitle) {
		  cout << "Thank you for using " << programTitle << " directory." << endl;

	 }


	 // Simply prompt the user to search or exit//
	 void mainmenu(const phone_Logs* data, int total_record_num) {
		  int flag = 1;
		  do
		  {
				char user_input[MAX_NAME_SIZE] = { 0 };
				int search_index_recorder[MAX_LOG_SIZE] = { 0 };
				int match_counter = 0;
				cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
				cout << "> " ;
				cin >> user_input;

				if (strCmp(user_input, "!")) {
					 // Call the function to find//
					 for (int i = 0; i < total_record_num; i++) {

						  char temp_userinput_lower[MAX_NAME_SIZE] = { 0 };
						  toLowerCaseAndCopy(temp_userinput_lower, user_input);
						  char temp_Existing_names[MAX_NAME_SIZE] = { 0 };
						  toLowerCaseAndCopy(temp_Existing_names, data[i].name);
						  if (strStr(temp_Existing_names, temp_userinput_lower)) {
								search_index_recorder[match_counter] = i;
								match_counter++;
						  }

					 }

					 if (match_counter) {
						  // call the display record function// 
						  displayRecord(data, search_index_recorder, match_counter);
					 }

					 else {
						  // Purposely do nothing to meet the output from the example.
						  ;
					 }

				}

				else {
					 // Exit from the menu//
					 flag = 0;
				}

		  } while (flag);

	 }

	 // The last function and is the entry point of the program/ 
	 void phoneDir(const char* programTitle, const char* fileName) {

		  //Call program title function to print out the name of the program// 
		  displayTitle(programTitle);
		  //Call the read file function to scan and save the data from the file//
		  int total_records = 0;
		  total_records = readFiledata(fileName);
		  if (total_records) {
				//Call the menu function//
				mainmenu(log_Storage, total_records);
		  }
		  // print out the thank you words//
		  displayEndwords(programTitle);
	 }




}