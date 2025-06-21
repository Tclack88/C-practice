#include <stdio.h>

int digit_count(int d, int n){
	int count = 0;
	while(n > 0){
		count += n%10 == d ? 1 : 0;
		n /= 10;
	}
	return count;
}

int main(){
	int d, n;
	while( scanf("%d %d", &d, &n)==2 )
		printf("%d\n", digit_count(d,n));
	return 0;
}
