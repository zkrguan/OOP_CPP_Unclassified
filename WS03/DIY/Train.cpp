/* ------------------------------------------------------
I have done all the coding by myself and
only copied the code that my professor provided
to complete my workshops and assignments.

Workshop 3 part 2
Course title:OOP244 NBB
Module:      Train
Filename:    Train.cpp
Version:     1
Author:	    Zhaokai Guan
Student Num: 130988215
Email:       zguan25@myseneca.ca
Date:        Feb 2nd 2022

Revision History
-----------------------------------------------------------
Date:   Reason:
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include"Train.h"
using namespace std;

namespace sdds{
 
    void Train::set(const char* name, int ppl, double speed) {
       /* Safe and empty defined by Zhaokai :

          string m_Train_Name's first element is null terminator.

          int m_ppl_On_Board equals to -2 ( do not make any sense in reality.

          double m_train_Speed equals to -320.5 ( even when the train is reversing, the speed
            can not reach that fast)
       */
       if ((name && strlen(name))&& (ppl >= 0 && ppl <= MAX_PEOPLE) && (speed >= 0 && speed <= MAX_SPEED)) {
          strncpy(m_train_Name, name, MAX_NAME_LENGTH);
          m_ppl_On_Board = ppl;
          m_train_Speed = speed;
       }
       //Even one of the data does not meet the criteria, the whole thing will be set to safe and empty//
       else {
          m_train_Name[0] = 0;
          m_ppl_On_Board = -2;
          m_train_Speed = -320.5;
       }
    }
    
    int Train::getNumberOfPeople() const{
       return m_ppl_On_Board;
    }
    
    const char* Train::getName() const{
       return m_train_Name;
    }
    
    double Train::getSpeed() const{
       return m_train_Speed;
    }

    // function actually just checking not setting.//
    bool Train::isSafeEmpty() const{
       /* Safe and empty defined by Zhaokai :

          string m_Train_Name's first element is null terminator.

          int m_ppl_On_Board equals to -2 ( do not make any sense in reality.

          double m_train_Speed equals to -320.5 ( even when the train is reversing, the speed
            can not reach that fast)
       */
       return !(m_train_Name[0]) && m_ppl_On_Board == -2 && m_train_Speed == -320.5 ? true : false;
    }
    void Train::display() const{
       if (isSafeEmpty()){
          cout << "Safe Empty State!" << endl;
       }
       // if it is not safe and empty print out the detail info//
       else{
          cout << "NAME OF THE TRAIN : " << m_train_Name << endl;
          cout << "NUMBER OF PEOPLE  : " << m_ppl_On_Board << endl;
          cout.setf(ios::fixed);
          cout.precision(2);
          cout << "SPEED             : " << m_train_Speed <<" km/h" << endl;
       }
    }

    bool Train::loadPeople(int peopleInput){
       bool res = true;
       if (isSafeEmpty()){
          res = false;
       }
       
       else{
          // declare another variable to make it readble, instead of having long conditions/
          int total_ppl = 0;
          total_ppl = m_ppl_On_Board + peopleInput;
          //when the people m_ppl_On_Board + peopleInput in the range//
          if (total_ppl <=MAX_PEOPLE && total_ppl >=0){
             m_ppl_On_Board += peopleInput;
          }
          //m_ppl_On_Board + peopleInput less then 0, then the ppl on board will be 0//
          else if(total_ppl <0){
             m_ppl_On_Board = 0;
          }
          // m_ppl_On_Board + peopleInput more than max people, then the ppl on board will be at max//
          else if (total_ppl >MAX_PEOPLE){
             m_ppl_On_Board = MAX_PEOPLE;
          }
          
       }
       return res;
    }

    // Same desgin as load ppl//
    bool Train::changeSpeed(double speed_input){
       bool res = true;
       if (isSafeEmpty()){
          res = false;
       }
       else{
          if (m_train_Speed+speed_input>=0&&m_train_Speed+speed_input<=MAX_SPEED){
             m_train_Speed += speed_input;
          }
          else if (m_train_Speed + speed_input < 0){
             m_train_Speed = 0;
          }
          else if (m_train_Speed + speed_input > MAX_SPEED) {
             m_train_Speed = MAX_SPEED;
          }

       }
       return res;
    }

    int transfer(Train&dst_train, Train& src_train){
       int res = 0;
       // if two trains both are not in the safe and empty, transfer process will happen//
       if (!src_train.isSafeEmpty() && !dst_train.isSafeEmpty()){
          if (src_train.getNumberOfPeople() + dst_train.getNumberOfPeople()<=MAX_PEOPLE){
             int actual_transfer = 0;
             dst_train.loadPeople(src_train.getNumberOfPeople());
             actual_transfer = src_train.getNumberOfPeople();
             src_train.loadPeople(-(src_train.getNumberOfPeople()));
             res = actual_transfer;
          }
          
          else{
             int actual_transer = 0;
             actual_transer = MAX_PEOPLE - dst_train.getNumberOfPeople();
             dst_train.loadPeople(actual_transer);
             src_train.loadPeople(-actual_transer);
             res = actual_transer;
          }

       }
       else{
          // Returns -1 to indicate the process did not happen//
          res = -1;
       }
       // first check both trains
       return res;
    }

}