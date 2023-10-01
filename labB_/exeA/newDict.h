/*
 * File Name:  dictionaryList.h
 * Assignment: Lab 2 Exercise A
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: September 23, 2023
 */
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
using namespace std;
#include "mystring_B.h"
typedef int Key;
typedef Mystring Datum;
class Node
{
  friend class DictionaryList;
private:
  Key keyM;
  Datum datumM;
  Node *nextM;
  Node(const Key &keyA, const Datum &datumA, Node *nextA);
};

class DictionaryList
{
public:
  friend ostream &operator<<(ostream &os, const DictionaryList &s);
  DictionaryList();
  DictionaryList(const DictionaryList &source);
  DictionaryList &operator=(const DictionaryList &rhs);
  ~DictionaryList();
  const Mystring &operator[](const int index);
  int size() const;
  int cursor_ok() const;
  const Key &cursor_key() const;
  const Datum &cursor_datum() const;
  void insert(const Key &keyA, const Datum &datumA);
  void remove(const Key &keyA);
  void find(const Key &keyA);
  void go_to_first();
  void step_fwd();
  void make_empty();
private:
  int sizeM;
  Node *headM;
  Node *cursorM;

  void destroy();

  void copy(const DictionaryList &source);
};

#endif
