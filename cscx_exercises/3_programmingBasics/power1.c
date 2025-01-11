#include <stdio.h>

int power(int b, int pow){
	if (pow==1){
		return b;
	}
	else{
		return b*power(b,pow-1);
	}
}

int main(){
	int b;
	int pow;
	scanf("%d %d",&b, &pow);
	printf("%d\n", power(b,pow));
	return 0;
}
