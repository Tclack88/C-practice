//https://www.codechef.com/learn/course/combinatorics/COMBI02/problems/COMB17?tab=statement
/* We are given a number N and 3 numbers a,b,c. We want to find the total numbers less than or equal to N that are divisible by any of the numbers a,b,c.
Strategy:
we can do this less brute force way by using combinatorics and set theory. Imagine we had a list of the numbers divisible by a up to N (so if N was 10, and a was 2, we would have {2,4,6,8,10}, for 3, we'd have {3,6,9}
We want to find |A∪B∪C|, i.e. the count of numbers of this union. This can be shown to reduce to |A∪B∪C| = |A| + |B| + |C| - |A∩B| - |B∩C| - |A∩C| + |A∩B∩C|. Each individual element X is just the integer division of A and X (A//X). And each |X∩Y| is just the integer division of N/lcm(X,Y). Similarly for the last value N/lcm(A,B,C).
INPUT:		OUTPUT:
5
10 2 3 2		7
5 3 2 4			3
6 3 3 3			2
24 12 2 12		12
20 3 20 3		7
*/
#include <stdio.h>

int gcd(int a, int b){
    int m = a;
    int M = b;
    if (a > b){
        M = a;
        m = b;
    }
    int R = 1;
    while (R){
        R = M%m;
        M = m;
        m = R;
    }
    return M;
}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}

int main() {
	int T, N, a,b,c;
	scanf("%d",&T);
	while (T--){
	    scanf("%d %d %d %d",&N,&a,&b,&c);
	    int count = N/a + N/b + N/c - N/lcm(a,b) - N/lcm(a,c) - N/lcm(b,c) + N/(lcm(lcm(a,b),c));
	    printf("%d\n",count);
	}
    return 0;
}
