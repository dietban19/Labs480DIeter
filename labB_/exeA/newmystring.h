/* File: mystring_B.h
 *
 *
 */
/*
 * File Name:  mystring_B.h
 * Assignment: Lab 2 Exercise A
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: September 23, 2023
 */

#include <iostream>
#include <string>
using namespace std;

#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring
{

public:
  friend ostream &operator<<(ostream &os, const Mystring &s);
  Mystring();
  Mystring(int n);
  Mystring(const char *s);
  int length() const;
  char get_char(int pos) const;
  const char *c_str() const;
  void set_char(int pos, char c);
  Mystring &append(const Mystring &other);
  void set_str(char *s);
  int isGreaterThan(const Mystring &s) const;
  int isLessThan(const Mystring &s) const;
  int isEqual(const Mystring &s) const;
  int isNotEqual(const Mystring &s) const;
  bool operator>=(const Mystring &rhs) const;
  bool operator<=(const Mystring &rhs) const;
  bool operator!=(const Mystring &rhs) const;
  bool operator>(const Mystring &rhs) const;
  bool operator<(const Mystring &rhs) const;
  bool operator==(const Mystring &rhs) const;
  char &operator[](const int index) const;
private:
  void memory_check(char *s);
};
#endif
