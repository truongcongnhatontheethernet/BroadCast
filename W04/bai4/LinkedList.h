#include <iostream>
#include <ostream>
#include <pthread.h>
#include <stdexcept>

using namespace std;

#ifndef _LL_H
#define _LL_H

template <class T> struct Node {
  T info;
  Node *pNext;
};

template <class T> class LinkedList {

private:
  Node<T> *_pHead, *_pTail;
  int _n;
  static Node<T> *CreateNode(const T &);

public:
  LinkedList();
  ~LinkedList();

  Node<T> *AddHead(const T &);
  Node<T> *AddTail(const T &);
  Node<T> *RemoveHead();
  Node<T> *RemoveTail();

  T &operator[](const int &);

  friend ostream &operator<<(ostream &os, const LinkedList<T> &ll) {

    Node<T> *node = ll._pHead;
    while (node) {
      os << node->info << ", ";
      node = node->pNext;
    }

    return os;
  }
};

template <class T> LinkedList<T>::LinkedList() {
  _pHead = _pTail = nullptr;
  _n = 0;
}

template <class T> LinkedList<T>::~LinkedList() {
  _n = 0;
  Node<T> *node = _pHead;
  while (_pHead != nullptr) {
    _pHead = _pHead->pNext;
    delete node;
    node = _pHead;
  }
}

template <class T> Node<T> *LinkedList<T>::CreateNode(const T &value) {
  Node<T> *newNode = new Node<T>{value, nullptr};
  return newNode;
}

template <class T>

Node<T> *LinkedList<T>::AddHead(const T &value) {

  Node<T> *newNode = CreateNode(value);

  newNode->pNext = _pHead;
  if (!_pTail) {
    _pTail = newNode;
  }

  _pHead = newNode;
  _n++;
  return newNode;
}

template <class T>

Node<T> *LinkedList<T>::AddTail(const T &value) {

  Node<T> *newNode = CreateNode(value);

  if (!_pTail) {
    _pHead = _pTail = newNode;
  }

  _pTail->pNext = newNode;
  _pTail = newNode;
  _n++;
  return newNode;
}

template <class T> Node<T> *LinkedList<T>::RemoveHead() {

  if (!_pHead)
    return nullptr;
  Node<T> *node = _pHead;
  _pHead = _pHead->pNext;
  _n--;

  if (!_pHead)
    _pTail = nullptr;

  return node;
}
template <class T> Node<T> *LinkedList<T>::RemoveTail() {

  if (!_pTail)
    return nullptr;

  Node<T> *node = _pHead;
  Node<T> *prev = nullptr;
  for (; node && node != _pTail; prev = node, node = node->pNext) {
  }

  if (prev) {
    prev->pNext = _pTail->pNext;
    _pTail = prev;
  }

  else if (node) {
    _pTail = _pHead = nullptr;
  }

  else {
    return nullptr;
  }

  // x->y->z

  _n--;
  return node;
}

template <class T> T &LinkedList<T>::operator[](const int &id) {
  if (id < 0 || id >= _n)
    throw out_of_range("out");

  Node<T> *p;
  int i = 0;
  for (p = _pHead; p && i != id; p = p->pNext, i++) {
  }

  return p->info;
}

#endif
