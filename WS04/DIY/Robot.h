/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 4 part 2
Course title:OOP244 NBB
Module:      Robot
Filename:    Robot.h
Version:     1
Author:	     Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Feb 10th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/

#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H
namespace sdds {
	class Robot {
		//attributes//
		char* m_Name;
		char* m_Location;
		double m_Weight;
		double m_Width;
		double m_Height;
		double m_Speed;
		bool   m_Depolyed;
		//modifer function//
		Robot& setSafeAndEmpty();
		void deallocate();



	public:
		// constructors and destructors//
		Robot();
		~Robot();
		Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool depolyment);

		//query functions are made under private so the client code won't be able to reach the data//
		char* getName() const;
		char* getLocation()const;
		bool  isDeployed() const;
		double getSpeed() const;


		//modifier functions//
		Robot& set(const char* name, const char* location, double weight, double width, double height, double speed, bool depolyment);
		Robot& setLocation(const char* newLocation);
		Robot& setDeployed(bool newStatus);
		// make it return a cout latter if we need it//
		void display() const;

		// The only query function should be public//
		bool isValid() const;





	};

	//the global function//
	int conrtolRooomReport(const Robot robot[], int num_robots);
	void displayReportTitle(int topspeed = 0);
	void displaySummary(int couter);
}

#endif // !SDDS_ROBOT_H