// https://www.codechef.com/practice/course/stacks-and-queues/STAQUEF/problems/PREP59
/*  The purpose of this is to determine if the parentheses are valid,
i.e. for every opening, there's a closing. (nesting okay)
eg.
INPUT:
3
()(())
(()()
))((

OUTPUT
1
0
0
*/
#include <stdio.h>

int LIMIT = 100002;
char STACK[100002];
int top;

int push(char c){
    if (top >= LIMIT){
        printf("stack full!\n");
        return -1;
    }
    else{
        STACK[++top] = c;
        return 0;
    }
}

int pop(){
    if (top < 0){
        printf("stack empty!\n");
        return 1;
    }
    else{
        top--;
        return 0;
    }
}

int main() {
	int T, res;
	char paren, extra; // extra holds the newline after T is scanned; throw away
	scanf("%d",&T);
	scanf("%c",&extra);
	while(T--){
	    top = -1;
	    scanf("%c",&paren);
	    while (paren != '\n'){
	       if (paren == '(')
	            push(paren);
	       else
	            if (top > -1 && STACK[top]=='(')
	                pop();
	            else
	                push(paren);
	       scanf("%c", &paren);
	    }
	    res = 0;
	    if (top == -1)
	        res = 1;
	    printf("%d\n",res);
	}
	
    return 0;
}


