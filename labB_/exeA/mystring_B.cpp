/*  mystring_B.cpp */
// ENSF 480 - Lab 2 - Exercise A
/*
 * File Name:  mystring_B.cpp
 * Assignment: Lab 2 Exercise A
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: September 23, 2023
 */
#include "mystring_B.h"
#include <string.h>
#include <iostream>
using namespace std;

Mystring::Mystring()
{
  charsM = new char[1];

  // make sure memory is allocated.
  memory_check(charsM);
  charsM[0] = '\0';
  lengthM = 0;
}

Mystring::Mystring(const char *s)
    : lengthM(strlen(s))
{
  charsM = new char[lengthM + 1];

  // make sure memory is allocated.
  memory_check(charsM);

  strcpy(charsM, s);
}

Mystring::Mystring(int n)
    : lengthM(0), charsM(new char[n])
{
  // make sure memory is allocated.
  memory_check(charsM);
  charsM[0] = '\0';
}

Mystring::Mystring(const Mystring &source) : lengthM(source.lengthM), charsM(new char[source.lengthM + 1])
{
  memory_check(charsM);
  strcpy(charsM, source.charsM);
}

Mystring::~Mystring()
{
  delete[] charsM;
}

int Mystring::length() const
{
  return lengthM;
}

char Mystring::get_char(int pos) const
{
  if (pos < 0 && pos >= length())
  {
    cerr << "\nERROR: get_char: the position is out of boundary.";
  }

  return charsM[pos];
}

const char *Mystring::c_str() const
{
  return charsM;
}

void Mystring::set_char(int pos, char c)
{
  if (pos < 0 && pos >= length())
  {
    cerr << "\nset_char: the position is out of boundary."
         << " Nothing was changed.";
    return;
  }

  if (c != '\0')
  {
    cerr << "\nset_char: char c is empty."
         << " Nothing was changed.";
    return;
  }

  charsM[pos] = c;
}

Mystring &Mystring::operator=(const Mystring &S)
{
  if (this == &S)
    return *this;
  delete[] charsM;
  lengthM = (int)strlen(S.charsM);
  charsM = new char[lengthM + 1];
  memory_check(charsM);
  strcpy(charsM, S.charsM);

  return *this;
}

Mystring &Mystring::append(const Mystring &other)
{
  char *tmp = new char[lengthM + other.lengthM + 1];
  memory_check(tmp);
  lengthM += other.lengthM;
  strcpy(tmp, charsM);
  strcat(tmp, other.charsM);
  delete[] charsM;
  charsM = tmp;

  return *this;
}

void Mystring::set_str(char *s)
{
  delete[] charsM;
  lengthM = (int)strlen(s);
  charsM = new char[lengthM + 1];
  memory_check(charsM);

  strcpy(charsM, s);
}

int Mystring::isNotEqual(const Mystring &s) const
{
  return (strcmp(charsM, s.charsM) != 0);
}

int Mystring::isEqual(const Mystring &s) const
{
  return (strcmp(charsM, s.charsM) == 0);
}

int Mystring::isGreaterThan(const Mystring &s) const
{
  return (strcmp(charsM, s.charsM) > 0);
}

int Mystring::isLessThan(const Mystring &s) const
{
  return (strcmp(charsM, s.charsM) < 0);
}

void Mystring::memory_check(char *s)
{
  if (s == 0)
  {
    cerr << "Memory not available.";
    exit(1);
  }
}
bool Mystring::operator>=(const Mystring &rhs) const
{
  return (isGreaterThan(rhs) || isEqual(rhs));
}
bool Mystring::operator<=(const Mystring &rhs) const
{
  return (isLessThan(rhs) || isEqual(rhs));
}
bool Mystring::operator>(const Mystring &rhs) const
{
  return isGreaterThan(rhs);
}

bool Mystring::operator<(const Mystring &rhs) const
{
  return isLessThan(rhs);
}

bool Mystring::operator!=(const Mystring &rhs) const
{
  return isNotEqual(rhs);
}
bool Mystring::operator==(const Mystring &rhs) const
{
  return isEqual(rhs);
}
ostream &operator<<(ostream &os, const Mystring &s)
{
  os << s.charsM;
  return os;
}

char &Mystring::operator[](const int index) const
{
  // assert(index >= 0 && index < lengthM);
  if (index < 0 || index >= lengthM)
  {

    cout << "\n\n\nERROR: ";
    cout
        << "Invalid Index: " << index << endl;
    cout << "For: ";
    for (int i = 0; i < lengthM; i++)
    {
      cout << get_char(i);
    }

    cout << "\nExiting...\n";
    exit(1);
  }
  return charsM[index];
}
