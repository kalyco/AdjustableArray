// Array.h

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array
{
 public:
  // Default constructor
  Array();
  // Nondefault constructor
  Array(int aLen);
  // Copy constructor
  Array(const Array & other);
  // Assign operator
  Array & operator=(const Array & other);
  // Destructor
  ~Array();

  void input(std::istream & s = std::cin);
  void output(std::ostream & s = std::cout) const;

  const int & operator[](int which) const;
  int & operator[](int which);

  int length() const;

protected:
  void setLength(int aLen);

private:
  int * mA;
  int mLen;

  void allocate(int aLen);
  void copy(const Array & other);
  void cleanup();
};

std::istream & operator>>(std::istream & s,       Array & a);
std::ostream & operator<<(std::ostream & s, const Array & a);

bool operator==(const Array & a1, const Array & a2);

Array operator+(const Array & a1, const Array & a2);
Array operator+(const Array & a1,               int x);
Array operator+(              int x, const Array & a2);

#endif
