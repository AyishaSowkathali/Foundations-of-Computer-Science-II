
// File Name: assign1_asr36
//
// Author: Ayisha S. R. Sowkathali
// Partner: Sifaben Vahora
// Date: 9/13/2016
// Assignment Number: 1
// CS 2308.002 Fall 2016
// Instructor: Jill Seaman
//
// This program shows menu of a cafe, takes in order and
//  shows the receipt.

#include<iostream>
#include<iomanip>
using namespace std;

const int NUM_CHOICES = 50;   // limitation for orders
const int NUM_ITEMS = 5;      // Number of items in the menu

struct menu {
     string name;   // names of the items
     double cost;   // cost of the items
};

//function prototypes
void showMenu(menu[]);
void getOrder(int []);
void printCheck(menu[], int[]);

int main()
{
     int choice[NUM_ITEMS]; // Array to store the choices entered
     menu itemInfo[NUM_ITEMS] = {{"Cheeseburger", 2.65},
                                   {"Hamburger", 2.25},
                                   {"French Fries", 1.35},
                                   {"Coke", 1.75},
                                   {"Beer", 3.00}};
     
     cout << fixed << setprecision(2) << endl;
     
     showMenu(itemInfo);
     
     getOrder(choice);
     
     printCheck(itemInfo, choice);

     cout << endl;
     
return 0;
}

/********************************************************************
 showMenu - reads the structure array and displays it as an output
 ********************************************************************/
void showMenu (menu items[]) {
     
     cout << "Burger Cafe Menu" << endl;
     for (int i=0; i<NUM_ITEMS; i++) {
          cout << left << setw(3) << i+1
          << setw(20) << items[i].name
          << setw(15) << items[i].cost << endl;
     }
     cout << endl;
}

/********************************************************************
 getOrder - gets the number of choices from the user and stores it in 
     the array 'choice[]'
 ********************************************************************/
void getOrder(int choice[]) {
     
     int sum = 0;
     
     cout << "Make your selections by number." << endl;
     cout << "Enter a number more than once to place multiple orders."
          << endl;
     cout << "When you are done, type 0." << endl;
     cout << endl;
     
     for (int i=0; i<NUM_CHOICES; i++){
          cin >> choice[i];
          sum += choice[i];
          if ((choice[i] <=0)||(choice[i]>5)) {
               break;
          }
     }
     if(sum >= NUM_CHOICES) {
          cout << "!!Warning!!";
          cout << "\nCustomer choice exceeded more than 50 !!" << endl;
     }
     cout << endl;
}

/********************************************************************
 printCheck - reads the structure array from main and the choice array through main from getOrder function.
     it calculates the total cost and taxrate and displays the receipt for the order.
 ********************************************************************/
void printCheck(menu itemInfo[], int choice[]) {
     
     double taxRate = 0.08;
     double tax = 0.0;
     double subTotal = 0.0;
     double total = 0.0;
     
     cout << "Order Receipt:" << endl << endl;
     
     for (int i=0; i<NUM_CHOICES; i++) {
          if ((choice[i] <=0)||(choice[i]>5)) {
               break;
          } else if (choice[i] == 1) {
               cout << left << setw(20) << itemInfo[0].name
               << setw(15) << itemInfo[0].cost << endl;
               subTotal += itemInfo[0].cost;
          } else if (choice[i] == 2) {
               cout << left << setw(20) << itemInfo[1].name
               << setw(15) << itemInfo[1].cost << endl;
               subTotal += itemInfo[1].cost;
          }else if (choice[i] == 3) {
               cout << left << setw(20) << itemInfo[2].name
               << setw(15) << itemInfo[2].cost << endl;
               subTotal += itemInfo[2].cost;
          } else if (choice[i] == 4){
               cout << left << setw(20) << itemInfo[3].name
               << setw(15) << itemInfo[3].cost << endl;
               subTotal += itemInfo[3].cost;
          } else if (choice[i] == 5) {
               cout << left << setw(20) << itemInfo[4].name
               << setw(15) << itemInfo[4].cost << endl;
               subTotal += itemInfo[4].cost;
          }
     }
     
     tax = subTotal * taxRate;
     total = tax + subTotal;
     cout << left << setw(20) << "Tax"
          << setw(15) << tax << endl;
     cout << left << setw(20) << "Amount Due"
          << setw(15) << total << endl;
}
