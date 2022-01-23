/* ------------------------------------------------------
Workshop 1 part 1

Module:   WordStat
Filename: Wordstat.cpp
Version:  1
Author:	  Zhaokai Guan

Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/

//This part is given by professor//

#include <iostream>
#include "cStrTools.h"
#include "Word.h"
using namespace std;
using namespace sdds;
int main() {
	char filename[256];
	programTitle();
	cout << "Enter filename: ";
	cin >> filename;
	wordStats(filename);
	return 0;
}
