#include<iostream>
#include "CharStack.h"
using namespace std;

int main() {
     CharStack myStack;
     
     if (myStack.isEmpty())
          cout << "stack is empty GOOD" << endl;
     else
          cout << "stack is not empty BAD" << endl;
     
     myStack.push('x');
     
     if (myStack.isEmpty())
          cout << "stack is empty BAD" << endl;
     else
          cout << "stack is not empty GOOD" << endl;
     
     if (myStack.isFull())  //this stack is never full
          cout << "stack is full BAD" << endl;
     else
          cout << "stack is NOT full GOOD" << endl;
     
     CharStack stack;
     char item;
     stack.push('2');
     stack.push('3');
     stack.push('5');
     item = stack.peek(); //item is 5
     cout << "item " << item << " should be 5" << endl;
     stack.pop();
     item = stack.peek(); //item is 3
     cout << "item " << item << " should be 3" << endl;
     stack.pop();
     stack.push('0');
     stack.pop();
     stack.pop();
     if (stack.isEmpty())
          cout << "stack is empty GOOD" << endl;
     else
          cout << "stack is not empty BAD" << endl;
return 0;
}
