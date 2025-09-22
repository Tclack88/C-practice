// https://www.codechef.com/practice/course/number-theory/INTNT01/problems/ODDSUMPAIR
/* Given 3 integers, determine whether or not the sum of any of the two numbers can give an odd number
strategy: observing that even+even = even odd+odd=even and even+odd=odd, We must simply verify that at least one odd number and one even number exist. This can be efficiently calculated with bitwise or with 0 for determining the 'even' and 'odd' variables, then returning bitwise and will let us know that at least one of each is present
INPUT: 		OUTPUT:
4
1 2 3		YES
8 4 6		NO
3 3 9		NO
7 8 6		YES
*/
#include <stdio.h>

int can_make_odd(int a, int b, int c){
    int odd = 0;
    int even = 0;
    even = even | (a % 2 == 0);
    odd = odd | (a % 2 != 0);
    even = even | (b % 2 == 0);
    odd = odd | (b % 2 != 0);
    even = even | (c % 2 == 0);
    odd = odd | (c % 2 != 0);
    return odd & even;
}
        

int main() {
	int T, a,b,c;
	scanf("%d",&T);
	while (T--){
	    scanf("%d %d %d",&a,&b,&c);
	    if (can_make_odd(a,b,c))
	        printf("YES\n");
	    else
	        printf("NO\n");
	}
	return 0;
}
