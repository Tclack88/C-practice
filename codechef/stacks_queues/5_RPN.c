/*
https://www.codechef.com/practice/course/stacks-and-queues/STAQUEF/problems/ONP?tab=statement
RPN - Reverse Polish Notation
aka "postfix notation" operators follow operands. (conventional math uses infix notation)
INPUT							OUTPUT
3
(a+(b*c))						abc*+
((a+b)*(z+x))					ab+zx+*
((a+t)*((b+(a+c))^(c+d)))		at+bac++cd+^*
*/


#include <stdio.h>
#include <stdlib.h>

struct Node{
	char chr;
	struct Node* last;	
	struct Node* next;	
};

struct Node* tail;

struct Node* createNode(char val){
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->chr = val;
	newNode->last = NULL;
	newNode->next = NULL;
	return newNode;
}

void push(char chr){
	struct Node* newNode = createNode(chr);
	newNode->last = tail;
	tail = newNode;
}

char pop(){
	char chr = tail->chr;
	if (tail->last == NULL){
		free(tail);
		return chr; // at first element
	}
	tail = tail->last;
	free(tail->next);
	tail->next = NULL;
	return chr;
}

int main() {
	// your code goes here
	int T;
	char chr, tmp;
	scanf("%d", &T);
	scanf("%c", &tmp); // throw away (first newline)
	while(T--){
	    scanf("%c", &chr);
		while (chr != '\n'){
			//printf("dealing with char: %c\n",chr);
	    	if (chr >=97 && chr <=122) // if a-z
	        	printf("%c",chr);
			else if (chr != ')') // if == ( or == operators (+,-,*,/,%)
				push(chr);
			else{ // must be ')', pop until '(' is found
				while (chr != '('){
					chr = pop();
	    			if (chr != '(')
	        			printf("%c",chr);
				}
			}
	    	scanf("%c", &chr);
		}
		printf("\n");
	}
	free(tail);
	return 0;
}
