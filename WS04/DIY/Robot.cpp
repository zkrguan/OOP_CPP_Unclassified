/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 4 part 2
Course title:OOP244 NBB
Module:      Robot
Filename:    Robot.cpp
Version:     1
Author:	     Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Feb 10th 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
#include "Robot.h"

using namespace std;

namespace sdds {


   // constructors and destructors//
   Robot::Robot() {
      setSafeAndEmpty();
   }

   Robot::~Robot() {
      deallocate();
   }

   Robot::Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool status) {
      setSafeAndEmpty().set(name, location, weight, width, height, speed, status);
   }


   //private functions//
   //query functions//
   char* Robot::getName() const
   {
      return m_Name;
   }

   char* Robot::getLocation() const
   {
      return m_Location;
   }

   bool Robot::isDeployed() const
   {
      return m_Depolyed;
   }

   double Robot::getSpeed() const
   {
      return m_Speed;
   }

   Robot& Robot::setSafeAndEmpty(){
      /* safeand empty defined by Zhaokai
         all the char pointers are equal to nullptr
         weight, width, height are equal to -10;
         speed equals to 0.0;
         depolyment status equals to false
      */
      m_Name = nullptr;
      m_Location = nullptr;
      m_Weight = -10;
      m_Width = -10;
      m_Height = -10;
      m_Speed = 0.0;
      m_Depolyed = false;
      return *this;
   }

   void Robot::deallocate(){
      delete[] m_Name;
      delete[] m_Location;
      setSafeAndEmpty();
      // or we call setSafe and empty???//
   }

  
   // public functions//
   // query function //
   
   bool Robot::isValid() const{
      return m_Speed>0;
   }
   void Robot::display() const{
     /* cout << "| ";
      cout.width(11);
      cout.setf(ios::left);
      cout << "Robot ID";
      cout << "| ";
      cout.width(16);
      cout << "Location";
      cout << "| ";
      cout.width(7);
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout << "Weight";
      cout << " |  ";
      cout.width(5);
      cout << "Width";
      cout << " | ";
      cout.width(5);
      cout << "Height";
      cout << " |  ";
      cout.width(5);
      cout << "Speed";
      cout.unsetf(ios::right);
      cout.unsetf(ios::fixed);
      cout << " | ";
      cout.width(7);
      cout << "Deployed";
      cout << " |" << endl;*/
      cout << "| ";
      cout.setf(ios::left);
      cout.width(11);
      cout << m_Name;
      cout << "| ";
      cout.width(16);
      cout << m_Location;
      cout << "| ";
      cout.width(6);
      cout.unsetf(ios::right);
      cout.setf(ios::right);
      cout.precision(1);
      cout.setf(ios::fixed);
      cout << m_Weight;
      cout << " |";
      cout.width(7);
      cout << m_Width;
      cout << " |";
      cout.width(7);
      cout << m_Height;
      cout << " |";
      cout.width(7);
      cout << m_Speed;
      cout.unsetf(ios::right);
      cout.unsetf(ios::fixed);
      cout << " | ";
      cout.width(8);
      cout << (m_Depolyed ? "YES" : "NO");
      cout << " |" << endl;
   }



   // modifer functions//

   Robot& Robot::set(const char* name, const char* location, double weight, double width, double height, double speed, bool depolyment){
    // start DMA//
      deallocate();
      m_Name = new char[strlen(name) + 1];
      strcpy(m_Name, name);
      m_Location = new char[strlen(location) + 1];
      strcpy(m_Location, location);
      m_Weight = weight;
      m_Width = width;
      m_Height = height;
      m_Depolyed = depolyment;
      m_Speed = speed;
      return *this;
   }

   Robot& Robot::setLocation(const char* newLocation){
      delete[] m_Location;
      m_Location = new char [strlen(newLocation) + 1];
      strcpy(m_Location, newLocation);
      return *this;
   }




   Robot& Robot::setDeployed(bool newStatus){
      m_Depolyed = newStatus;
      return *this;
   }





   



   // global function //
   void displayReportTitle(int topspeed) {  
      if (!topspeed) {
         cout << "                        ------ Robot Control Room -----" << endl;
         cout << "                    ---------------------------------------" << endl;
      }
      cout << "| ";
      cout.width(11);
      cout.setf(ios::left);
      cout << "Robot ID";
      cout << "| ";
      cout.width(16);
      cout << "Location";
      cout << "| ";
      cout.width(6);
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout << "Weight";
      cout << " |  ";
      cout.width(5);
      cout << "Width";
      cout << " | ";
      cout.width(5);
      cout << "Height";
      cout << " |  ";
      cout.width(5);
      cout << "Speed";
      cout.unsetf(ios::right);
      cout.unsetf(ios::fixed);
      cout << " | ";
      cout.width(7);
      cout << "Deployed";
      cout << " |" << endl;
      cout << "|------------+-----------------+--------+--------+--------+--------+----------|"<<endl;
   }

   void displaySummary(int couter){
      cout << "|=============================================================================|"<<endl;
      cout << "| SUMMARY:";
      cout.setf(ios::right);
      cout.width(69);
      cout << "|" << endl;
      cout << "| " << couter << "  " << "robots are deployed.";
      cout.width(54);
      cout << "|" << endl;
      cout << "| The fastest robot is:";
      cout.width(56);
      cout << "|" << endl;
      cout.unsetf(ios::right);


   }


   int conrtolRooomReport(const Robot robot[], int num_robots){
      int result = 0;
      int deploymnet_couter = 0;
      int top_speed_index = 0;
      displayReportTitle();

      for (int i = 0; i < num_robots && robot[i].isValid();i++) {
         robot[i].display();
         deploymnet_couter += robot[i].isDeployed();
         top_speed_index = (robot[top_speed_index].getSpeed()<robot[i].getSpeed()) ? i : top_speed_index;
         result = i;
      }
      if (result){
         result++;
      }
      if ((result)==num_robots){
         displaySummary(deploymnet_couter);
         displayReportTitle(top_speed_index);
         robot[top_speed_index].display();
         cout << "|=============================================================================|"<<endl;

      }
      int flag = 0;
      return flag = (result == num_robots) ? -1 : result;
   }

   

}