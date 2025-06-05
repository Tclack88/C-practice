/* https://www.codechef.com/practice/course/two-pointers/POINTERF/problems/PROC18A
a person will run N kilometers, but he's capable of "running fast" for K kilometers in a row (and just once). There are girls at every kilometer, the amount is provided. Find which contiguous section has the most girls so that the runner can impress the most

Strategy: two pointers. advance one pointer summing every K slots. Check the total and store the "best" if a next best is found, use another pointer to keep that index

INPUT:				OUTPUT:
1					12
7 2
2 4 8 1 2 1 8
*/
#include <stdio.h>

int sum_slice(int arr[], int length){
    int total = 0;
    for (int i=0; i<length; i++)
        total += arr[i];
    return total;
}

int main() {
	int T,K,N,a,b,best,total;
	scanf("%d",&T);
	while (T--){
	    best = 0;
	    scanf("%d %d",&N,&K);
	    int arr[N];
	    for (int i=0; i<N; i++)
	        scanf("%d",&arr[i]);
	    a = 0;
	    b = K;
	    best = sum_slice(arr,K); 
	    while (b <= N){
	        total = sum_slice(&arr[b-K],K);
	        if (total > best){
				best = total;
	            a = b-K;
			}
	        b++;
	    }
	    printf("%d\n",best);
	}
    return 0;
}
