#include <stdio.h>
#include <string.h>

#define STACK_CAPACITY 101
char stackArray[STACK_CAPACITY];
int topIndex = -1;

int isEmpty() {
    return topIndex == -1;
}

int isFull() {
    return topIndex >= STACK_CAPACITY - 1;
}

void push(char character) {
    if (topIndex >= STACK_CAPACITY)
        printf("Stack is full\n");
    else{
        stackArray[++topIndex] = character;
    }
}

char pop() {
    if (topIndex < 0){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        char ele = stackArray[topIndex--];
        return ele;
    }
}

int main() {
    char inputString[] = "Hello, World!";
    int inputLength = strlen(inputString);

    // Push each character onto the stack
    for (int i = 0; i < inputLength; i++) {
        char currentChar = inputString[i];
        push(currentChar);
    }

    // Pop the characters from the stack to construct the reversed string
    char reversedString[STACK_CAPACITY];
    int reversedIndex = 0;
    while (!isEmpty()) {
        reversedString[reversedIndex++] = pop();
    }
    reversedString[reversedIndex] = '\0'; // Null terminate the reversed string
    
    printf("%s\n", reversedString);
    return 0;
}
