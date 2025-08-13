//https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/SUMTRIAN
/*
A triangle of numbers is given. You must sum down the triangle either directly down or down and to the right. So with a triangle like this:
1
2 1
1 2 3

possible paths are: (1,2,1), (1,2,2), (1,1,2), (1,1,3), 4 possible paths. We are to return the largest sum of values. (in this case, 5 which can be optained with 1,2,2 or 1,1,3

Strategy:
To save space, I will express everything as a single array, rather than an array of arrays. Triangle numbers are given by the formula T_N = N*(N+1)/2 with the Nth triangle number is given by N. This also happens to be the left index if starting from 0. i.e. T(0) = 0, T(1) = 1, T(2) = 3, T(3) = 6, T(4) = 10 and so on:

0
1 2
3 4 5
6 7 8 9
10 . . . .

Here, I read in the original array (arr) directly and then make a "solution" (sol) array where I put the 0th index as the 0th index of arr. Then, I progressively go to each element in the array and calculate the item "down" and "down and right" as the item at the solution array at that index plus the item in arr at the "down" and "down and right" positions respectively. This way it builds up. There will be conflicts of course (when calculating the down value). In this case, I keep whichever value is higher because that's the only thing that we care about in this procedure.
INPUT: 		OUTPUT:
2
3		
1
2 1
1 2 3			5
4
1
1 2
4 1 2
2 3 1 1			9
*/

#include <stdio.h>
#include <string.h>

void printArr(int arr[],int size){
    for(int i=0; i<size; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void readArr(int arr[], int size){
    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);
}

int trinum(int num){
    return num*(num+1)/2;
}

int down(int col, int idx){
    int diff = idx - trinum(col);
    return trinum(col+1)+diff;
}

int down_right(int col, int idx){
    return down(col, idx) + 1;
}

int max(int a, int b){
    if (a>b)
        return a;
    return b;
}

int main() {
	int T, N;
	scanf("%d",&T);
	while(T--){
	    scanf("%d",&N);
	    int size = trinum(N);
	    int arr[size];
	    int sol[size];
	    readArr(arr, size); // populate initial array
	    memset(sol,0,size*sizeof(int));
	    sol[0] = arr[0];
	    int highest = sol[0];
	   // printArr(arr,size);
	    for(int i=0; i<N-1; i++){
	        for(int j=trinum(i); j<trinum(i+1); j++){
	            sol[down(i,j)] = max(sol[j] + arr[down(i,j)], sol[down(i,j)]);
	            sol[down_right(i,j)] = sol[j] + arr[down_right(i,j)];
	            highest = max(highest, max(sol[down(i,j)],sol[down_right(i,j)]));
	        }
	        
	    }
	   // printArr(sol,size);
	   // printf("\nhighest: %d\n", highest);
	    printf("%d\n", highest);
	}
    return 0;
}
