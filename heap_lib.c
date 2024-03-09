#include "heap_lib.h"

//creating the heapstructure
Heap* createHeap()
{
//declaring heapsize
Heap* heap = (Heap*)malloc(sizeof(Heap));
// Initialize to empty heap
heap->node = NULL;
return heap;
}
//creating a queue
Queue* createQueue()
{
//declaring queue size
Queue* queue = (Queue*) malloc(sizeof(Queue));
//initializing to empty queue
queue->front = NULL;
queue->rear = NULL;
return queue;
}
//inserting node to heap
HeapNode* insertNode(dtype element, HeapNode* root)
{
//declaring heapnode size
HeapNode* newNode = (HeapNode*)malloc(sizeof(HeapNode));
//initializing first to empty then with data
newNode->data = element;
newNode->left = NULL;
newNode->right = NULL;
newNode->parent = NULL;
if(root == NULL)
{
//if root is null then return a new node
return newNode;
}
else
{
// Create a queue for insertion
Queue *queue = createQueue();
enqueue(queue, root);
while (!isEmpty(queue))
{
//dequeuing the queue
HeapNode *front = dequeue(queue);
//assigning heapleft to the new node
if (front->left == NULL)
{
front->left = newNode;
newNode->parent = front;
free(queue); // Free the queue
return newNode; // Return the new node
}
else if (front->right == NULL)
{
//assigning right heap to the newnode
front->right = newNode;
newNode->parent = front;
free(queue); // Free the queue
return newNode; // Return new node
}
else
{
// enqueue them for further traversal
enqueue(queue, front->left);
enqueue(queue, front->right);
}
}
free(queue); // Free the queue
return NULL;
}
}
HeapNode* insertHeap(dtype element, Heap* root)
{
//if root is null print error message
if (root == NULL)
{
fprintf(stderr, "Error: Heap is NULL.\n");
exit(EXIT_FAILURE);
}
//creating a new node to heap
HeapNode* added_node = insertNode(element, root->node);
//add the node to heap.
if(root->node == NULL)
{
root->node = added_node;
}
return added_node;
}
HeapNode* getData(const char* filename)
{
//creating a heap
Heap* root = createHeap();
char line[100];
//opening the file to read
FILE* file1 = fopen(filename,"r");
if(file1 == NULL)
{
printf("No such file or directory");
return;
}
dtype file_data;
//get the data from the file
while(fscanf(file1, SPECIFIER, &file_data) != EOF)
{
//printf("\nfile data %d",file_data);
HeapNode *newNode = insertHeap(file_data,root);
max_heapify(root,newNode);
}
//closing the file.
fclose(file1);
return root->node;
}
//maxifying the heap
void max_heapify(Heap* root,HeapNode* rightMostnode)
{
//getting the parent node
HeapNode* parent = rightMostnode->parent;
while(parent != NULL && rightMostnode->data > parent->data)
{
//swapping the data
swapData(rightMostnode,parent);
//swapping the node and the parent.
rightMostnode = parent;
parent = rightMostnode->parent;
}
}
void swapData(HeapNode* node1, HeapNode* node2)
{
//swapping the given two nodes.
dtype temp = node1->data;
node1->data = node2->data;
node2->data = temp;
}
void printHeap(HeapNode* root)
{
//printing the given heap.
if(root == NULL)
{
return;
}
//recursive calling for left and right sub tree
printHeap(root->left);
printf(SPECIFIER," ",root->data);
printHeap(root->right);
}
//function to enqueue
void enqueue(Queue* q, HeapNode* node)
{
//creating the queue node
QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
newNode->node = node;
newNode->next = NULL;
if (isEmpty(q))
{
//assigning the newnode to queue
q->front = q->rear = newNode;
}
else
{
//assiugning newnode to the rear queue
q->rear->next = newNode;
q->rear = newNode;
}
}
//function to dequeue
HeapNode* dequeue(Queue* q)
{
if (q->front == NULL) {
return NULL;
}
//getting the front of the queue
QueueNode* front_node = q->front;
q->front = q->front->next;
if (isEmpty(q))
{
//making a rear to null
q->rear = NULL;
}
//creating the dequeue node
HeapNode* dequeueNode = front_node->node;
//free the node
free(front_node);
return dequeueNode;
}
// Function to check if the queue is empty
int isEmpty(Queue *queue)
{
return (queue == NULL || queue->front == NULL);
}
int getAllOccurrences(Heap* root, dtype* occurrences)
{
//
if (root == NULL) {
return 0;
}
//initializing count to 1
int count = 1;
int numOccur = 0;
//creating queue
Queue* q = createQueue();
int maxVal = root->node->data;
//printf("\n new %ld ",maxVal);
//creating queue
if(root->node->left != NULL)
{
enqueue(q,root->node->left);
}
if(root->node->right != NULL)
{
// //enqueing right node of heap
enqueue(q,root->node->right);
}
while(!isEmpty(q))
{
//dequeing the node
HeapNode* current = dequeue(q);
//getting the max data
if(current->data == maxVal)
{
//adding max data to occurence
occurrences[numOccur] = current->data;
count++;
numOccur++;
}
//enqueing left node of heap
if(current->left != NULL)
{
enqueue(q,current->left);
}
//enqueing right node of heap
if(current->right != NULL)
{
enqueue(q,current->right);
}
}
free(q);//freeing the queue
return count;
}
// Function to find the rightmost leaf
HeapNode* getRightmostLeaf(Heap* root)
{
if(root == NULL)
{
return NULL;
}
//creating queue
Queue* q = createQueue();
enqueue(q,root->node); //enqueue
HeapNode* RightmostNode = NULL;
while(!isEmpty(q))
{
//dequeue the node
RightmostNode = dequeue(q);
//enqueing left node of heap
if(RightmostNode->left != NULL)
{
enqueue(q,RightmostNode->left);
}
//enqueing right node of heap
if(RightmostNode->right != NULL)
{
enqueue(q,RightmostNode->right);
}
}
free(q); //freeing the queue
return RightmostNode;
}
HeapNode* removeAllOccurrences(Heap* root, int numOccur)
{
if (root == NULL )
{
return 0;
}
int count=0;
//getting max data
int maxVal = root->node->data;
Queue* q = createQueue();
//enqueing left node of heap
if(root->node->left != NULL)
{
enqueue(q,root->node->left);
}
//enqueing right node of heap
if(root->node->right != NULL)
{
enqueue(q,root->node->right);
}
while(!isEmpty(q))
{
//dequeue the node
HeapNode* current = dequeue(q);
//getting max data
if(current->data == maxVal)
{
//remove node
removeMax(root,current);
}
//enqueing left node of heap
if(current->left != NULL)
{
enqueue(q,current->left);
}
//enqueing right node of heap
if(current->right != NULL)
{
enqueue(q,current->right);
}
}
free(q); //freeing the queue
//remove node
removeMax(root,root->node);
//maxify heap
max_heapify(root,root->node);
q = createQueue();
//enqueing left node of heap
if(root->node->left != NULL)
{
enqueue(q,root->node->left);
}
//enqueing right node of heap
if(root->node->right != NULL)
{
enqueue(q,root->node->right);
}
while(!isEmpty(q))
{
HeapNode* current = dequeue(q);
max_heapify(root,current);
//enqueing left node of heap
if(current->left != NULL)
{
enqueue(q,current->left);
}
//enqueing right node of heap
if(current->right != NULL)
{
enqueue(q,current->right);
}
}
free(q); //free the queue
return root->node;
}
void removeMax(Heap* root, HeapNode* n_node) {
if (root == NULL || n_node == NULL)
return ;
// Find the rightmost leaf
HeapNode* rightmostLeaf = getRightmostLeaf(root);
//assigfning it to node data
n_node->data = rightmostLeaf->data;
if(rightmostLeaf->parent != NULL)
{
//getting the rightmost node in left of heap
if(rightmostLeaf->parent->left == rightmostLeaf)
{
free(rightmostLeaf->parent->left);
rightmostLeaf->parent->left = NULL;
}
//getting the rightmost node in right of heap
if(rightmostLeaf->parent->right == rightmostLeaf)
{
//free the parent node
free(rightmostLeaf->parent->right);
rightmostLeaf->parent->right = NULL;
}
}
else
{
//free the root node
free(root->node);
root->node = NULL;
}
max_heapify(root,n_node);
//maxifying the heap
if(n_node->left != NULL || n_node->right != NULL)
{
max_heapify(root,n_node);
}
}
void saveData(const char* filename, Heap* root)
{
//saving data to file
FILE* file = fopen(filename, "w");
if (file == NULL) {
printf("Error opening file.\n");
return;
}
//helper function
saveDataHelper(file, root->node);
fclose(file);
}
void saveDataHelper(FILE* file, HeapNode* root) {
if (root == NULL)
return;
//print data to file
fprintf(file, SPECIFIER,"%\n", root->data);
//recursive calling
saveDataHelper(file, root->left);
saveDataHelper(file, root->right);
}
char getChoiceYN()
{
//declaring a variable
char choice;
char lowerChoice;
while (1)
{
//initializing
scanf(" %c", &choice);
//making it lower case
lowerChoice = tolower(choice);
//checking if it has yes or no
if (lowerChoice == 'y' || lowerChoice == 'n')
{
return lowerChoice;
}
else
{
printf("Invalid option. Please type 'y' to restart or 'n' to exit:\n");
}
}
}
