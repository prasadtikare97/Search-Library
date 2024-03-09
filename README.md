1. Implement a C program that uses binary search trees to search for elements in a list of elements.

In this problem, you will create a .c program that, given a list of elements, prints out the positions in the list where the element is found.
For this problem, we will use Binary Search Trees (BST), which means you must use a dynamic doubly-linked list to store your data. 
Your tree will be composed of nodes that hold the data and the left and right subtrees, as well as an index that indicates the sequence in which the values are obtained in the original dataset.
search_lib.c search_lib.h search.c BST.c myData_CS500.csv


2. Implement a C program that uses heaps to search for elements in a list of elements.
 A heap is a data structure often used to find data in a given order (i.e., ascending or descending).
 According to the heap properties, the maximum (or minimum) value among all values in the tree is located at the root node.
In this problem, we will change the getAllOccurrences function but this time using a heap.
Since the goal of the heap is to have the maximum or minimum value at the root, we will assume that our getAllOccurrences function is always interested in whichever value the root has, rather than receiving an element to search for.
heap_lib.h heap_lib.c heap.c myHeapData_CS500.csv 
