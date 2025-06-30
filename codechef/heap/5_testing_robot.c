// https://www.codechef.com/practice/course/heaps/HEAPF/problems/TSTROBOT?tab=statement
/* This doesn't actually seem to fit the "heap" theme. In essence, a number is given (as a starting point), then a string of R's and L's (length is specified). Based on the ordering, a robot will move right or left. The goal is to print the range (maximum to minimum value)
INPUT:			OUTPUT:
2
6 10
RRLLLL			5  (10->11->12->11->10->9->8) overall 12->8
2 0
LL				3  (0 to -2)
*/
#include <stdio.h>

int main() {
	int T,len,N;
	scanf("%d",&T);
	while(T--){
	    scanf("%d %d",&len, &N);
	    char seq[len+1]; // +1 to allow for \n
	    scanf("%s",seq);
	    int max = N;
	    int min = N;
	    for (int i=0; i<len; i++){
	        if (seq[i] == 'R')
	            N++;
	        else
	            N--;
	        if (N > max)
	            max = N;
	        if (N < min)
	            min = N;
	    }
	    printf("%d\n",max-min+1);
	}
    return 0;
}
