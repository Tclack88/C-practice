// this is just a structure for reading in the data from main, defining the node
// And all relevant functions
/*
// sample input: 
2
8
1 2 3 3 3 5 1 3
7
1 2 3 2 1 3 2
expected output:
2
3 
*/
#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Definition for singly-linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to build a linked list from an array
struct Node* buildList(int* arr, int n) {
    if (n == 0) {
        return NULL;
    }
    struct Node* head = createNode(arr[0]);
    struct Node* current = head;
    for (int i = 1; i < n; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the linked list memory
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// MY code below here
int countCriticalPoints(struct Node* head) {
    // Write your code here
    struct Node* current = head;
    int cp = 0;
    int c, n, nn;
    while(current->next != NULL && current->next->next != NULL){
        c = current->data;
        n = current->next->data;
        nn = current->next->next->data;
        if( (c<n && nn<n) || (c>n && nn>n) ){
            cp++;
        }
        current=current->next;
    }
    return cp;

}
// my code above here
int main() {
    int T;
    scanf("%d", &T); // Read number of test cases

    while (T--) {
        int N;
        scanf("%d", &N); // Read length of list

        int* arr = (int*)malloc(N * sizeof(int));
        if (arr == NULL) {
             perror("Memory allocation failed");
             return EXIT_FAILURE;
        }

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]); // Read list elements into an array
        }

        struct Node* head = buildList(arr, N); // Build the linked list

        // Call your countCriticalPoints function
		//printList(head);
        int count = countCriticalPoints(head);

        // Print the resulting list
        printf("%d\n",count);

        // Free the memory allocated for the list
        // Note: freeList should be called on the head returned by removeDuplicates
        // assuming removeDuplicates might change the head or rearrange nodes.
        // If your removeDuplicates only modifies next pointers and uses free()
        // on removed nodes, calling freeList(newHead) is correct.
        freeList(head);
        free(arr); // Free the temporary array
    }

    return 0;
}
