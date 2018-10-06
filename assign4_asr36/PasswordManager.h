// File Name: passwordManager.h
//
// Author: Ayisha S.R. Sowkathali
// Date:11/01/2016
// Assignment Number: 4
// CS 2308.002 Fall 2016
// Instructor: Jill Seaman
//
// File contains the class declaration and specifications for the program

#include<string>
using namespace std;

class PasswordManager
{
private:
	string password;
	string encrypt(string) const;
	bool meetsCriteria(string) const;

public:
	void setEncryptedPassword(string);
	string getEncryptedPassword() const;
	bool setNewPassword(string);
     bool authenticate(string) const;
};