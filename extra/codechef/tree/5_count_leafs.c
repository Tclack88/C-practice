// https://www.codechef.com/learn/course/trees/TREES/problems/DSCPP86
/*
count leafs
INPUT:					OUTPUT:
8							3
0 1
0 2
1 3
1 4
2 5
3 6
5 7
*/
#include <stdio.h>
#include <stdlib.h>

int leaf_count = 0;

struct Node{
    int val;
    struct Node* nextChild;
    struct Node* nextSibling;
};

struct Node* createNode(int val){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->nextChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}


void dfs_count_leafs(struct Node* node, int is_counting_child){
    if (node == NULL){
        if (is_counting_child == 1){
            leaf_count++;
        }
        return;
	}
    dfs_count_leafs(node->nextChild, 1);
    dfs_count_leafs(node->nextSibling,0);
}

void addEdge(struct Node* current, int u, int v){
    struct Node* newNode = createNode(v);
    if (current->val == u){
        if (current->nextChild == NULL){
            current->nextChild = newNode;
            return;
        }
        else{
            struct Node* lastSibling = current->nextChild;
            while (lastSibling->nextSibling != NULL)
                lastSibling = lastSibling->nextSibling;
            lastSibling->nextSibling = newNode;
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


int main() {
    int N,u,v;
    scanf("%d",&N);
	// initialize first node with first item scanned, then
	// add the edge scanned
	scanf("%d %d", &u, &v);
    struct Node* tree = createNode(u);
    addEdge(tree,u,v);
    while( scanf("%d %d",&u, &v) == 2)
        addEdge(tree,u,v);
    dfs_count_leafs(tree, 0);
    printf("%d\n",leaf_count);
    return 0;
}
