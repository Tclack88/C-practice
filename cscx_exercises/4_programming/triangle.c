#include <stdio.h>


// work in progress

int main(){
	int a, b, c;
	while( scanf("%d %d %d", &a, &b, &c) == 3 ){
		if (a+b <= c || b+c<= a || c+a <= b)
			printf("impossible\n");
		else if (a == b && b == c)
			printf("equilateral acute\n");
		else{
			if (a == b || b == c || a == c)
				printf("isoceles ")
			else
				printf("scalene ");

			if (a==b || b==c || a==c)
				printf("right\n");
			else
				printf("obtuse");
		}
	}
	return 0;
}
