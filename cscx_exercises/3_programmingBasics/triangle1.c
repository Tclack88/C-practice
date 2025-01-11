#include <stdio.h>

int main(){
	int a;
	int b;
	int c;
	scanf("%d %d %d", &a, &b, &c);
	if (a + b <= c || b + c <= a  || c + a <= b){
		printf("impossible\n");
	}
	else if (a == b && a == c){
		printf("equilateral\n");
	}else if (a == b || a == c || b == c){
		printf("isosceles\n");
	}
	else
		printf("scalene\n");
	return 0;
}
