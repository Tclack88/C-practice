// https://www.codechef.com/practice/course/heaps/HEAPF/problems/HEAPEDU3
/*
All together, with a small twist. Adding/building the heap and then deleting with the input being "+ x" (to add some digit x to the heap, or "-" to indicate removing the last element
INPUT:		OUTPUT:
7				4
+ 4				6
+ 6				6
+ 6				6
+ 5				6
-				5
-				4
-				
*/
#include <stdio.h>

void swap(int* a, int*b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_heap(int heap[], int size){
	for (int i=0; i<size; i++)
		printf("%d ",heap[i]);
	printf("\n");
}

int get_parent(int child){
	if (child % 2 == 0)
        return (child-2)/2;
    return (child-1)/2;
}

void add(int heap[], int val, int size){
    heap[size] = val;
	int child = size; // index of child
	int parent = get_parent(child);
	while (parent >=0 && heap[parent] > val){
		swap(&heap[child],&heap[parent]);
		child = parent;
		parent = get_parent(child);
	}
}

void heap_down(int heap[],int parent, int size){
	int c1 = 2*parent + 1;
	int c2 = 2*parent + 2;
	if (c1 < size){
		if (heap[c1] <= heap[c2] && heap[c1]<heap[parent]){
			swap(&heap[c1],&heap[parent]);
			heap_down(heap,c1,size);
		}
		else if (heap[c2] < heap[c1] && heap[c2]<heap[parent]){
			swap(&heap[c2],&heap[parent]);
			heap_down(heap,c2,size);
		}
	}
}

int main() {
    int N, val;
    char op;
    scanf("%d",&N);
    int heap[N]; // max size
    int size=0;
    while(N--){
        scanf(" %c",&op); // leading space to ignore white space 
        if (op == '+'){	  //(space after = undefined behavior)
        	scanf("%d",&val);
            add(heap, val, size++);
        }
        else{ // op == '-'
            swap(&heap[0],&heap[--size-1]);
            heap_down(heap, 0, size);
        }
		print_heap(heap,size);
        printf("\tlast element: %d\n",heap[size-1]); // print last element */
    }
	return 0;
}
