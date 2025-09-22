// https://www.codechef.com/practice/course/number-theory/INTNT01/problems/RETURNCHANGE?tab=statement
/* Rounded change. Input: a price between 1 and 100, must round it to the nearest 10 (round up at 5) and then return the change as if paying with a $100 bill.
INPUT:	OUTPUT:
4
35		60
54		50
80		20
12		90
*/
#include <stdio.h>

int get_change(int n){
	if (n % 10 <= 4)
		return 100 - 10*(n/10);
	return 100 - 10*((n+10)/10);
}

int main(){
	int T, n;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		printf("%d\n",get_change(n));
	}
	return 0;
}
