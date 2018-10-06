// File Name: StringDriver.cpp
// 
// Author: Ayisha S.R. Sowkathali
// Date: 11/17/2016
// Assignment Number: 5
// CS 2308.002 Fall 2016
// Instructor: Jill Seaman
// 
// Main driver to implement an interface that manipulates a list of strings.

#include<iostream>
#include<iomanip>
using namespace std;

#include "StringList.h"

int main()
{
     //testing StringList
     StringList slist;
    
     string product1 = "Apple iPhone 3GS";
     string product2 = "Samsung Captivate SGH-I897";
     string product3 = "Blackberry RIM Bold 9930";
     string product4 = "Apple iPad 2 16GB WiFi";

     cout << endl;
     
     cout << "Testing add/display/count: " << endl;
     cout << "count is: " << slist.count() << endl;

     slist.add(product1);
     slist.display();
     cout << "count is: " << slist.count() << endl;
    
     slist.add(product2);
     slist.display();
     cout << "count is: " << slist.count() << endl;

     slist.add(product3);
     slist.add(product4);
     slist.display();
     cout << "count is: " << slist.count() << endl;

     cout << endl;
     
     cout << "Testing sort/display: " << endl;
     slist.sort();
     slist.display();
    
     cout << endl;
     cout << "Testing lookup: " << endl;
     cout <<"lookup(product1): " << boolalpha<< slist.lookup(product1)<< endl;
     cout <<"lookup(\"nothing\"): "<< boolalpha<<slist.lookup("nothing")<<endl;
     cout << endl;
     
     cout << "Testing remove: " << endl;
     bool delResult;
     delResult = slist.remove(product4);
     cout << "delete result product4 = " << boolalpha << delResult << endl;
  
     delResult = slist.remove(product3);
     cout << "delete result product3 = " << boolalpha << delResult << endl;

     delResult = slist.remove("Not There");
     cout << "delete result Not There = " << boolalpha << delResult << endl;

     slist.display();
     cout << "count is: " << slist.count() << endl;

     cout << endl;
     cout << "Testing add/sort/display after removal: " << endl;
     slist.add("Microsoft Surface");
     slist.display();
     cout << "now sorted: " << endl;
     slist.sort();
     slist.display();
     cout << endl;
}
