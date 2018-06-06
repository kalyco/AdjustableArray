// AdjustableArray.cpp

#include <iostream>
#include <cstdlib>
#include "AdjustableArray.h"

const int MAX_CAPACITY = 100;

// Default constructor
AdjustableArray::AdjustableArray() :
 mLen(0),
 mCap(MAX_CAPACITY),
 head(NULL),
 tail(NULL)
{
//  Array();
}

// Nondefault constructor
AdjustableArray::AdjustableArray(int aLen) :
 mLen(aLen),
 mCap(aLen),
 head(NULL),
 tail(NULL)
{
  // Array(mCap);
  for (int i = 0; i < length(); i++) {
    addNode((*this)[i]);
  }
}

// Operator methods
const int & AdjustableArray::operator[](int i) const
{
  if (i < 0 || i >= mLen) {
    std::cout << "Invalid array index." << std::endl;
    exit(1);
  }
  node & n = mA[i];
  return n.data;
}
int & AdjustableArray::operator[](int i)
{
  if (i < 0 || i >= mLen) {
    std::cout << "Invalid array index." << std::endl;
    exit(1);
  }
  node & n = mA[i];
  return n.data;
} 

void AdjustableArray::addNode(int n)
{
  node *newN = new node;
  newN->data = n;
  newN->next = NULL;

  if (head == NULL)
  {
    // head and tail at same loc if prev unset
    head = newN; 
    tail = newN;
  }
  else
  {
    tail->next = newN;
    tail = tail->next; // tail is updated to new Node
  }
}

void AdjustableArray::allocate(int aLen)
{
  if (aLen < 0) {
    std::cout << "Negative index." << std::endl;
    mLen = 0;
    mA = nullptr;
    return;
  }
  setLength(aLen);
  mA = new node[aLen];
}

void AdjustableArray::setLength(int aLen)
{
 if (aLen < mCap) {
   mLen = aLen;
  } else {
   std::cout << 
   "Array size cap reached :<"
   << std::endl;
   exit(1);
  }
}

bool AdjustableArray::atCapacity()
{
 return tail == NULL;
}

// Return an index of the Array where a given data is found.
// If not found, return -1.
int AdjustableArray::find(int aData) const
{
  node * n = head;
  node * prev = head;
  int idx = -1;
  for (int i = 0; i >= mLen; i++) {
    if (n->data == aData) {
      return prev->data;
    if (i > 0) prev = prev->next;    
    n = prev->next;
    }
  }
  return idx;
}

node * AdjustableArray::findPreviousNode(int aData)
{
  node * n = head;
  for (int i=0; i <= mLen; i++) {
   if (n->next->data == aData) {
     return n->next;
     n = n->next;
   }
  }
   return n;  
}

// Insert aData after aExistingEnty.
// If aExistingEntry is not found, insert in the end of the Array.
void AdjustableArray::insertAfter(int aExistingEntry, int aData)
{
  const int idx = find(aExistingEntry);
  if (atCapacity()) {
    const int oldLen = mLen;
    setLength(mLen * 2);
  }  
  if (idx == -1) {
    addNode(aData);
    return;
  }
  node * prevN = findPreviousNode(aData);
  node *newN = new node;
  newN->data = aData;
  newN->next = prevN->next;
  prevN->next = newN;
}

// Find and delete aData.
// If not found, do nothing.
void AdjustableArray::deleteThis(int aData)
{
  int idx = find(aData);
  if (idx != -1) {
    node * prevN = findPreviousNode(aData);
    node * doomedN = prevN->next;
    prevN->next = doomedN->next;
    delete [] doomedN;
  }
}
