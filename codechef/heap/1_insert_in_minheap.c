// https://www.codechef.com/practice/course/heaps/HEAPF/problems/HEAPEDU1
/*
build a min heap and print it as it builds. 
INPUT:			OUTPUT:
5
5  				5 
4 				4 5 
3				3 5 4 
2				2 3 4 5 
1				1 2 4 5 3 
*/
#include <stdio.h>
void print(int arr[],int len){
    for (int i=0; i<len; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int get_parent(int heap[], int index){
    if (index%2 ==0)
        return (index-2)/2;
    return (index-1)/2;
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insert(int heap[], int val, int child){
    heap[child] = val;
    int parent = get_parent(heap,child);
		//printf("parent: %d (%d), child: %d(%d)\n",heap[parent],parent,heap[child],child);
    while(parent >= 0 && heap[parent] > heap[child]){
        swap(&heap[parent],&heap[child]);
        child = parent;
        parent = get_parent(heap, child);
		//printf("in loop, parent: %d (%d), child: %d(%d)\n",heap[parent],parent,heap[child],child);
    }
}

int main() {
	int size, val;
	scanf("%d",&size);
	int heap[size];
	for (int i=0; i<size; i++){
	    scanf("%d",&val);
	    insert(heap, val, i);
	    print(heap,i+1);
	}
	return 0;
}
