#include "search_lib.h"
//declaring input and output files
const char* INPUT_FILE = "myData_CS500.csv";
const char* OUTPUT_FILE = "Output_file.csv";
int main()
{
//declaring variables
srand(time(NULL));
char choice='y';
//creating the tree
Treenode* root = createTree();
root = getData(INPUT_FILE);
//printing the tree
//printTree(root);
saveData(OUTPUT_FILE,root);
bool isValidBST = validateTree(root);
//printf("\n%d",isValidBST);
if(isValidBST == 1)
{
do
{
//declaring variables
dtype* occurrences = (dtype*)malloc(10 * sizeof(dtype));
dtype* numOccurrences = (dtype*)malloc(sizeof(dtype));
*numOccurrences = 0;
//generating the random elemnent
dtype random_target_element = rand() % (2000-0 + 1) + 0;
printf("\nSearching for %ld:",random_target_element);// Printingrandom element
//getting first occurrence
dtype FirstOccurrence_index =
getFirstOccurrence(random_target_element,root);
//getting last occurrence
dtype LastOccurrence_index =
getLastOccurrence(random_target_element,root->left);
//getting All occurrence
getAllOccurrences(random_target_element,root,occurrences,numOccurrences);
//if element is not found
if (FirstOccurrence_index == NOT_FOUND || LastOccurrence_index ==
NOT_FOUND )
{
printf("\nElement not found.");
}
else
{
//print all the occurrences
printf("\nFirst occurrence of %ld is at index %ld.\n",
random_target_element, FirstOccurrence_index);
printf("\nLast occurrence of %ld is at index %ld.\n",
random_target_element, LastOccurrence_index);
if(*numOccurrences > 0)
{
printf("\nAll Occurrences: ");
int i;
for(i=0; i < *numOccurrences ;i++)
{
printf("%d",occurrences[i]);
if( i< (*numOccurrences) - 1)
{
printf(", ");
}
}
}
//deallocate memory
free(occurrences);
free(numOccurrences);
}
//check if user want to search again
printf("\nDo you want to simulate the search again [y|n]? ");
choice = getChoiceYN();
}while(choice=='y');
}
//freeing the root
free(root);
//end message
printf("\nThanks for searching. Come back if needed!");
// end the program
printf("\nProgram ended.\n");
return 0;
}

