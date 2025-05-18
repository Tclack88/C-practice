// WRITTEN FROM SCRATCH!
// https://www.codechef.com/practice/course/stacks-and-queues/STAQUEF/problems/STONE_PILE
/*
INPUT:
3
3
-5 0 5
4
-1 -3 2 4
6
-100000 0 0 100000 -1000000 1000000
OUTPUT:
0 -5
1 2
1 0
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node* next;
};

// make global for cleaner functions//
struct Node* head;
struct Node* tail;
struct Node* nextNode;

struct Node* createNode(int val){
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->value = val;
	newNode->next = NULL;
	return newNode;
}

void printQ(struct Node* Q){
	struct Node* current = Q;
	while(current != NULL){
		printf("%d ",current->value);
		current = current->next;
	}
	printf("\n");
}

void move1(){
	tail->next = head;
	struct Node* tmp = head->next;
	head->next = NULL;
	head = tmp;
	tail = tail->next;
}

void move2(){
	struct Node* tmp = head;
	head = head->next;
	free(tmp);
}

void play1(){
	move1();
	move2();
}

void play2(){
	move1();
	move1();
	move2();
}

int main(){
	int T, n, val;
	scanf("%d", &T);
	while(T--){
		scanf("%d",&n);
		for (int i=0; i<n; i++){
			scanf("%d",&val);
			if (i==0){
				head = createNode(val);
				tail = head;
			}
			else{
				nextNode = createNode(val);
				tail->next = nextNode;
				tail = nextNode;
			}
		}
		while(n > 1){
			play1();
			n--;
			if (n==1){
				printf("1 %d\n",tail->value);
				break;
			}
			play2();
			n--;
			if (n==1){
				printf("0 %d\n",tail->value);
				break;
			}
		}
	}
	return 0;
}
