// https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/ZCO14002
/* Story: Someone is assigning activities from a schedule to students. No student can go 3 or more days in a row without performing a task and each task has different duration. The assignee wants to minimize their own work load. Duties are given as an int array with the values representing the time required to complete it.
strategy: I noticed from trial and error that if I simply took a greedy approach, choosing the smallest of the first 3 duties, then the smallest of the next three in front of that, I would get a minimum, however I cannot guarantee that would always yield the best. What I can do however is initialize a "best" array with the first 3 duties assigned to the first 3 slots, then the next blank slot, look back at the previous 3 entries and add the smallest their, then continue this. That way, each slot represents the smallest value that one could land on when moving ahead. Then once filled, look at the smallest of the final 3 filled slots of the "best" array which would represent the minimum choice
INPUT:				OUTPUT:
10
3 2 1 1 2 3 1 3 2 1		4

8
3 2 3 2 3 5 1 3			5
NOTE: I got this logic first try!
*/
#include <stdio.h>

int min(int a, int b){
    if (a < b)
        return a;
    return b;
}

int main() {
	int N;
	scanf("%d",&N);
	int duty[N];
	for (int i=0; i<N; i++)
	    scanf("%d",&duty[i]);
	int best[N];
	best[0] = duty[0];
	best[1] = duty[1];
	best[2] = duty[2];
	for (int i=3; i<N; i++){
	    best[i] = duty[i] + min(min(best[i-1],best[i-2]),best[i-3]);
	}
	printf("%d", min(min(best[N-1],best[N-2]),best[N-3]));
    return 0;
}
