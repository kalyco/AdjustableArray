// AdjustableArray

#ifndef ADJUSTABLE_ARRAY_H
#define ADJUSTABLE_ARRAY_H

#include <iostream>

#include "Array.h"

struct node
{
  int data;
  struct node *next;
};

class AdjustableArray : public Array 
{
public:
  // Default constructor
  AdjustableArray();
  // Nondefault constructor
  AdjustableArray(int aLen);
  // Copy contstructor
  //AdjustableArray(const AdjustableArray & other)
  // Destructor
  //~AdjustableArray();
    // Assign operator
  // Assignment operator
  // AdjustableArray & operator=(const AdjustableArray & other);

  const int & operator[](int which) const;
  int & operator[](int which);

  int find(int aData) const;
  void insertAfter(int aExistingEntry, int aData);
  void deleteThis(int aData);

protected:
  void setLength(int aLen);

private:
  node *head,*tail;
  node * mA;
  int mLen;
  int mCap;

  void allocate(int aLen);
  void copy(const AdjustableArray & other);
  void cleanup();

  bool atCapacity();
  int findLastIdx();
  node * findPreviousNode(int aData);
  void addNode(int n);
  // void updateTail(node *n);
};
#endif
