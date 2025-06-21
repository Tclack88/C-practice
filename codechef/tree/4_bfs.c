// https://www.codechef.com/learn/course/trees/TREES/problems/BFS?tab=statement
/* BFS breadth first search
re-implemented the n-ary tree structure from scratch for practice, created the BFS logic using a queue. Very clever, didn't figure it out myslef
INPUT:					OUTPUT
10					1 2 3 4 5 6 7 8 9 10
1 2
1 3
1 4
2 5
5 9
3 6
3 7
6 10
4 8
*/
#include <stdio.h>
#include <stdlib.h>

#define  MAXSIZE 100000

struct Node{
    int val;
    struct Node* nextChild;
    struct Node* nextSibling;
};

struct Queue{
    struct Node* items[MAXSIZE];
    int front;
    int back;
};

struct Queue* startQueue(){
    struct Queue* Q = malloc(sizeof(struct Queue));
    Q->front = -1;
    Q->back = 0;
    return Q;
}

void enqueue(struct Queue* Q, struct Node* node){
    Q->items[Q->back] = node;
    Q->back++;
}

struct Node* dequeue(struct Queue* Q){
    Q->front++;
    struct Node* node = Q->items[Q->front];
    return node;
}


struct Node* createNode(int val){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->nextChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void addEdge(struct Node* node, int u, int v){
    struct Node* newNode = createNode(v);
    struct Node* current = node;
    struct Node* nextChild = current->nextChild;
    struct Node* nextSibling ;
    if (current->val == u){
        if (current->nextChild == NULL){
            current->nextChild = newNode;
            return;
        }
        else{
            nextSibling = current->nextChild;
            while (nextSibling->nextSibling != NULL)
                nextSibling = nextSibling->nextSibling;
            nextSibling->nextSibling = newNode;
            return;
        }
    }
    else{
        if (current->nextChild != NULL)
            addEdge(current->nextChild,u,v);
        if (current->nextSibling != NULL)
            addEdge(current->nextSibling,u,v);
    }
}

void bfs(struct Node* node, int N){
    struct Queue* Q = startQueue();
    enqueue(Q,node);
    struct Node* next;
	struct Node* free_me; // tmp storage pointer for freeing
    // struct Node* nextSibling
    while (Q->front < N-1){ // previously failed with N
        next = dequeue(Q);	// but this test case is not
		free_me = next;    //0-counted, so when equal
        printf("%d ",next->val); // to N-1, it's past the
        next = next->nextChild;  // end and tries to dequeue
		free(free_me);
        while (next != NULL){  
            enqueue(Q,next);
            next = next->nextSibling;
        }
    }
}

int main() {
    int N,u,v;
    scanf("%d",&N);
	// initialize first node with first item scanned, then
    // add the edge scanned
    scanf("%d %d", &u, &v);
    struct Node* tree = createNode(u);
    addEdge(tree,u,v);
    while(scanf("%d %d",&u,&v)==2)
        addEdge(tree,u,v);
    bfs(tree, N);
    return 0;
}
