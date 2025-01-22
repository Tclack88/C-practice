#include <stdio.h>

int reverse_digits(int n){
	int order = 1;
	if (n == 0)
		return 0;
	int n_copy = n;
	while(n_copy > 0){
		order *= 10;
		n_copy /= 10;
	}
	order /= 10;

	int ret = 0;
	while (n > 0){
		ret += order * (n%10);
		order /= 10;
		n /= 10;
	}
	return ret;
}

int palindrome(int n){
	int reversed = reverse_digits(n);
	if (reversed == n)
		return 1;
	return 0;
}

int main(){
	int n;
	while( scanf("%d", &n) == 1){
		printf("%d is ", n);
		if (!palindrome(n) )
			printf("not ");
		printf("palindrome\n");
	}
	return 0;
}
