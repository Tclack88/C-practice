#include <stdio.h>

// Print primes up to but not including input n. (negatives, 0 and 1 do not count, print nothing)
// Basic strategy: check N % i up to N. if any remainder is 0, it's a factor and thus not prime
int isprime(int n){
	for (int i = 2; i < n; i++){
		if (n%i == 0)
			return 0;
	}
	return 1;
}

int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		if (n <= 2){
			printf("\n");
			continue;
		}
		for(int i=2; i < n; i++){
			if (isprime(i)){
				if(i == 2)
					printf("2");
				else
					printf(" %d",i);
			}
		}
		printf("\n");
	}
	return 0;
}
