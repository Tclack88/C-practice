#include <stdio.h>

int factorial(int x){
	int n = 1;
	if (x == 0)
		return 1;
	else{
		for (int i = 1; i <= x; i++){
			n *= i;
	}
	return n;
}
			
		
	return x;
}

int main(){
	int x;
	while( scanf("%d",&x)==1 ){
		x = factorial(x);
		printf("%d\n",x);
	}
	return 0;
}
