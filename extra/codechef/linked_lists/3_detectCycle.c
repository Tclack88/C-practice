#include <stdio.h>
#include <stdlib.h>
/*
Tests
3   <---- # of tests cases
2   <--- next test case has 2 digits
8 5 <--- the two digits
1   <--- expected answer index (starting from 1 instead of 0)
2
5 9
1
3
5 6 8
2
*/

// Definition for singly-linked list.
typedef struct Node {
    int val;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list (useful for debugging)
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the linked list (be careful with cycles!)
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to detect the cycle (you will implement this)
Node* detectCycle(Node* head); // Your function declaration

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        int *A = (int*)malloc(N * sizeof(int));
        Node *head = NULL;
        Node *tail = NULL;
        Node **nodes = (Node**)malloc(N * sizeof(Node*)); // To store addresses of nodes

        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            Node *newNode = createNode(A[i]);
            nodes[i] = newNode; // Store the address of the created node
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        int cycle_start_index;
        scanf("%d", &cycle_start_index);
        cycle_start_index--; // to take into account that weird start from 1 index

        // Create the cycle
        if (N > 0 && cycle_start_index >= 0 && cycle_start_index < N) {
            tail->next = nodes[cycle_start_index];
        } else if (N > 0 && cycle_start_index == 0) {
            // Handle the case where N=1 and cycle_start_index is 0
            // The single node points to itself
            if (head != NULL) {
                 head->next = head;
            }
        }


        // Call your detectCycle function
        Node* cycleStartNode = detectCycle(head);

        if (cycleStartNode != NULL) {
            printf("%d\n", cycleStartNode->val);
        } else {
            // You can print something to indicate no cycle, or adjust based on how you want to test
            // printf("No cycle\n");
        }

        // IMPORTANT: Freeing a list with a cycle is tricky.
        // For this problem, you might not need to free if you are just testing the detectCycle function.
        // If you do need to free, you'll need a more complex approach that breaks the cycle first.
        // For testing, you can skip freeing for simplicity, but in a real application, memory management is crucial.
        free(A);
        free(nodes);
    }
    return 0;
}

// Your detectCycle function goes here
typedef struct Node NODE;
NODE *detectCycle(NODE *head){
    // Floyd's Cycle Detection Algorithm
    struct Node* s = head; //slow
    struct Node* f = head; //fast
    s = s->next;
    f = f->next->next;
    while(f != s){
        s = s->next;
        f = f->next->next;
    } // finds first meet point
    f = head;
    while (f!=s){
        s = s->next;
        f = f->next;
    }
    return f;
}
