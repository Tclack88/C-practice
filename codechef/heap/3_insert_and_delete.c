// Work in progress
#include <stdio.h>

void heap_down(){
    
}

void add(int heap[], int val, int size){
    heap[size] = val;
    
}

void delete_down(){
    
}

int main() {
    int N;
    char op;
    scanf("%d",&N)
    int heap[N]; // max size
    int size=0;
    while(N--){
        scanf("%c",&op)
        if (op == "+"){
            scanf("%d",&val);
            add(heap, val, size++);
        }
        else{
            swap(heap[0],heap[--size]);
            delete_down();
        }
        printf("%d\n",heap[size-1]); // print last element
    }
	return 0;
}
