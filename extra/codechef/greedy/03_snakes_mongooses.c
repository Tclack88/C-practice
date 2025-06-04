// https://www.codechef.com/learn/course/greedy-algorithms/LIGRDSA04/problems/SNELECTP?tab=statement
/*
mongooses and snakes "vote". in a fair election, everyone votes, but here, the mongooses will eat the snakes. But a mongoose will only eat one adjacent snake. If this happens, who will win?

Strategy: a mongoose will eat the snake to the left (if it exists), else, it will eat the snake of the right (if exists), else, do nothing

INPUT:				OUTPUT:
4
sm					mongooses
ssm					tie
sms					tie
ssmmmssss			snakes
*/
#include <stdio.h>

int main() {
	int T, snakes,mongooses;
	char junk;
	char last = 0;
	char current = 0;
	scanf("%d",&T);
	scanf("%c",&junk);
	while (T--){
		last = 0;
		snakes = 0;
		mongooses = 0;
	    current = getchar();
	    while (current != '\n'){
	        if (current == 's'){
	            snakes++;
	            if (last == 'm'){
	                snakes--;
	                last = 0;
	            }
	            else
	                last = current;
	        }
	        else if (current == 'm'){
	            mongooses++;
	            if (last == 's' && snakes >0){
	                snakes--;
	                last = 0;
	            }
	            else
	                last = current;
	        }
	    	current = getchar();
	    }
	    if (snakes >  mongooses)
	        printf("%s\n","snakes");
	    else if (snakes <  mongooses)
	        printf("%s\n","mongooses");
	    else
	        printf("%s\n","tie");
	}
}
