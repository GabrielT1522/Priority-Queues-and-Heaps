CSCE 3301 - Algorithms and Data Structures
README.TXT
Priority Queues and Heaps

Created by Gabriel Torres on 10/14/22.

For this programming assignment, a Priority Queue is implemented and follows the following conditions: 

1. The Priority Queue can grow dynamically. 
2. Three (3) different implementations of the Priority Queue are created. 
3. Two (2) of these implementations will be based on a List. 
    - The first list implementation, UnsortedPQ, uses an unsorted list to store the data. 
    - The second list implementation, SortedPQ, uses a sorted list. 
    - The third implementation, HeapPQ, should be an array-based implementation of a Heap.

    
The mplementations are tested using a set of numbers in a text file named “numbers.txt”. 
Each line of the file will contain a number. The first number will be which Priority Queue to use 
(0=UnsortedPQ, 1=SortedPQ, 2=HeapPQ). The second number will be the number of remaining elements in the file, n.
The first two numbers of the file (queue type and n) will NOT be inserted into the Priority Queue.
However, the remaining n numbers will be inserted. All n numbers are then removed and are printed on the screen.