// CSCE 3301 - Algorithms and Data Structures
// main.cpp
// Priority Queues and Heaps
//
// Created by Gabriel Torres on 10/14/22.

#include "UnsortedPQ.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  int qType, n;
  srand(time(NULL)); // Initiate random generator seed
  qType = rand() % 3 + 1; // First random number is either 0, 1, or 2
  n = rand() % 21 + 1; // Second random number is between 1 and 20

  ofstream outFile("numbers.txt");
  outFile << qType << endl << n << endl;
  // Insert n random numbers between 1 and 100 into the file
  for (int i = 0; i < n; i++) {
    outFile << rand() % 101 << endl;
  }
  outFile.close();

  int dataArray[n];
  
  ifstream inFile("numbers.txt");
  inFile >> qType >> n;
  for (int i = 0; i < n; i++) {
    inFile >> dataArray[i];
  }
  inFile.close();
  /*
  // Test file
  for (int i = 0; i < n; i++) {
    cout << "Array index [" << i << "]: " << dataArray[i] << endl;
  }
  */
  cout << "Priority Queue Type: " << qType << endl;
  cout << "Priority Queue size: " << n << endl;
  UnsortedPQ<int> myUPQ(dataArray, n);
  cout << "myUPQ.isEmpty(): " << myUPQ.isEmpty() << endl;
  cout << "myUPQ.size(): " << myUPQ.size() << endl;
  cout << "myUPQ.minValue(): " << myUPQ.minValue() << endl;
  //cout << "myUPQ.removeMin(): " << myUPQ.removeMin() << endl;
  cout << "myUPQ.size(): " << myUPQ.size() << endl;
  cout << "myUPQ.minValue(): " << myUPQ.minValue() << endl;

  

  return 0;
}