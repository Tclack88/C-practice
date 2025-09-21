// https://www.codechef.com/learn/course/number-theory/LINTDSA02/problems/PRIMFACT05?tab=statement
// for the number N, return the total number of prime factors. If it's prime or 1, return 1
/* INPUT:	OUTPUT:
2
121				1
26				2	
*/
#include <stdio.h>

int is_prime(int val){
	if (val <= 1)
		return 0;
	if (val == 2)
		return 1;
	if (val%2 == 0)
		return 0;
	for (int i=3; i*i<=val; i+=2){
		if (val%i == 0)
			return 0;
	}
	return 1;
}

int prime_factor_count(int n){
    int count = 0;
    for (int i=2; i<n; i++){
        if (n%i == 0)
			count += is_prime(i);
    }
	if (count == 0)
		return 1;
    return count;
}

int main() {
	int n, val;
	scanf("%d",&n);
	for (int i=0; i<n; i++){
		scanf("%d",&val);
		printf("%d: %d\n",i,prime_factor_count(val));
	}
	return 0;
}
