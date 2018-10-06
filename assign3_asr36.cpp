
// File Name: assign3_asr36.cpp
//
// Author: Ayisha S. R. Sowkathali
// Partner: Sifaben Vahora
// Date: 10/11/2016
// Assignment Number: 3
// CS 2308.002 Fall 2016
// Instructor: Jill Seaman
//
// Program to implement and test different functions using pointers and
//   dynamic memory allocation.

#include<iostream>
#include<iomanip>
using namespace std;

// Function prototypes
void showArray(int*, int);
bool isReverse(int*, int*, int, int);
double pizza(int, int*, int*);
int *duplicateArray(int*, int);
int *doubleArray(int*, int);
int *subArray(int*, int, int);

int main() {
     
     //testing isReverse
     bool flag;
     int testArray1[8] = {1, 2, 3, 4, 5, 6, 7, 8};
     int testArray2[8] = {8, 7, 6, 5, 4, 3, 2, 1};
     int testArray3[8] = {8, 6, 6, 5, 4, 3, 2, 1};
     
     flag = isReverse(testArray1, testArray2, 8, 8);
     cout << "\ntesting isReverse:" << endl;
     cout << "test data array 1: ";
     showArray(testArray1, 8);
     cout << "test data array 2: ";
     showArray(testArray2, 8);
     cout << "Expected result: true" << endl;
     cout << "Actual result:\t ";
     if (flag == true) {
          cout << "true" << endl;
     } else {
          cout << "false" << endl;
     }
     
     cout << "test data array 1: ";
     showArray(testArray1, 8);
     cout << "test data array 3: ";
     showArray(testArray3, 8);
     flag = isReverse(testArray1, testArray3, 8, 8);
     cout << "Expected result: false" << endl;
     cout << "Actual result:\t ";
     if (flag == true) {
          cout << "true" << endl;
     } else {
          cout << "false" << endl;
     }
     cout << endl;
     
     //testing pizza for 25 people
     int people = 25;
     int p;
     int s;
     cout << "testing pizza for 25 people:" << endl;
     cout << "Expected result: 112.80 p: 9 s: 3" << endl;
     double result = pizza(people, &p, &s);
     cout << fixed << setprecision(2);
     cout << "Actual results : " << result << " p: " << p << " s: " << s << endl;
     cout << endl;
     
     //testing doubleArray
     int testDoubleArray[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
     int *newDoubleArray;
     newDoubleArray = doubleArray(testDoubleArray, 9);
     cout << "testing doubleArray" << endl;
     cout << "test data: ";
     showArray(testDoubleArray, 9);
     cout << "Expected result: 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9" << endl;
     cout << "Actual result:\t ";
     showArray(newDoubleArray, 18);
     cout << endl;
     delete [] newDoubleArray;
     
     //testing subArray
     int start = 5;
     int length = 4;
     int testSubArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 32767};
     int *newSubArray;
     newSubArray = subArray(testSubArray, start, length);
     cout << "testing subArray: " << endl;
     cout << "test data: ";
     showArray(testSubArray, 10);
     cout << "start: " << start << " length: " << length << endl;
     cout << "Expected result: 6 7 8 9" << endl;
     cout << "Actual result:\t ";
     showArray(newSubArray, length);
     cout << endl;
     delete [] newSubArray;
     
return 0;
}

//*****************************************************************************
// showArray - takes all the array elements and displays in the console
//****************************************************************************/
void showArray(int *array, int size) {
     for (int i=0; i<size; i++) {
          cout << *(array+i) << " ";
     }
     cout << endl;
}

//*****************************************************************************
// isReverse - takes in two array pointers (arr1 and arr2) and the size of both
//   arrays. It compares two array pointers and returns true if they are equal
//   and in reverse order, it returns false if it is not equal.
// check - to keep track of the elements to be compared.
//****************************************************************************/
bool isReverse(int *arr1, int *arr2, int size1, int size2) {
     int check=0;
     for (int i=0; i<size1; i++) {
          if (*(arr1+i) == *(arr2+(size2-i-1))) {
               check++;
          }
     }
     if(check == size2){
          return true;
     }
     else {
          return false;
     }
}
              

//*****************************************************************************
// pizza - takes in one int arguments (number of people) and two int pointer
//   arguments (number of pizzas and number of slices) to calculate the
//   total slizes of pizza. It returns a double value to main.
// totalSlices - total slices of pizza after all the calculations.
//****************************************************************************/
double pizza(int people, int *pizzas, int *slices) {
     int totalSlices = people*3;
     *pizzas = totalSlices/8;
     *slices = totalSlices%8;
     return *pizzas*11.95 + *slices*1.75;
}

//*****************************************************************************
// duplicateArray - takes in a pointer array and size of array as arguments,
//   creates newArray using dynamic memory allocation.
//   It copied the elements of array to newArray and returns newArray.
//****************************************************************************/
int *duplicateArray(int *array, int size) {
     if (size<0)
          return NULL;
     int *newArray = new int[size];
     for (int i=0; i<size; i++) {
          *(newArray+i) = *(array+i);
     }
     return newArray;
}

//*****************************************************************************
// doubleArray - takes in a pointer array and size of array as arguments,
//   creates newArray double the size of actual array using dynamic memory
//   allocation.
//   It copies the elements of array to newArray and returns newArray.
//****************************************************************************/
int *doubleArray(int *array, int size) {
     int *newArray;
     if (size <= 0)
          return NULL;
     newArray = new int [size*2];
     for (int i = 0; i <= size; i++)
     {
          *(newArray+i)= *(array+i);
          for (int j=size; j<size*2; j++) {
               *(newArray+j) = *(array+(j-i));
          }
     }
     return newArray;
}

//*****************************************************************************
// subArray - takes an int array, start index and lenght as arguments.
//   It creates a new array that is a copy of the elements from the original
//   array starting at the start index, and has length equal to the length
//   argument by implementing duplicate array function.
//   It returns the new pointer array.
//****************************************************************************/
int *subArray(int *array, int start, int length) {
     int *result = duplicateArray(array+start, length);
     return result;
}