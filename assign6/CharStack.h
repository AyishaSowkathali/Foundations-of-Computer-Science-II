// File Name: CharStack.h
//
// Author: Ayisha S.R. Sowkathali
// Date:12/06/2016
// Assignment Number: 6
// CS 2308.002 Fall 2016
// Instructor: Jill Seaman
//
// File contains the class declaration and specifications for the
//   CharStack class

#include <string>
using namespace std;

class CharStack
{
private:
    string stackString;
    
public:
    CharStack();    // Constructor
    
    // Stack operations
    void push(char);
    void pop();      //removes top character
    char peek();     //returns top character without removing it
    bool isFull() const;
    bool isEmpty() const;
};
