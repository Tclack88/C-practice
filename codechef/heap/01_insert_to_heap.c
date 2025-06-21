//https://www.codechef.com/learn/course/heaps/LIHP01/problems/HEAP04?tab=statement
/*
Note, this problem came with a solution and just required a run, so I ignored that and implemented it myself for practice
INPUT:			OUTPUT:
7
2 3 4 6 1 3 1	1 2 1 6 3 4 3
*/
#include <stdio.h>
int arr[100];
int size = 0;

void printArr(){
    for(int i=0; i<=size; i++)
	    printf("%d ", arr[i]);
	printf("\n");
}

//Function to swap two variables
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// // Function to insert a value into the heap
// void insert(val){
//     arr[size] = val; // Add the value to the end of the array
//     size++; // Increment the size of the heap
//     int cur_index = size-1; // Index of the newly inserted element

//     // Perform heapify-up operation
//     while(cur_index!=0){ // Continue until reaching the root (index 0)
//         int parent_index = (cur_index-1)/2; // Calculate the index of the parent node
//         if(arr[parent_index]>arr[cur_index]){ // If the parent node is greater than the current node
//             swap(&arr[parent_index], &arr[cur_index]); // Swap them
//         }
//         cur_index = parent_index; // Move up to the parent node
//     }
// }

int get_parent(int position){
    int parent_position;
    if (position%2 == 1)
        parent_position = (position-1)/2;
    else
        parent_position = (position-2)/2;
    return parent_position;
}

void insert(int val){
    arr[size] = val;
    int position = size;
    int parent_position = get_parent(position);
    while (arr[position] < arr[parent_position] && position > 0){
        swap(&arr[position], &arr[parent_position]);
        position = parent_position;
        parent_position = get_parent(position);
    }
    size++;
}

int main(void) {
	int n, val;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
	    scanf("%d", &val);
	    insert(val);
	}
	size--;
	printArr();
	return 0;
}
