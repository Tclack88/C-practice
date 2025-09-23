//https://www.codechef.com/practice/course/number-theory/INTNT01/problems/DIVIDEMAKEEQ?tab=statement
/* We are given a different number of numbers. We want to make all the numbers the same by making the least number of changes. We make changes by dividing the numbers of the array by some number. Strategy: Because we are dividing the number, we are turning it into one of its divisors. So we can find the GCD of all numbers. If an element is not equal to this GCD, it must be changed and thus we count it as a needed change.
INPUT:			OUTPUT:
4
2
11 22				1
5
38 38 38 38 38		0
4
4 4 16 8			2
4
11 13 17 19			4
*/
#include <stdio.h>

int gcd(int a, int b){
    int M = b;
    int m = a;
    if (a>b){
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

int main() {
	int T, N;
	scanf("%d",&T);
	while (T--){
	    scanf("%d",&N);
	    int arr[N];
	    for (int i=0; i<N; i++)
	        scanf("%d",&arr[i]);
	    int GCD = arr[0];
	    for (int i=1; i<N; i++)
	        GCD = gcd(GCD,arr[i]);
	    int count = 0;
	    for (int i=0; i<N; i++){
	        if (GCD != arr[i])
	            count++;
		}
	    printf("%d\n",count);
	}
    return 0;
}
