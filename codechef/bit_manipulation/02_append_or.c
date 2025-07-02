// https://www.codechef.com/learn/course/bit-manipulation/BITM04/problems/APPENDOR?tab=statement
/*
N numbers are provided, they will all be bitwise or'd together. Detemine the smallest (non-negative) number you can bitwise or with this in order to get the number Y. If no such number exists, print -1
eg. N = 4 (3 5 6 2), Y = 15. left = (3|5|6|2) = 7.  7 | 8 = 15. return 8
7:  0 1 1 1			3: 0 0 1 1
8:  1 0 0 0			x: (impossible. Cannot or 1 with something to give 0)
15: 1 1 1 1			8: 1 0 0 0
INPUT:			OUTPUT:
4				8
4 15			-1
3 5 6 2			1
3 8				0
1 2 1			2
1 1
0
5 7
1 2 4 2 1
*/
#include <stdio.h>

int get_digits(int a, int b){
    // determine max numb of binary digits
    int max = (a >= b ? a : b);
    int min = (a < b ? a : b);
    int ret = 0;
    while (max > 0){
        ret++;
        max /=2;
    }
	return ret;
}

int get_complement(int left, int Y, int N){
    int ret = 0;
    for(int i=0; i<N; i++){
        int shift = 1<<i;
        if ( !((left & shift) ^ (Y & shift)) ) // both bits are 1 or 0, add nothing
            continue;
        else if (Y & shift ) // Y bit is 1, but not left, add
            ret += shift;
        else                // Y bit is 0, left is 1 => impossible
            return -1;
    }
    return ret;
}

int main() {
	int T,N,Y,n;
	scanf("%d",&T);
	while(T--){
	    int left = 0;
	    scanf("%d %d",&N,&Y);
	    for (int i=0; i<N; i++){
	        scanf("%d",&n);
	        left |= n;
	    }
	    int num_digits = get_digits(left, Y);
        int X = get_complement(left, Y, num_digits);
	    printf("%d\n",X);
	}
    return 0;
}
