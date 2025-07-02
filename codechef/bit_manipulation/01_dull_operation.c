// https://www.codechef.com/learn/course/bit-manipulation/BITM02/problems/DUPLETP
/*
The dull operation is finding a pair of numbers x,y which satisfies (x|y)(x^y) for some number N.
Notice that for some odd number N, the last digit of the binary will be a 1
N = 3: 11
N = 47: 10111
N|(N-1) = N  and N^(N-1) = 1, so their product is N
For any number, at least one possibility for the pair exists. In this code, we just need to find such a pair
INPUT:	OUTPUT:		MY OUTPUT:
4
1		1 0		 	0 1
49		3 4			48 49
21		7 4			20 21
35		7 2			34 35
*/
#include <stdio.h>

int main() {
	int T, N;
	scanf("%d",&T);
	while (T--){
	    scanf("%d",&N);
	    printf("%d %d\n",N-1, N);
	}
    return 0;
}
