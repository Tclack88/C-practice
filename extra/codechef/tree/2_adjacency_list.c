//https://www.codechef.com/learn/course/trees/TREES/problems/DSCPP82?tab=statement
/*
An implementation of displaying an adjacency list
Strategy: make an array where each index corresponds to the nodes of the tree. Use a linked list data structure to append as necessary to that index of the array
INPUT:			OUTPUT:
6				0 1 2
0 1				1 3 4
0 2				2 5
1 3				3
1 4				4
2 5				5
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Used with memcopy for commented out code below

struct Node{
    int val;
    struct Node* next;
};

struct Node* startNode(int val){
    struct Node* newNode = malloc(sizeof(struct Node));
	newNode -> val = val;
	newNode -> next = NULL;
	return newNode;
}

struct Node* addNode(struct Node* NodeIn, int val){
    struct Node* newNode = startNode(val);
    struct Node* tail = NodeIn;
    while (tail -> next != NULL)
        tail = tail->next;
    tail -> next = newNode;
    return NodeIn;
}

void printNodeArr(struct Node* arr[], int size){
	for (int i=0; i<size; i++){
		struct Node* next = arr[i];
		while (next != NULL){
			printf("%d ",next->val);
			next = next->next;
		}
		printf("\n");
	}
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* arr[n];
    int j,val;
	for (int i=0; i<n; i++) // both work
        arr[i] = startNode(i);
    while(scanf("%d %d",&j,&val) == 2)
        arr[j] = addNode(arr[j],val);
	printNodeArr(arr,n);
    return 0;
}

/* This is another version (depending on what is needed)
OUTPUT:
1 2
3 4
5
#include <stdio.h>
#include <stdlib.h>


struct Node{
    int val;
    struct Node* next;
};


struct Node* addNode(struct Node* NodeIn, int val){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode -> val = val;
    newNode -> next = NULL;
    if (NodeIn == NULL)
        return newNode;
    struct Node* tail = NodeIn;
    while (tail -> next != NULL)
        tail = tail->next;
    tail -> next = newNode;
    return NodeIn;
}

void printNodeArr(struct Node* arr[], int size){
    for (int i=0; i<size; i++){
        struct Node* next = arr[i];
        while (next != NULL){
            printf("%d ",next->val);
            next = next->next;
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* arr[n];
    for (int i=0; i< n; i++)
        arr[i] = NULL;
    int j,val;
    while(scanf("%d %d",&j,&val) == 2)
        arr[j] = addNode(arr[j],val);
    printNodeArr(arr,n);
    return 0;
}
*/
