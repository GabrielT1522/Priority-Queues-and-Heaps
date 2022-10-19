// CSCE 3301 - Algorithms and Data Structures
// Node.h
// Priority Queues and Heaps
//
// Created by Gabriel Torres on 10/14/22.

#ifndef NODE_H
#define NODE_H

// Define Node Class
template <class Type> class Node {
public:
  Node *next, *prev;
  Type element;
};
#endif