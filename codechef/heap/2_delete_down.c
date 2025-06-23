// https://www.codechef.com/practice/course/heaps/HEAPF/problems/HEAPEDU2
/*
delete from top, then print down.
INPUT:		OUTPUT:
5
1			2 3 4 5
2			3 5 4
4			4 5
5			5
3
*/
#include <stdio.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print(int heap[], int size){
    for (int i=0; i<size; i++)
        printf("%d ",heap[i]);
    printf("\n");
}

void delete_down(int heap[], int top, int end){
    int parent = top;
    int c1 = 2*parent + 1;
    int c2 = 2*parent + 2;
    if (heap[c1] <= heap[c2]){
        if (c1 < end && heap[parent] > heap[c1]){
            swap(&heap[parent],&heap[c1]);
            delete_down(heap, parent, end);
        }
    }
    else if (heap[c2] < heap[c1]){
        if (c2 < end && heap[parent] > heap[c2]){
            swap(&heap[parent],&heap[c2]);
            delete_down(heap, parent, end);
        }
    }
}

int main() {
	int N;
	scanf("%d",&N);
	int heap[N];
	for (int i=0; i<N; i++){
	    scanf("%d",&heap[i]);
	}
    while(N--){
    	swap(&heap[0],&heap[N]);
        delete_down(heap, 0, N);
	    print(heap, N);
    }
    return 0;
}
