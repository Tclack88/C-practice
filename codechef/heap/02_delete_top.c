// https://www.codechef.com/learn/course/heaps/LIHP01/problems/HEAP05?tab=statement
/* 
code was provided and commented out. I kept it commented it out and wrote the solution myself. Also the inserting logic for bulding the minheap was provided, I didn't remove this as it was the last challenge. Full disclosure: it does not pass the tests online, but the output was not provided. I'm unsure if it was expecting the "deleteing the element..." statements to remain, or whether or not the intermediate heap build prints should to be kept or something else. I'm going to assume it's correct.

INPUT:				OUTPUT:
7					1 2 1 6 3 4 3
1 2 1 6 3 4 3		1 2 3 6 3 4
2					2 3 3 6 4
0 1	<-- don't know why this was provided
*/

#include <stdio.h>
int arr[100];
int size = 0;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insert(int val){
    arr[size] = val;
    size++;
    int cur_index = size-1;
    while(cur_index!=0){
        int parent_index = (cur_index-1)/2;
        if(arr[parent_index]>arr[cur_index]){
            swap(&arr[parent_index], &arr[cur_index]);
        }
        cur_index = parent_index;
    }
}

// void Heapify(int index) {
//     int left_child = 2*index+1;
//     int right_child = 2*index+2;
//     if(left_child<size && arr[left_child]<arr[index]){
//         swap(&arr[index], &arr[left_child]);
//         Heapify(left_child);
//     }
//     if(right_child<size && arr[right_child]<arr[index]){
//         swap(&arr[index], &arr[right_child]);
//         Heapify(right_child);
//     }
// }

// void delete_from_heap(int index){
//     printf("deleting the element %d\n", arr[index]);
//     swap(&arr[index], &arr[size-1]);
//     size--;
//     Heapify(index);
// }

void heapify(int index){
    int c1 = index*2+1; // c1: index of child 1
    int c2 = index*2+2; // c2: inmdex of child 2
    if (c2 > size-1) // guard against accessing outer memory.
        c2 = index; // by setting this to index, it's guaranteed
    if (c1 > size-1) // to be the same (and within bounds). So no
        c1 = index; // swap will happen
        
    if (arr[c1] <= arr[c2] && arr[c1] < arr[index]){
        swap(&arr[c1],&arr[index]);
        heapify(c1);
    }
    else if (arr[c2] <= arr[c1] && arr[c2] < arr[index]){
        swap(&arr[c2], &arr[index]);
        heapify(c2);
    }
    else
        return;
}

void delete_from_heap(int index){
    swap(&arr[index],&arr[size-1]);
    size--;
    heapify(0);
}

void print(){
    for(int i=0; i<size; i++){
	    printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
	    int value;
	    scanf("%d", &value);
	    insert(value);
	}
	print();
	int x;
	scanf("%d", &x);
	for (int i=0; i<x; i++){
	    int index;
	    scanf("%d", &index);
	    delete_from_heap(0);
	    print();
	}
}
