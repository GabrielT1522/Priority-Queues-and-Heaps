// CSCE 3301 - Algorithms and Data Structures
// main.cpp
// Priority Queues and Heaps
//
// Created by Gabriel Torres on 10/14/22.

#include "SortedPQ.h"
#include "UnsortedPQ.h"
#include <fstream>
#include <iostream>
using namespace std;

template <class Type> void testUnsortedPQ(Type *dataArray, int n) {
  UnsortedPQ<int> myUPQ(dataArray, n);
  cout << "myUPQ.isEmpty(): " << myUPQ.isEmpty() << endl;
  cout << "myUPQ.size(): " << myUPQ.size() << endl;
  cout << "myUPQ.printUnsortedPQ(): ";
  myUPQ.printUnsortedPQ();
  cout << "myUPQ.minValue(): " << myUPQ.minValue() << endl;
  cout << "myUPQ.removeMin(): " << myUPQ.removeMin() << endl;
  cout << "myUPQ.size(): " << myUPQ.size() << endl;
  cout << "myUPQ.printUnsortedPQ(): ";
  myUPQ.printUnsortedPQ();
  cout << "myUPQ.minValue(): " << myUPQ.minValue() << endl;
}

template <class Type> void testSortedPQ(Type *dataArray, int n) {
  SortedPQ<int> mySPQ(dataArray, n);
  cout << "mySPQ.isEmpty(): " << mySPQ.isEmpty() << endl;
  cout << "mySPQ.size(): " << mySPQ.size() << endl;
  cout << "mySPQ.printSortedPQ(): ";
  mySPQ.printSortedPQ();
  cout << "mySPQ.minValue(): " << mySPQ.minValue() << endl;
  cout << "mySPQ.removeMin(): " << mySPQ.removeMin() << endl;
  cout << "mySPQ.size(): " << mySPQ.size() << endl;
  cout << "mySPQ.printSortedPQ(): ";
  mySPQ.printSortedPQ();
  cout << "mySPQ.minValue(): " << mySPQ.minValue() << endl;
}

string PQTypeName(int qType) {
  if (qType == 0) {
    return "Unsorted Priority Queue";
  } else if (qType == 1) {
    return "Sorted Priority Queue";
  } else if (qType == 2) {
    return "Heap Priority Queue";
  } else {
    return "Error";
  }
}

int main() {
  int PQType, n;
  srand(time(NULL));   // Initiate random generator seed
  PQType = rand() % 3; // First random number is either 0, 1, or 2
  n = rand() % 21 + 1; // Second random number is between 1 and 20
  
  ofstream outFile("numbers.txt");
  outFile << PQType << endl << n << endl;
  // Insert n random numbers between 1 and 100 into the file
  for (int i = 0; i < n; i++) {
    outFile << rand() % 101 + 1 << endl;
  }
  outFile.close();

  int dataArray[n];

  ifstream inFile("numbers.txt");
  inFile >> PQType >> n;
  for (int i = 0; i < n; i++) {
    inFile >> dataArray[i];
  }
  inFile.close();
  
  cout << "Priority Queue Type: " << PQTypeName(PQType) << endl;
  cout << "Priority Queue size: " << n << endl << endl;
  switch (PQType) {
  case 0:
    testUnsortedPQ(dataArray, n);
    break;
  case 1:
    testSortedPQ(dataArray, n);
    break;
  case 2:
    cout << "Heap Priority Queue has not been implemented yet.\n";
    break;
  default:
    break;
  }

  return 0;
}
