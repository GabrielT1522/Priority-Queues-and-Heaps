// CSCE 3301 - Algorithms and Data Structures
// PriorityQueue.h
// Priority Queues and Heaps
//
// Created by Gabriel Torres on 10/14/22.

#ifndef UNSORTEDPQ_H
#define UNSORTEDPQ_H
#include "Node.h"
#include <exception>
#include <iostream>
using namespace std;

template <class Type> class UnsortedPQ {
private:
  Node<Type> *front, *rear;
  int count;

public:
  UnsortedPQ(void) {
    count = 0;
    front = NULL;
    rear = NULL;
  };
  // Performs an insertion of "n" items from dataArray
  // into the priority queue
  UnsortedPQ(Type *dataArray, int n) {
    count = 0;
    front = NULL;
    rear = NULL;
    for (int i = 0; i < n; i++) {
      insertItem(dataArray[i]);
    }
  };
  ~UnsortedPQ(void) {
    cout << "\nUnsorted Priority Queue has been deconstructed.\n";
  };
  bool isEmpty() {
    if (size() == 0)
      return true;
    else
      return false;
  };
  int size() { return count; };
  // inserts a piece of data into the priority queue
  void insertItem(Type data) {
    auto *newNode = new Node<Type>();
    newNode->element = data;
    if (front == NULL) {
      front = rear = newNode;
    } else {
      newNode->next = front;
      front->prev = newNode;
      front = newNode;
    }
    count++;
  };
  // removes and returns the minimum value in the queue
  // throws an exception if the queue is empty
  Type removeMin(void) throw(exception) {
    auto *itr = front;
    int min = minValue();

    //cout << "\nAfter: " << itr->element << endl;
    while (itr != NULL && min != itr->element) {
      itr = itr->next;
      if (min == itr->element) {
        if (front == rear) {
          front == rear == NULL;
        } else {
          itr->next = itr->prev;
          // rear->next = NULL;
          //delete (itr);
        }
        count--;
      }
    }
    return min;
  };
  // return the minimum value in the queue without removing it
  // throws an exception if the queue is empty
  Type minValue(void) throw(exception) {
    Type min = 100;
    auto *itr = front;
    while (itr != NULL) {
      if (min > itr->element) {
        min = itr->element;
      }
      itr = itr->next;
    }
    return min;
  };
};
#endif