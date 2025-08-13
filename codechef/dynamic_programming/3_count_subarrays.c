//https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/SUBINC?tab=hints
/*
We are trying to find the total amount of increasing substrings. A single item also counts, in the example 1 4 2 3, we have, 1, 4, 2, 3 as well as 1 4, 2 3. This is 6 in total which should be our output.
INPUT:		OUTPUT:
3
4
1 4 2 3		6
1
5
3			1
*/
#include <stdio.h>

void setArr(int arr[], int size){
    for(int i=0; i<size; i++)
		arr[i] = 1;
}

void sum_sol(int arr[], int size){
    long total = 0; // int not big enough for some test cases
    for(int i=0; i<size; i++)
        total += arr[i];
    printf("%ld\n", total);
}

int main() {
	int T, N;
	scanf("%d",&T);
	while(T--){
	    scanf("%d",&N);
	    int arr[N];
	    for(int i=0; i<N; i++)
	        scanf("%d",&arr[i]);
	    int sol[N];
		setArr(sol,N);
	    for(int i=1; i<N; i++){
	        if(arr[i] >= arr[i-1])
	            sol[i] += sol[i-1];
	    }
	    sum_sol(sol, N);
	}
    return 0;
}
