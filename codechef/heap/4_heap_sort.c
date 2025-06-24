// Work In Progress
#include <stdio.h>

int print_heap(int heap[], int size){
    for (int i=0; i<size; i++)
        printf("%d ",heap[i]);
    printf("\n");
}

int get_parent(int child){
    if (child % 2 == 0)
        return (child-2)/2;
    return (child-1)/2;
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int heap[], int size){
    while (size > 0){
        int child = size;
        int parent = get_parent(child);
		printf("parent: %d, child: %d\n",parent, child);
        while (heap[child] < heap[parent] && parent >= 0){
            swap(&heap[child],&heap[parent]);
            child = parent;
            parent = get_parent(child);
			printf("(inside) parent: %d, child: %d\n",parent, child);
        }
        size--;
    }
}

int main() {
    int size;
    scanf("%d",&size);
    int heap[size];
    for (int i=0; i<size; i++)
        scanf("%d",&heap[i]);
    int N = size-1;
    heapify(heap,N);
    while(N--){
        swap(&heap[0],&heap[N]);
        heapify(heap,N);
    }
    print_heap(heap, size);
}
