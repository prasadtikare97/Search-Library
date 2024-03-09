// inclusion guards
#ifndef HEAP_LIB_H
#define HEAP_LIB_H

// header files
#include <stdio.h>
#include <stdlib.h> // for malloc
#include <ctype.h> // for tolower
#include <stdbool.h> // for bool data type
#include <time.h>

// global constants
#define LENGTH 10
#define NOT_FOUND -1
#define SPECIFIER "%ld"


// data type definition
typedef long int dtype;

//declaring heapNode
typedef struct HeapNode {
    int data;
    struct HeapNode* left;
    struct HeapNode* right;
    struct HeapNode* parent;
} HeapNode;
//declaring heap

typedef struct heap {
    HeapNode* node;
} Heap;
//declaring queue node

typedef struct QueueNode {
    HeapNode* node;
    struct QueueNode *next;
} QueueNode;
//declaring queue

typedef struct Queue
{
    QueueNode* front;
    QueueNode* rear;
}Queue;

/**
* @brief Creates an empty heap

* This function initializes and returns an empty heap
*
* @return A pointer to the created heap
*/
Heap* createHeap();
/**
* @brief Creates an empty queue
*
* This function initializes and returns an empty queue
* time time complexity os O(1)
*param NA
*
* @return NA
*/

Queue* createQueue();
/**
* @brief inserting the node 
*

* The time complexity of this algorithm is <O(1)>
*
* @param  pointer root to the heapnode
* @param element 
* @... <add as many as needed>
**/

HeapNode* insertNode(dtype element, HeapNode* root);
/**
* @brief inserting the node to the heap by calling insertnode
*

* The time complexity of this algorithm is <O(1)>
*
* @param  pointer root to the heapnode
* @param element 
* @... <add as many as needed>
**/
HeapNode* insertHeap(dtype element, Heap* root);
 /**
* @brief getting the data from the file
*

* The time complexity of this algorithm is <O(1)>
*
* @param pointer to the filename
**/


HeapNode* getData(const char* filename);
 /**
* @brief max heapifying the nodes
*

* The time complexity of this algorithm is <O(1)>
*

* @param pointer to the root of the heap
* @param pointer to the rightmostnode of the heapnode

**/


void max_heapify(Heap* root,HeapNode* rightMostnode);
 /**
* @brief swapping two nodes
*

* The time complexity of this algorithm is <O(1)>
*

* @param pointer to the node1 of heapnode
* @param pointer to the node2 of heapnode

**/

void swapData(HeapNode* node1, HeapNode* node2);

 /**
* @brief printing the heap
*

* The time complexity of this algorithm is <O(1)>
*
* @param pointer root to the heapnode
**/
 void printHeap(HeapNode* root);
/**
* @brief Enqueues a node into a queue.
*
* This function enqueues a given heap node into the specified queue.
*
* @param queue The queue to enqueue the node into.
* @param node The heap node to enqueue.
*/
void enqueue(Queue* q, HeapNode* node);
/**
* @brief dequeues a node from a queue.
*
* This function enqueues a given heap node from the specified queue.
*
* @param  The queue to dequeue the node into.
*/

HeapNode* dequeue(Queue* q);
/**
* @brief checking if the queue is empty or not
*
* @param  pointer to the queue
*/


int isEmpty(Queue *queue);
 /**
* @brief  function for getting the all occurence of the element from the heap
*
* The time complexity of this algorithm is <O(1)>
*
* @param pointer to the root of the heap
* @param poiinter to the occurence 
**/

int getAllOccurrences(Heap* root, dtype* occurrences);
  /**
* @brief  Function to find the rightmost leaf
*
* The time complexity of this algorithm is <O(1)>
*
* @param pointer to the root of the tree

**/
HeapNode* getRightmostLeaf(Heap* root);
 /**
* @brief  function for removing the all occurence of the element from the heap
*
* The time complexity of this algorithm is <O(1)>
* @param pointer to the root of the heap
* @param number of occurrences
**/
HeapNode* removeAllOccurrences(Heap* root, int numOccur);
 /**
* @brief  function for removing the max element from the heap
*
* The time complexity of this algorithm is <O(1)>
* @param pointer to the root of the heap
* @param pointer to the n_node of the heapnode
**/
void removeMax(Heap* root, HeapNode* n_node);
 /**
* @brief  function for saving the data into the output file
*
* The time complexity of this algorithm is <O(1)>
* @param pointer to the root of the heap
* @param pointer to the filename
**/
void saveData(const char* filename, Heap* root);
 /**
* @brief helper function for saving the data into the output file
*
* The time complexity of this algorithm is <O(1)>
* @param pointer to the node of the heapnode
* @param pointer to the File
**/
void saveDataHelper(FILE* file, HeapNode* node);
  /**
* @brief  function to get the user input y or n
*
* The time complexity of this algorithm is <O(1)>
*
* @param NA
**/
char getChoiceYN();
// end SEARCH_LIB
#endif
