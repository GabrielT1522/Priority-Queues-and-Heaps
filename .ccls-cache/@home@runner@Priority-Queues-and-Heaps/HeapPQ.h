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

template <class Type> class HeapPQ {
private:
  // Initialize max size of heapArray
  const static int MAX = 22;
  int heapArray[MAX];
  int heapArraySize;
  int count;

public:
  HeapPQ(int dataArray[], int n) {
    count = 0;
    heapArraySize = n;
    for (int i = 0; i < n; i++) {
      insertItem(dataArray[i]);
    }
  };
  ~HeapPQ(void) { cout << "\nHeap Priority Queue has been deconstructed.\n"; };

  int size() { return count; }

  bool isEmpty() {
    if (size() == 0)
      return true;
    else
      return false;
  }

  int parent(int index) { return (index - 1) / 2; }

  int rightChild(int index) { return (2 * index) + 2; }

  int leftChild(int index) { return (2 * index) + 1; }

  void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
  }

  void insertItem(int item) {
    heapArray[count] = item;
    count++;
    
    int index = count - 1;
    while (index != 0 && heapArray[parent(index)] > heapArray[index]) {
      swap(&heapArray[parent(index)], &heapArray[index]);
      index = parent(index);
    }
  };

  void minHeap(int index) {
    int left = leftChild(index);
    int right = rightChild(index);
    int min = index;

    if (left <= count && heapArray[right] < heapArray[min]) {
      min = left;
    }
    if (right <= count && heapArray[right] < heapArray[min]) {
      min = left;
    }

    if (min != index) {
      int tmp = heapArray[index];
      heapArray[index] = heapArray[min];
      heapArray[min] = tmp;
      minHeap(min);
    }
  };

  Type removeMin() {
    int min = minValue();
    heapArray[0] = heapArray[count - 1];
    count--;
    minHeap(0);
    return min;
  };
  Type minValue() { return heapArray[0]; }
  void printHeapPQ() {
    for (int i = 0; i < heapArraySize; i++) {
      cout << heapArray[i] << " ";
    }
    cout << endl;
  }
};
#endif