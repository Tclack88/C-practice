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
            printf("at value u=%d, adding new child\n",u);
            current->nextChild = newNode;
			printf("\t...success\n");
            return;
        }
        else{
            printf("u (%d) already has child, making sibling...\n",u);
            struct Node* lastSibling = current->nextChild;
            while (lastSibling->nextSibling != NULL){
                lastSibling = lastSibling->nextSibling;
            }
            lastSibling->nextSibling = newNode;
            return;
        }
    }
    else if (current->nextChild == NULL){
        printf("creating new leaf %d\n",v);
        current->val = u;
        current->nextChild = newNode;
        return;
    }
    else{
        addEdge(current->nextChild, u, v);
    }
}

int main() {
    struct Node* tree;
    int N,u,v;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d %d",&u, &v);
        addEdge(tree,u,v);
    }
    dfs(tree);
    

    return 0;
}

