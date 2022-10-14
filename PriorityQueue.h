// CSCE 3301 - Algorithms and Data Structures
// PriorityQueue.h
// Priority Queues and Heaps
//
// Created by Gabriel Torres on 10/14/22.

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <exception>
using namespace std;

template <class Type> class PriorityQueue {
private:
  // data here
public:
  PriorityQueue(void);
  // Performs an insertion of "n" items from dataArray
  // into the priority queue
  PriorityQueue(Type *dataArray, int n);
  ~PriorityQueue(void);
  bool isEmpty(void);
  int size(void);
  // inserts a piece of data into the priority queue
  void insertItem(Type data);
  // removes and returns the minimum value in the queue
  // throws an exception if the queue is empty
  Type removeMin(void) throw(exception);
  // return the minimum value in the queue without removing it
  // throws an exception if the queue is empty
  Type minValue(void) throw(exception);
};
#endif