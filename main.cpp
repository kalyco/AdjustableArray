// main.cpp

#include <iostream>
#include "AdjustableArray.h"

using namespace std;

int main()
{
  AdjustableArray a1(-1); // Non-default constructor
  
  AdjustableArray a2; // constructor

  cout << "a2: " 
       << a2  // Overloaded << operator
       << endl; 
  
  AdjustableArray a3(10); // Non-default constructor

  for (int i = 0; i < a3.length(); i++) {
    a3[i] = i + 1; // overloaded [] operator
  }
  
  cout << "a3: "
       << a3
       << endl;
  
  // Testing insertion and deletion
  a3.insertAfter(3, 15);
  
  cout << "a3: "
       << a3
       << endl;
  

  a3.insertAfter(33, 100);

  cout << "a3: "
       << a3
       << endl;
  

  a3.deleteThis(2);

  cout << "a3: "
       << a3
       << endl;  

  a3.insertAfter(1, 30);

  cout << "a3: "
       << a3
       << endl;
  
  a3.deleteThis(55);

  cout << "a3: "
       << a3
       << endl;

  return 0;
}
