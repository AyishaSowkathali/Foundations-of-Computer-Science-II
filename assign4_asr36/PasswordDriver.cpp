// File Name: passwordDriver.cpp
//
// Author: Ayisha S.R. Sowkathali
// Date:11/01/2016
// Assignment Number: 4
// CS 2308.002 Fall 2016
// Instructor: Jill Seaman
//
// Program to manage passwords.
// This file contains the main function that links the header file
//   and its own .cpp file.

#include <iostream>
#include <fstream>
#include "PasswordManager.h"

const int SIZE=3;
const string DEFAULT_PW = "ABC123***";

bool validateNetID(int);
bool validateOPw(string);

int main()
{
     // Call for header file with an array of 3 instance
     PasswordManager pm[SIZE];
     
     int netID;
     string pw;          // password
     string encryptedPw; // encrypted password
     string oldPassword;
     string newPassword;
     bool check;
     
     ifstream fin;
     ofstream fout;
     
     // Opens and validates input file
     fin.open("password.txt");
     if (fin) {
          fin >> encryptedPw;
          for (int i=0; i<SIZE; i++) {
               pm[i].setEncryptedPassword(encryptedPw);
          }
     } else {
          for (int i=0; i<SIZE; i++) {
               pm[i].setNewPassword(DEFAULT_PW);
          }
     }
     fin.close();
     
     cout << "Please enter you netID: ";
     cin >> netID;
     if (validateNetID(netID)) {
          cout << "Please enter your old password: ";
          cin >> oldPassword;
          cout << "Please enter your new password: ";
          cin >> newPassword;
          check = pm[netID].setNewPassword(newPassword);
          if (!check) {
               cout << "New password does not meet criteria." << endl;
          }
          if (validateOPw(oldPassword)) {
               cout << "Password has been changed for netID: " <<
                    netID << endl;
          }
     }

     // Output file
     fout.open("password.txt");
     for (int i=0; i < SIZE; i++) {
          fout << pm[i].getEncryptedPassword() << endl;
     }
     fout.close();
     
     cout << endl;
     return 0;
}

/******************************************************************************
 validateNetID: takes in the netID as the argument, checks the condition and 
     returns true if the condition is satisfied and returns false otherwise
******************************************************************************/
bool validateNetID(int netID) {
     if (netID >= 0 && netID < 3) {
          return true;
     }
     cout << "NetID is invalid. Password not changed." << endl;
     return false;
     
}

/******************************************************************************
 validateOPw: takes in the oldPassword as argument and checks if the old 
     password equals to default password. Returns true if equal and false 
     otherwise.
******************************************************************************/
bool validateOPw(string oldPassword) {
     if (oldPassword != DEFAULT_PW) {
          cout << "Old password is incorrect." << endl;
          return false;
     }
     return true;
}