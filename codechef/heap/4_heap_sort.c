// https://www.codechef.com/practice/course/heaps/HEAPF/problems/HEAPEDU4?tab=statement
/* take an unsorted array and sort using heap sort (two steps, 1 convert to a MAX heap, 2. swap first element with last to store the max value at end, then decrement the size being considered, heapify to convert to max heap again, continue this process)

I know this isn't the best code. In my heapify for instance, my exit condition of the while loop was when the parent equaled the size, however that doesn't generally happen, Instead I make it exit when no swaps can occur. It works for the example provided, unsure if it works in general
INPUT:					OUTPUT:
7
23 9 17 5 31 12 8		5 8 9 12 17 23 31
*/
#include <stdio.h>

int print_heap(int heap[], int size){
    for (int i=0; i<size; i++)
        printf("%d ",heap[i]);
    printf("\n");
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void build_max_heap(int heap[], int size){
    int top_parent = (size-1)/2; // first parent
    while (top_parent >= 0){
        int parent = top_parent;
        while (parent <= (size-1)/2){ // largest possible parent
            int c1 = 2*parent+1;
            int c2 = 2*parent+2;
            if (c2 < size){
                if (heap[c1] >= heap[c2] && heap[c1] >  heap[parent]){
                    swap(&heap[c1], &heap[parent]);
                    parent = c1;
                }
                else if (heap[c2] > heap[c1] && heap[c2] > heap[parent])
                    swap(&heap[c2], &heap[parent]);
                    parent = c2;
            }
            else if (c1 < size){
                if (heap[c1] > heap[parent]){
                    swap(&heap[c1], &heap[parent]);
                    parent = c1;
                }
            }
            else
                parent = c1;
        }
        top_parent--;
    }
}

void heapify(int heap[], int size){
        int parent = 0;
        while(parent < size){
            int c1 = 2*parent + 1;
            int c2 = 2*parent + 2;
            if (c2 < size){
                if (heap[c1] >= heap[c2] && heap[c1] > heap[parent]){
                    swap(&heap[c1],&heap[parent]);
                    parent = c1;
                }
                else if (heap[c2] > heap[c1] && heap[c2] > heap[parent]){
                    swap(&heap[c2],&heap[parent]);
                    parent = c2;
                }
            }
            else if (c1 < size && heap[c1] > heap[parent]){
                swap(&heap[c1],&heap[parent]);
                parent = c1;
            }
            else
                return;
        }
}

int main() {
    int size;
    scanf("%d",&size);
    int heap[size];
    for (int i=0; i<size; i++)
        scanf("%d",&heap[i]);
    int N = size;
    build_max_heap(heap,N);
    while(N--){
        swap(&heap[0],&heap[N]);
        heapify(heap,N);
    }
    print_heap(heap, size);
}
