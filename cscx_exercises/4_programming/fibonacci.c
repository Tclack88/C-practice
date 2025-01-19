#include <stdio.h>

int fibonacci(int n){
	// non recursive to save time for larger numbers; avoid recalculations
	if (n == 1)
		return 1;
	int N = 0;
	int last = 0;
	int next = 1;
	for (int i = 1; i < n; i++){
		N = last + next;
		last = next;
		next = N;
	}
	return N;
		
}

int main(){
	int n;
	while (scanf("%d", &n) == 1)
		printf("%d\n", fibonacci(n));
	return 0;
}
