// File Name: CharStack.h
//
// Author: Ayisha S.R. Sowkathali
// Date:12/06/2016
// Assignment Number: 6
// CS 2308.002 Fall 2016
// Instructor: Jill Seaman
//
// File contains the implementations for the CharStack class

#include<iostream>
#include<cassert>
#include "CharStack.h"
using namespace std;

//*****************************************************************************
// Constructor : creates an empty stack
//*****************************************************************************
CharStack::CharStack() {
     stackString = "";
}

//*****************************************************************************
// push : takes in a char 'x' and pushes onto the stack
//*****************************************************************************
void CharStack::push(char x) {
     assert(!isFull());  // will exit the program if stack is full
     stackString += x;
}

//*****************************************************************************
// pop : pops the top value from the stack
//*****************************************************************************
void CharStack::pop() {
     assert(!isEmpty()); // will exit the program if stack is empty
     stackString.erase(stackString.size()-1);
}

//*****************************************************************************
// peek : returns the top character from the stack
//*****************************************************************************
char CharStack::peek() {
     char top;
     top = stackString.at(stackString.length()-1);
     return top;
}

//*****************************************************************************
// isFull : return true if the stack is full, or false otherwise
//*****************************************************************************
bool CharStack::isFull() const {
     return false;
}

//*****************************************************************************
// isEmpty : returns true if the stack is empty, or false otherwise
//*****************************************************************************
bool CharStack::isEmpty() const {
     return stackString.empty();
}