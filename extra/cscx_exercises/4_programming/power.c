#include <stdio.h>

int power(int x, int n){
	if(n == 0)
		return 1;
	return x*power(x,n-1);
}

int main(){
	int x;
	int n;
	while( scanf("%d %d",&x, &n)==2 ){
		x = power(x,n);
		printf("%d\n",x);
	}
	return 0;
}
