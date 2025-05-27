#include <stdio.h>
#include <stdlib.h>
// codechef challenge from here: https://www.codechef.com/practice/course/stacks-and-queues/STAQUEF/problems/DSCPPAS269
/* find the "next biggest peak". Using stack architecture to run it the most efficiently
sample input:   output:
4
6 5 3 6			-1 6 6 -1
sample input:   output:
2
1 2				2 -1
*/

void printArr(int* arr, int n){
	for(int i=0; i<n; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

struct Node{
    int val;
    int idx;
    struct Node* last;
    struct Node* next;
};

struct Node* createNode(int idx, int val){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->idx = idx;
	newNode->last = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to find the next higher peak for each element in heights
int* next_higher_peak(int* heights, int n) {
    int* result = malloc(sizeof(int)*n);
    
    struct Node* stack;
    struct Node* tail;
    struct Node* newNode;
    int top = -1;
    for(int i=0; i<n; i++){
        if (i==0){
            stack = createNode(i, heights[i]);
            tail = stack;
            top++;
        }
        else if (heights[i] < tail->val){
            newNode = createNode(i, heights[i]);
			newNode->last = tail;
            tail->next = newNode;
			tail = newNode;
            top++;
        }
        else{
            while(heights[i] > tail->val && top >=0){ //top -> node->last != NULL?
                result[tail->idx] = heights[i];
				if (tail->last == NULL){// back at the front, cannot "remove tail"
					tail = stack;		// otherwise, nowhere for later nodes to
				}						// be added to
				else{
                	tail = tail->last;
                	free(tail->next);
                	tail->next = NULL;
				}
                top--;
            }
            newNode = createNode(i, heights[i]);
			newNode->last = tail;
            tail->next = newNode;
			tail = newNode;
            top++;
        }
    }
	while (top >=0){
		if (tail->last == NULL){
			result[tail->idx] = -1;
			free(tail);
			top--;
		}
		else {
			result[tail->idx] = -1;
        	tail = tail->last;
        	free(tail->next);
        	tail->next = NULL;
        	top--;
		}
	}
    return result;
}

// My code above. Main function below provided //
int main() {
    int n;
    // Take the size of the heights array as input
    scanf("%d", &n);
    
    int* heights = (int*)malloc(n * sizeof(int));

    // Take the heights array elements as input
    for (int i = 0; i < n; ++i) {
        scanf("%d", &heights[i]);
    }

    // Get the next higher peaks
    int* result = next_higher_peak(heights, n);

    // Print the result
    for (int i = 0; i < n; ++i) {
        printf("%d ", result[i]);
    }

    // Free allocated memory for heights and result arrays
    free(heights);
    free(result);

    return 0;
}
