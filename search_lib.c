#include "search_lib.h"
//declaring input and output files
//creating a tree
Treenode* createTree()
{
Treenode* root = NULL;
return root;
}
//printing the tree
void printTree(Treenode* root)
{
if(root == NULL)
{
return;
}
//printing via preorder traversal
printf(SPECIFIER," ",root->data);
//recursive calling for left and right sub tree
printTree(root->left);
printTree(root->right);
}
//adding the node to the tree
Treenode* addNode(Treenode* root, dtype data, int index)
{
if(root == NULL)
{
//if tree is null then add a newnode
Treenode* newNode = (Treenode*)malloc(sizeof(Treenode));
newNode->data=data;
newNode->index=index;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}
//adding data to left if data is lesser than root of data.
if(data < root->data)
{
root->left = addNode(root->left,data,index);
}
else
{
//adding data to right if data is greater than root of data.
root->right = addNode(root->right,data,index);
}
return root;
}
Treenode* getData(const char* filename)
{
//getting the data from the file.
Treenode* root = NULL; // Initialize an empty tree
int index = 0;
char line[100];
//opening the file
FILE* file1 = fopen(filename,"r");
if(file1 == NULL)
{
printf("No such file or directory");
return;
}
//get the data from the file
while(fgets(line, sizeof(line), file1))
{
dtype file_data = atof(line);
// printf("\nfile data %d",file_data);
root = addNode(root,file_data,index);
index++;
}
//closing the file.
fclose(file1);
return root;
}
//getting the first occurence
int getFirstOccurrence(dtype element, Treenode *root)
{
if (root == NULL)
{
return NOT_FOUND;
}
while (root != NULL)
{
//if element is found in tree return index
if(element == root -> data)
{
return root -> index;
}
else if (element < root -> data)
{
//else find data in left of tree
root = root -> left;
}
else
{
//else find data in right of tree
root = root -> right;
}
}
return NOT_FOUND;
}
//getting the last occurences
int getLastOccurrence(dtype element, Treenode* root)
{
if (root == NULL) {
printf("\nTree is Empty.");
return NOT_FOUND;
}
//getting the current node.
Treenode* current = root;
int lastIndex = -1; // Initialize last index to -1
while (current != NULL)
{
//checking element on left of the tree
if (element < current->data) {
current = current->left;
}
//checking element on right of the tree
else if (element > current->data)
{
current = current->right;
}
else
{
// Check for repeated occurrences on the left side
Treenode* leftSubtree = current->left;
while (leftSubtree != NULL)
{
//checking elementin left subtree
if (leftSubtree->data == element)
{
lastIndex = leftSubtree->index; // Update last index
leftSubtree = leftSubtree->left;
} else
{
leftSubtree= NULL; // No more occurrences on the left side
}
}
lastIndex = current->index; // Update last index with current node's

current = current->right; // Continue searching for further occurrences
}
}
return lastIndex; // Return the last index of the element in the tree
}
//helper function for getting all occurences
void getAll(dtype element, Treenode *root, dtype *occurrences, dtype
*numOccurrences)
{
if (root != NULL)
{
if (element == root->data)
{
//if elemnt is found then add to that occurences array
occurrences[*numOccurrences] = root->index;
(*numOccurrences)++;
}
//recursive calling
getAll(element, root->left, occurrences, numOccurrences);
getAll(element, root->right, occurrences, numOccurrences);
}
}
void getAllOccurrences(dtype element, Treenode *root, dtype *occurrences, dtype
*numOccurrences)
{
//finding all the occurences
*numOccurrences = 0;
getAll(element, root, occurrences, numOccurrences);
}
void push(Stack* stack, Treenode* node)
{
//pushing to stack
Node* newNode = (Node*) malloc(sizeof(Node));
newNode->data = node->data;
newNode->next = stack->head;
//adding newnode to stack
stack->head = newNode;
stack->top++;
}
//pop function
Treenode* pop(Stack* stack)
{
if (stack->top == -1)
{
return NULL; // Stack is empty
}
//temp node to pop the element
Node* tempNode = stack->head;
stack->head = tempNode->next;
stack->top--;
//creating node
Treenode* poppedNode = malloc(sizeof(Treenode));
//add the data to temp node
poppedNode->data = tempNode->data;
poppedNode->left = NULL;
poppedNode->right = NULL;
//free the node
free(tempNode);
return poppedNode;
}
//validate the tree
bool validateTree(Treenode* root)
{
if (root == NULL)
{
return true; // An empty tree is a valid BST
}
//creating the stack
Stack stack;
stack.top = -1;
stack.head = NULL;
//getting the tree
Treenode* current = root;
Treenode* previous = NULL;
while (current != NULL || stack.top != -1)
{
// Traverse the left subtree
while (current != NULL)
{
//push the node to stack
push(&stack, current);
current = current->left;
}
// Pop the top node
current = pop(&stack);
previous = current->right;
// Check if the current node's data is smaller than or equal to theprevious node's data
if (previous != NULL && current->data <= previous->data)
{
return false; // Tree is not a BST
}
// Move current
current = current->right;
}
return true;
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
//save the data to file
void saveData(const char* filename,Treenode* root)
{
FILE* file2 = fopen(filename,"a");
if (file2 == NULL) {
printf("Error opening file.\n");
return;
}
if (root != NULL)
{
// Write data to the file in preorder
fprintf(file2, SPECIFIER,"\n", root->data);
//recursive call to data
saveData(filename,root->left);
saveData(filename,root->right);
}
fflush(file2); //flushing all the data
fclose(file2); //close the file
}



