// https://www.codechef.com/learn/course/trees/TREES/problems/DSADFS?tab=statement
/* depth first search
two challenges exist here:	1. Building and filling a general n-node tree structure
							2. doing the depth first search (much easier in comparison to the initial tree build

INPUT:									OUTPUT
10 <-- size (unecessary)			
1 2 <--- node, next node pairs
1 5		(eg. node 1 has children)
1 9				  |					1 2 3 4 5 6 7 8 9 10
2 3			------------
3 4			|	 |		|
5 6			2    5		9
6 7
5 8
9 10
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXX 100005

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


void dfs(struct Node* node){
    if (node == NULL)
        return;
    printf("%d ",node->val);
    dfs(node->nextChild);
    dfs(node->nextSibling);
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
	// could made return type of add Edge int (0 or 1 for success/fail
	// this could prevent needless recursive search
    else{ 
		if (current->nextChild != NULL)
			addEdge(current->nextChild,u,v);
		if (current->nextSibling != NULL)
        	addEdge(current->nextSibling,u,v);
    }
}

int main() {
    //struct Node* tree = createNode(1);
    int N,u,v;
    scanf("%d",&N);
	// initialize first node with first item scanned, then
    // add the edge scanned
	scanf("%d %d", &u, &v);
    struct Node* tree = createNode(u);
	addEdge(tree,u,v);
	while( scanf("%d %d",&u, &v) == 2)
        addEdge(tree,u,v);
    dfs(tree);
    return 0;
}
