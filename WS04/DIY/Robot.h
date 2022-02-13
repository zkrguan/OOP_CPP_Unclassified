/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 4 part 2
Course title:OOP244 NBB
Module:      Robot
Filename:    Robot.h
Version:     1
Author:	    Zhaokai Guan
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
		//Private functions//
		Robot& setSafeAndEmpty();
		void deallocate();

	public:
		//constructors and destructors//
		Robot();
		~Robot();
		Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool depolyment);

		//query functions//
		char* getName() const;
		char* getLocation()const;
		bool  isDeployed() const;
		double getSpeed() const;
		bool isValid() const;
		void display() const;

		//modifier functions//
		Robot& set(const char* name, const char* location, double weight, double width, double height, double speed, bool depolyment);
		Robot& setLocation(const char* newLocation);
		Robot& setDeployed(bool newStatus);
	};

	//the global functions//
	int conrtolRooomReport(const Robot robot[], int num_robots);
	void displayReportTitle(int topspeed = 0);
	void displaySummary(int couter);
}

#endif // !SDDS_ROBOT_H