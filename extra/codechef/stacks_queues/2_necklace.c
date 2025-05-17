#include <stdio.h>
#include <stdlib.h>
// IMPLEMENTED FROM SCRATCH!
/*
INPUT
2
5 3
1 5 3 4 2
6 5
10 1 2 9 8 2

OUTPUT
4 2 1 5 3
2 10 1 2 9 8
*/

struct Node{
	int value;
	struct Node* next;
};

struct Node* createNode(int value){
	struct Node* newnode = malloc(sizeof(struct Node));
	newnode->value = value;
	newnode->next = NULL;
	return newnode;
}

void printQ(struct Node* head){
	struct Node* current = head;
	while (current != NULL){
		printf("%d ",current->value);
		current = current->next;
	}
	printf("\n");
}

int main(){
	struct Node* Q;
	int T, size, idx, val;
	int arr[100002]; // 10^5 max size
	scanf("%d",&T);
	while (T--){
		struct Node* head;
		struct Node* tail;
		scanf("%d %d", &size, &idx);
		for (int i=0; i <size; i++){
			scanf("%d", &val);
			if (i==0){
				head = createNode(val);
				tail = head;
			}
			else{
				struct Node* next = createNode(val);
				tail->next = next;
				tail = next;
			}

		}
		if (size == 1)
			printf("%d\n",head->value);
		else{
			for (int j=0; j<idx; j++){
				struct Node* temp = head;
				head = head->next;
				tail->next = temp;
				tail = temp;
				tail->next = NULL;
			}
			printQ(head);
		}
	}
	return 0;
}
