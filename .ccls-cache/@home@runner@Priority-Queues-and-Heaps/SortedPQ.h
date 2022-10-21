// CSCE 3301 - Algorithms and Data Structures
// SortedPQ.h
// Priority Queues and Heaps
//
// Created by Gabriel Torres on 10/14/22.

#ifndef SORTEDPQ_H
#define SORTEDPQ_H
#include "Node.h"
#include <exception>
#include <iostream>
using namespace std;

template <class Type> class SortedPQ {
private:
  Node<Type> *front, *rear;
  int count;

public:
  SortedPQ(void) {
    count = 0;
    front = NULL;
    rear = NULL;
  };
  // Performs an insertion of "n" items from dataArray
  // into the priority queue
  SortedPQ(Type *dataArray, int n) {
    count = 0;
    front = NULL;
    rear = NULL;
    for (int i = 0; i < n; i++) {
      insertItem(dataArray[i]);
    }
  };
  ~SortedPQ(void) {
    cout << "\nSorted Priority Queue has been deconstructed.\n";
  };
  bool isEmpty() {
    if (size() == 0)
      return true;
    else
      return false;
  };
  int size() { return count; };
  // inserts a piece of data into the priority queue
  void insertItem(int data) {
    auto *newNode = new Node<Type>();
    newNode->element = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (front == NULL)
      front = newNode;
    else if (front->element >= newNode->element) {
      newNode->next = front;
      (newNode->next)->prev = newNode;
      front = newNode;
    } else {
      auto *itr = front;
      // Get place to insert newNode in order
      while (itr->next != NULL && itr->next->element < newNode->element)
        itr = itr->next;
      
      newNode->next = itr->next;

      if (itr->next != NULL)
        newNode->next->prev = newNode;

      itr->next = newNode;
      newNode->prev = itr;
    }
    count++;
  };
  // removes and returns the minimum value in the queue
  Type removeMin(void) {
    auto tempNode = front;
    if (isEmpty()) {
      cout << "Sorted Priority Queue is empty.\n";
      return 0;
    } else {
      if (front == rear) {
        front == rear == NULL;
        free(front);
      } else {
        front = front->next;
        front->prev = NULL;
        free(tempNode);
      }
      count--;
    }
    return tempNode->element;
  };

  // return the minimum value in the queue without removing it
  Type minValue(void) {
    if (isEmpty()) {
      cout << "Sorted Priority Queue is empty.\n";
      return 0;
    } else {
      return front->element;
    }
  };

  void printSortedPQ() {
    if (isEmpty()) {
      cout << "Sorted Prority Queue is Empty.\n";
      return;
    }
    auto *itr = front;
    while (itr != NULL) {
      cout << itr->element << " ";
      itr = itr->next;
    }
    cout << endl;
  }
};
#endif