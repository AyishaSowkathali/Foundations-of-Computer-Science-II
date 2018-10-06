// File Name: CharStack.h
//
// Author: Ayisha S.R. Sowkathali
// Date:12/06/2016
// Assignment Number: 6
// CS 2308.002 Fall 2016
// Instructor: Jill Seaman
//
// Checks any text file for matching brackets

#include<iostream>
#include<fstream>
#include "CharStack.h"
using namespace std;

// function prototype
char matchBrackets(char);

int main() {
     
     //input the filename to check
     string fileName;
     cout << "Enter the name of a file to check: ";
     cin >> fileName;
     
     ifstream fin;
     fin.open(fileName.c_str());
     
     if (!fin) {
          cout << "Error, problem opening " << fileName << endl;
          return 0;
     }
     
     CharStack stack;
     char ch;
     char topBracket;
     bool flag = false;
     
     while (!flag && fin >> ch) {
          switch (ch) {
               case '{':
               case '(':
               case '[':
                    if (!stack.isFull()) {
                         stack.push(ch);
                    }
                    else {
                         cout << "!!Stack is full!!" << endl;
                         flag = true;
                    }
                    break;
               case '}':
               case ']':
               case ')':
                    if (!stack.isEmpty()) {
                         topBracket = stack.peek();
                         stack.pop();
                         if (topBracket == matchBrackets(ch)) {
                              // they match
                         } else {
                              cout << "Expected " << matchBrackets(topBracket)
                                   << " but found " << ch << endl;
                              flag = true;
                         }
                    } else {
                         cout << "Unmatched " << ch << endl;
                         flag = true;
                    }
                    break;
               default:
                    break;
          }
     }
     if (!flag) {
          if (!stack.isEmpty()) {
               stack.pop();
               topBracket = stack.peek();
               cout << "Missing " << matchBrackets(topBracket) << endl;
          } else {
               cout << "All bracket pairs were matched" << endl;
          }
     }
}

//*****************************************************************************
// matchBrackets : returns the matching bracket for a given bracket
//   ch : the bracket to provide the match for.
//*****************************************************************************
char matchBrackets(char ch) {
     switch (ch) {
          case '{': return '}';
          case '[': return ']';
          case '(': return ')';
          case '}': return '{';
          case ']': return '[';
          case ')': return '(';
     }
     return ch;
}