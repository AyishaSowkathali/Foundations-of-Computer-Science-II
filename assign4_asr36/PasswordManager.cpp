// File Name: passwordManager.cpp
//
// Author: Ayisha S.R. Sowkathali
// Date:11/01/2016
// Assignment Number: 4
// CS 2308.002 Fall 2016
// Instructor: Jill Seaman
//
// This file implements each member function of the class

#include "PasswordManager.h"

/******************************************************************************
 encypt: (a private function) takes a string and converts it to char to get 
     its ascii value and returns the encrypted string.
 pw - password
******************************************************************************/
string PasswordManager::encrypt(string pw) const {
	string encryptedPW;
	for(int i=0; i<pw.length(); i++) {
          char x = ((pw[i] - 33) + 15) % 94 + 33;
          encryptedPW += x;
	}
	return encryptedPW;
}

/******************************************************************************
 meetsCriteria:(a private functio) takes a string and verifies the password
     and returns true if it is same as what is asked for and returns false 
     otherwise.
******************************************************************************/
bool PasswordManager::meetsCriteria(string pw) const {
     const int PW_LENGTH = 8;
     int upperCase = 0;
     int aDigit = 0;
     
     if (pw.length() < PW_LENGTH) {
		return false;
     }
     
	for (int i=0; i < pw.length(); i++) {
          char p = pw.at(i);
		if (isupper(p))
			upperCase = 1;
		else if (isdigit(p))
			aDigit = 1;
	}
     
     if (upperCase == 1 && aDigit == 1) {
          return true;
     }
     return false;
}

/******************************************************************************
 setEncryptedPassword: (a setter function) takes a string (an encrypted 
     password) and stores it in the member variable.
******************************************************************************/
void PasswordManager::setEncryptedPassword(string pw) {
	password = pw;
}

/******************************************************************************
 getEncryptedPassword: (a getter function) returns the value of the encrypted
     password stored in the member variable
******************************************************************************/
string PasswordManager::getEncryptedPassword() const {
	return password;
}

/******************************************************************************
 setNewPassword: takes a string (a proposed password). If it meets the criteria 
     in verifyPassword, it encrypts the password and stores it in the member
     variable and returns true. Otherwise returns false.
******************************************************************************/
bool PasswordManager::setNewPassword(string pw) {
     bool valid;
     valid = meetsCriteria(pw);
	if (valid) {
		password = encrypt(pw);
		return true;
	} return valid;
}

/******************************************************************************
 authenticate: takes a string (a password) and returns true if, once encrypted, 
     it matches the encrypted string stored in the the member variable. Else 
     returns false.
******************************************************************************/
bool PasswordManager::authenticate(string pw) const {
	return (encrypt(pw) == password);
}