
// File Name: assign2_asr36.cpp
//
// Author: Ayisha S. R. Sowkathali
// Partner: Sifaben vahora
// Date: 9/27/2016
// Assignment Number: 2
// CS 2308.002 Fall 2016
// Instructor: Jill Seaman
//
// This program allows the user to manage inventory of a small store that sells
//   sells electronics

#include<iostream>
#include<iomanip>
using namespace std;

const int SIZE = 100;    // size of partially filled inventory

// struct inventory holds the information of each product
struct inventory{
     string pName;  // name of the product
     int pSku;      // sku number of the product
     int pQuantity; // quantity of the products
     double pPrice; // price of the products
};

// Function prototypes
int displayOptions();
void addItem(inventory[], int&);
void removeItem(inventory[], int&);
void displayInventory(inventory[], int);
void displayProduct(inventory[], int&);
int binarySearch(inventory[], int&, int);
void bubbleSort(inventory [], int&);

int main() {
     
     inventory items[SIZE];   // structure array
     int index = 0;           // to keep track of array index
     int option;              // to store the choice
     
     cout << fixed << setprecision(2) << endl;
     
     do{
          option = displayOptions();

          switch (option) {
          case 1:
               addItem(items, index);
               break;
          case 2:
               removeItem(items, index);
               break;
		case 3:
			bubbleSort(items, index);
			displayInventory(items, index);
			break;
          case 4:
               displayProduct(items, index);
               break;
          default:
               break;
          }
     } while (option!=5);
          cout << "Exiting the program." << endl;
     
     cout << endl;
     
return 0;
}

//******************************************************************************
// displayOptions - displays the options to choose from in order to manage the
//   store inventory.
//   choice - used to store the choice entered by the user
//*****************************************************************************/
int displayOptions() {
     
     int choice;
     
     cout << "Manage Inventory Menu" << endl << endl;
     cout << "1. Add Product" << endl;
     cout << "2. Remove Product" << endl;
     cout << "3. Display inventory sorted by sku" << endl;
     cout << "4. Lookup a product by sku" << endl;
     cout << "5. Quit the program" << endl;
     cout << endl;
     cout << "Enter your choice: " ;
     cin >> choice;
     
     if(choice < 1 || choice >= 6) {
          cout << "Please enter 1, 2, 3, 4, or 5: ";
          cin >> choice;
     }
     return choice;
}


//******************************************************************************
// binarySearch - takes in the argumemt of structure array 'items', index to
//   to keep track of the partially filled array, and skuNum to perform a search
//   for the sku number of the product in the inventory.
//   first - First array element
//   last - last array element
//   middle - mid point of search
//   position - position of search value and flag.
//   the funtion returns the position of the search value.
//*****************************************************************************/
int binarySearch(inventory items[], int &index, int skuNum)
{
     int first = 0,
     last = index - 1,
     middle,
     position = -1;
     bool found = false;
     
     while (!found && first <= last)
     {
          middle = (first + last) / 2;
          if (items[middle].pSku == skuNum)
          {
               found = true;
               position = middle;
          }
          else if (items[middle].pSku > skuNum)
               last = middle - 1;
          else
               first = middle + 1;
     }
     return position;
}

//******************************************************************************
// addItem - takes in the argument of structure array 'items', and index to keep
//   track of the partially filled array.
//   It allows the user to enter the information of the product to the inventory
//   skuNum - stores the sku number entered by the user to add the product and
//        to perform a search on whether the product is already available in the
//        inventory.
//*****************************************************************************/
void addItem(inventory items[], int &index){
     
     int skuNum;
     
     if (index == SIZE) {
          cout << "!!WARNING!! INVENTORY IS FULL" << endl;
     }
     
     cout << "\nEnter the data for the new product in the following order:\n";
     cout << "sku, quantity, price on one line, ";
     cout << "and the product name on a separate line." << endl;
     
     cin >> skuNum >> items[index].pQuantity >> items[index].pPrice;
     cin >> ws;
     getline(cin, items[index].pName);
     if (binarySearch(items, index, skuNum)==0) {
          cout << "items exists in the inventory" << endl;
     }
     items[index].pSku = skuNum;
     
     cout << endl;
     
     index++;
}

//******************************************************************************
// removeItem - takes in the argument of structure array 'items', and index to
//   keep track of the partially filled array and allowes the user to enter the
//   sku number of the product to be removed.
//   sku - stores the sku number of the product to be removed.
//   check - stores the position returned by the binarySearch
//*****************************************************************************/
void removeItem(inventory items[], int &index) {
     int sku;
     int check;
     
     cout << "Enter sku of product to remove:";
     cin >> sku;
     
     check = binarySearch(items, index, sku);
     
     if (check < 0) {
          cout << "No product found with this sku." << endl;
          cout << endl;
     }
     else if ( check != index-1) {
          for (int i=check; i<index-1; i++) {
               items[i] = items[i+1];
          }
          cout << "Removed product with sku: " << sku << endl;
          cout << endl;
     }
     index--;
     cout << endl;
}

//******************************************************************************
// displayInventory - takes in the argument of structure array 'items', and
//   index to keep track of the partially filled array and displays all the
//   product available in the inventory using for loop.
//*****************************************************************************/
void displayInventory(inventory items[], int index) {
     cout << endl;
     for (int i=0; i<index; i++) {
          cout << right << setw(10) << items[i].pSku
               << setw(6) << items[i].pQuantity
               << setw(9) << items[i].pPrice
               << " " << items[i].pName << endl;
     }
     cout << endl;
}

//******************************************************************************
// bubbleSort - takes in the argument of structure array 'items', and index to
//   keep track of the partially filled array and sorts the inventory according
//   to the ascending order of the sku number of the product.
//   swap - swap to sort
//   temp - holds the data temporarily
//*****************************************************************************/
void bubbleSort(inventory items[], int &index)
{
	bool swap;
	inventory temp;
	do
	{
		swap = false;
		for (int i = 0; i < (index - 1); i++) {
			if (items[i].pSku > items[i + 1].pSku) {
				temp = items[i];
				items[i] = items[i + 1];
				items[i + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

//******************************************************************************
// displayProduct - takes in the argument of structure array 'items', and index
//   to keep track of the partially filled array and allowes the user to enter
//   the sku number of the product to know other informations of that particular
//   product.
//   sku - stores the sku number of the product to be viewed.
//   check - stores the position returned by the binarySearch
//*****************************************************************************/
void displayProduct(inventory items[], int &index) {
     
     int sku;
     int check;
     
     cout << "Enter sku of product to find: ";
     cin >> sku;
     cout << endl;
     
     check = binarySearch(items, index, sku);
     
     if (check < 0) {
          cout << "No product found with this sku." << endl;
     }
     else
     {
          cout << "product name: " << items[check].pName << endl;
          cout << "sku: " << sku << endl;
          cout << "quantity: " << items[check].pQuantity << endl;
          cout <<  "price: " << items[check].pPrice << endl;
     }
     cout << endl;
}

