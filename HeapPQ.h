// CSCE 3301 - Algorithms and Data Structures
// HeapPQ.h
// Priority Queues and Heaps
//
// Created by Gabriel Torres on 10/14/22.

#ifndef HEAPPQ_H
#define HEAPPQ_H
#include <exception>
#include <iostream>
using namespace std;

class entry {
public:
  int key;
  int value;
};

class ListNode {
public:
  entry *entryExample;
  ListNode *next, *prev;
};

class HeapPQ {
private:
  ListNode *front, *rear;
  int count;

public:
  HeapPQ(void) {
    count = 0;
    front = NULL;
    rear = NULL;
  };
  // Performs an insertion of "n" items from dataArray
  // into the priority queue
  HeapPQ(int *dataArray, int n) {
    count = 0;
    front = NULL;
    rear = NULL;
    for (int i = 0; i < n; i++) {
      insertItem(dataArray[i]);
    }
  };
  ~HeapPQ(void) { cout << "\nHeap Priority Queue has been deconstructed.\n"; };
  bool isEmpty() {
    if (size() == 0)
      return true;
    else
      return false;
  };
  int size() { return count; };
  // inserts a piece of data into the priority queue
  void put(int key, int value) {
    ListNode *itr = front->next;
    while (itr->next != rear) {
      if ((itr->entryExample)->key == key) {
        (itr->entryExample)->value = value;
        return;
      }
      itr = itr->next;
    }
    // entry with the same key doesn not exist
    // new to create a new node
    entry *newEntry = new entry();
    newEntry->key = key;
    newEntry->value = value;

    ListNode *newNode = new ListNode();
    newNode->entryExample = newEntry;
    
    ListNode *lastNode = rear->prev;

    newNode->prev = lastNode;
    newNode->next = rear;
    lastNode->next = newNode;
    rear->prev = newNode;
    count++;
  };
  // removes and returns the minimum value in the queue
  // throws an exception if the queue is empty
  int removeMin(void){

  };

  // return the minimum value in the queue without removing it
  // throws an exception if the queue is empty
  int minValue(void){

  };
};
#endif