#include <stdio.h>
int inc(int x){
	return x+1;
}

int main(){
	int x;
	scanf("%d", &x);
	printf("%d\n", inc(x));
	return 0;
}
