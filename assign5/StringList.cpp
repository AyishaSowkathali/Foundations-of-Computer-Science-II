// File Name: StringList.cpp
//
// Author: Ayisha S.R. Sowkathali
// Partner: Sifaben Vahora
// Date: 11/17/2016
// Assignment Number: 5
// CS 2308.002 Fall 2016
// Instructor: Jill Seaman
//
// Implementation of the functions  

#include "StringList.h"
using namespace std;

//*****************************************************************************
// StringList : Constructor that takes an argument and dynamically allocates
//    all the nodes in the list.
//*****************************************************************************
StringList::StringList() {
	head = nullptr;
}

//*****************************************************************************
// StringList : Destructor that deletes the pointer of the node created by the
//     contructor.
//*****************************************************************************
StringList::~StringList() {
	StringNode *p;
	StringNode *n;

	p = head;

	while (p) {
		n = p->next;
		delete p;
		p = n;
	}
}

//*****************************************************************************
// count : keeps track of the number of products added into the list.
//*****************************************************************************
int StringList::count() {
	int count = 0;

	StringNode *p;
	StringNode *n;

	p = head;

	while (p) {
		n = p->next;
		count++;
		p = n;
	}
	return count;
}

//*****************************************************************************
// add : adds product to the string list
// product : name of the products from the main drive
//*****************************************************************************
void StringList::add(string product) {
	StringNode *newNode = new StringNode(); //adding new node to the string
	newNode->data = product;
	newNode->next = head;
	head = newNode;
}

//*****************************************************************************
// display : shows all products from the list
//*****************************************************************************
void StringList::display() {
	StringNode *p;
	p = head;
	while (p) {
		cout << p->data << endl;
		p = p->next;
	}
}

//*****************************************************************************
// lookup : locates the product from the list
//*****************************************************************************
bool StringList::lookup(string product) {

	StringNode *p;
	StringNode *n;

	p = head;

	while (p) {
		n = p->next;
		if (p->data == product) {
			return true;
		}
		p = n;
	}

	return false;
}

//*****************************************************************************
// remove : removes the specified product from the list
//*****************************************************************************
bool StringList::remove(string product) {
	StringNode *p = head;
	StringNode *prev = nullptr;

	while (p) {
		if (p->data == product) {
			if (p == head)
				head = p->next;
			else
				prev->next = p->next;
			delete p;
			return true;
		}
		prev = p;
		p = p->next;
	}
	return false;
}

//*****************************************************************************
// sort : sorts the product from the list alphebatically.
//*****************************************************************************
void StringList::sort() {

	//     StringNode *newNode = new StringNode;
	//
	//     for (StringNode *p = head; p->next != NULL; p = p->next) {
	//          // compare to the list ahead
	//          for (newNode = p->next; newNode != NULL; newNode = newNode->next) {
	//               if (newNode->data < p->data) {
	//                    StringNode *temp = new StringNode;
	//                    temp->data = newNode->data;
	//                    newNode->data = p->data;
	//                    p->data = temp->data;
	//               }
	//          }
	//     }

	StringNode *newHead = NULL;   // the head of the new list

	while (head)   // repeats until the original list is empty
	{
		// removes the first node
		StringNode *newNode = head;   // call it new node for insertion
		head = head->next;

		// to find the first node with a larger value in the newlist
		StringNode *p = newHead; // current node, first node of the list
		StringNode *prev = NULL; // previous node, nothing in it for now

		while (p != NULL && newNode->data > p->data) {
			prev = p; // save the current node address
			p = p->next;   // advance current node to next
		}

		// insert into the newlist
		if (prev == NULL) { // p must be pointing to the first node
			newHead = newNode;
			newNode->next = p;
		} else {  // when prev is not null
			prev->next = newNode;
			newNode->next = p;
		}
	}
	head = newHead;
}

