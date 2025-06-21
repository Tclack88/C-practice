#include <stdio.h>

int triple(int x){
	return 3*x;
}

int main(){
	int x;
	scanf("%d", &x);
	printf("%d\n",triple(x));
	return 0;
}
