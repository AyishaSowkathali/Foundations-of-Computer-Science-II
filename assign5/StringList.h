// File Name: StringList.h
//
// Author: Ayisha S.R. Sowkathali
// Psrtner: Sifaben Vahora
// Date: 11/17/2016
// Assignment Number: 5
// CS 2308.002 Fall 2016
// Instructor: Jill Seaman
//
// Represents a list of strings.
// Supports adding and removing strings, displaying and sorting strings,
// lookup and count of the number of strings in the list.

#include<iostream>
using namespace std;

class StringList
{
  private:
    struct StringNode          // the Nodes of the linked list
    {
        string data;           // data is a string
        StringNode *next;      // points to next node in list
    };
    
    StringNode *head;           // the head pointer
    
  public:
    StringList();
    ~StringList();
    
    int count();
    void add(string);
    bool remove(string);
    void display();
    bool lookup(string);
    void sort();
};
