//https://www.codechef.com/practice/course/number-theory/INTNT01/problems/EXISTENCE
/* Checking that some input for X and Y (which can be up to 10^18) satisfy the equation: X^4 + 4Y^2 = 4(X^2)Y
Strategy: need to use unsigned long long to get large numbers. These values will be on the order of 10^36, so an unsigned long which covers upt o 10^32 isn't enough. long long alone is probably sufficient, but these values will always be positive, so no problem making it unsigned
INPUT:							OUTPUT:
5				
2 2								YES
4 4								NO
3 6								NO
8 32							YES
200000000 20000000000000000		YES
*/
#include <stdio.h>

int main() {
    int T, X, Y;
	scanf("%d",&T);
	while (T--){
	    scanf("%d %d",&X,&Y);
	    unsigned long long left = X*X*X*X + 4*Y*Y;
	    unsigned long long right = 4*X*X*Y;
	    if (left == right)
	        printf("YES\n");
	    else
	        printf("NO\n");
	}
    return 0;
}
