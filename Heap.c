
//including userdefined function(header files)
#include "heap_lib.h"
const char* INPUT_FILE = "myHeapData_CS500.csv";
const char* OUTPUT_FILE = "OutputHeap_file.csv";



int main()
{
//declaring variables
srand(time(NULL));
char choice;
Heap* heap;
//creating a heap.
heap = createHeap();
heap->node = getData(INPUT_FILE);
saveData(OUTPUT_FILE,heap);
do
{
//declaring variables
int num_Occue;
dtype* occurrences = (dtype*)malloc(10 * sizeof(dtype));
//calling all occurences
num_Occue = getAllOccurrences(heap,occurrences);
//printing all the occurences
int i;
for ( i = 0; i < num_Occue - num_Occue + 1; i++)
{
occurrences[i] = heap->node->data;
printf("\nThe Largest element is %ld and it occured %d times!\
n",occurrences[i] , num_Occue);
}
//asking user to stimulate again
printf("\nDo you want to see the simulation again? (y/n): ");
choice = getChoiceYN();
if (choice == 'y')
{
//removing all occurences of heap node.
heap->node = removeAllOccurrences(heap, num_Occue);
printf("\nThe largest element has been removed from the heap.");
// printHeap(heap->node);
}
//freeing the memory
free(occurrences);
}
while(choice=='y');
//freeing heap
free(heap);
//end message
printf("\nThanks for searching. Come back if needed!");
// end the program
printf("\nProgram ended.\n");
return 0;
}

