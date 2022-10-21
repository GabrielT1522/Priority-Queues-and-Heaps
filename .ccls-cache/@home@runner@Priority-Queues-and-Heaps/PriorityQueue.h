// CSCE 3301 - Algorithms and Data Structures
// PriorityQueue.h
// Priority Queues and Heaps
//
// Created by Gabriel Torres on 10/14/22.

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <exception>
#include <iostream>
using namespace std;

struct DNode {
public:
  DNode *prev, *next;
  int item;
};

class PriorityQueue {
private:
  DNode *front, *rear;
  int count;

public:
  PriorityQueue(void);
  // Performs an insertion of "n" items from dataArray
  // into the priority queue
  PriorityQueue(int *dataArray, int n);
  ~PriorityQueue(void);
  bool isEmpty() {
    if (count == 0)
      return true;
    else
      return false;
  };
  int size() { return count; };
  // inserts a piece of data into the priority queue in order
  // As noted from in class example 10/21/22
  void insertItem(DNode *toInsert) { //(Node *toInsert)
    DNode *p = front->next;
    while (toInsert->item > p->item) {
      p = p->next;
    }

    toInsert->prev = p;
    toInsert->next = p->next;
    p->next = toInsert;
    (p->next)->prev = toInsert;
    count ++;
  };
  // removes and returns the minimum value in the queue
  // throws an exception if the queue is empty
  int removeMin(void) throw(exception);
  // return the minimum value in the queue without removing it
  // throws an exception if the queue is empty
  int minValue(void) throw(exception);
};
#endif