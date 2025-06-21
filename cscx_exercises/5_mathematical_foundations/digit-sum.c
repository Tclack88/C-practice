#include <stdio.h>

int digit_sum(int n){
		int total = 0;
		while(n > 0){
			total += n%10;
			n /= 10;
		}
		return total;
}

int main(){
	int n;
	int total;
	while( scanf("%d", &n)==1 ){
		printf("%d\n", digit_sum(n));
	}
	return 0;
}
