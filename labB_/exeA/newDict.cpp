

/*
 * File Name: dictionaryList.cpp
 * Assignment: Lab 2 Exercise A
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: September 23, 2023
 */

#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include "dictionaryList.h"
#include "mystring_B.h"

using namespace std;

Node::Node(const Key &keyA, const Datum &datumA, Node *nextA)
    : keyM(keyA), datumM(datumA), nextM(nextA){}
DictionaryList::DictionaryList()
    : sizeM(0), headM(0), cursorM(0){}

DictionaryList::DictionaryList(const DictionaryList &source)
{copy(source);}

DictionaryList &DictionaryList::operator=(const DictionaryList &rhs)
{
  if (this != &rhs)
  {
    destroy();
    copy(rhs);
  }
  return *this;
}
DictionaryList::~DictionaryList()
{
  destroy();
}

int DictionaryList::size() const
{
  return sizeM;
}

int DictionaryList::cursor_ok() const
{
  return cursorM != 0;
}

const Key &DictionaryList::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->keyM;
}

const Datum &DictionaryList::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->datumM;
}

void DictionaryList::insert(const Key &keyA, const Datum &datumA)
{
  if (headM == 0 || keyA < headM->keyM)
  {
    headM = new Node(keyA, datumA, headM);
    sizeM++;
  }

  else if (keyA == headM->keyM)
    headM->datumM = datumA;

  else
  {


    for (Node *p = headM; p != 0; p = p->nextM)
    {
      if (keyA == p->keyM)
      {
        p->datumM = datumA;
        return;
      }
    }

    Node *p = headM->nextM;
    Node *prev = headM;

    while (p != 0 && keyA > p->keyM)
    {
      prev = p;
      p = p->nextM;
    }

    prev->nextM = new Node(keyA, datumA, p);
    sizeM++;
  }
  cursorM = NULL;
}

void DictionaryList::remove(const Key &keyA)
{
  if (headM == 0 || keyA < headM->keyM)
    return;

  Node *doomed_node = 0;

  if (keyA == headM->keyM)
  {
    doomed_node = headM;
    headM = headM->nextM;

  }
  else
  {
    Node *before = headM;
    Node *maybe_doomed = headM->nextM;
    while (maybe_doomed != 0 && keyA > maybe_doomed->keyM)
    {
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->nextM;
    }

    if (maybe_doomed != 0 && maybe_doomed->keyM == keyA)
    {
      doomed_node = maybe_doomed;
      before->nextM = maybe_doomed->nextM;
    }
  }
  if (doomed_node == cursorM)
    cursorM = 0;

  sizeM--;
}

void DictionaryList::go_to_first()
{
  cursorM = headM;
}

void DictionaryList::step_fwd()
{
  assert(cursor_ok());
  cursorM = cursorM->nextM;
}

void DictionaryList::make_empty()
{
  destroy();
  sizeM = 0;
  cursorM = 0;
}


void DictionaryList::find(const Key &keyA)
{
  for (Node *p = headM; p != 0; p = p->nextM)
  {
    if (keyA == p->keyM)
    {
      cursorM = p;
      return;
    }
    cursorM = NULL;
  }
}

void DictionaryList::destroy()
{
  Node *current = headM;
  while (current != nullptr)
  {
    Node *next = current->nextM;
    delete current;
    current = next;
  }
  headM = nullptr;
  cursorM = nullptr;
  sizeM = 0;
}

void DictionaryList::copy(const DictionaryList &source)
{
  headM = nullptr;
  cursorM = 0;
  if (source.headM == nullptr)
  {
    sizeM = 0;
    return;
  }
  headM = new Node(source.headM->keyM, source.headM->datumM, nullptr);
  if (source.cursorM == source.headM)
  {
    cursorM = headM;
  }
  Node *p = source.headM->nextM;
  Node *newNode = headM;
  while (p != 0)
  {
    newNode->nextM = new Node(p->keyM, p->datumM, nullptr);
    newNode = newNode->nextM;
    if (source.cursorM == p)
    {
      cursorM = newNode;
    }
    p = p->nextM;
  }
  sizeM = source.sizeM;
}

ostream &operator<<(ostream &os, const DictionaryList &dl)
{
  DictionaryList temp = dl;
  temp.go_to_first();
  while (temp.cursor_ok())
  {
    /*
    cursour_datum is a pointer to datumM which is an object of lengthM and charsM
    so we need to make a <<operator for myString
    friend ostream &operator<<(ostream &os, const Mystring &s);
    */
    cout << temp.cursor_key() << ": " << temp.cursor_datum();
    cout << endl;
    temp.step_fwd();
  }
  return os;
}

const Mystring &DictionaryList::operator[](const int index)
{
  go_to_first();

  for (int i = 0; i < index; ++i)
  {
    step_fwd();
  }
  return cursor_datum();
}