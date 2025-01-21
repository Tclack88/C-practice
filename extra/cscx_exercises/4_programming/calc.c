#include <stdio.h>
#include <math.h>

int main(){
	float x, y;
	char o;
	while( scanf(" %f %c %f", &x, &o, &y) == 3 ){
		switch (o){
			case '+':
				printf("%.2f\n", x + y);
				break;
			case '-':
				printf("%.2f\n", x - y);
				break;
			case '*':
				printf("%.2f\n", x * y);
				break;
			case '/':
				printf("%.2f\n", x / y);
				break;
			case '^':
				//if (y == 0)
				//	x = 1;
				//else if ( y == (int) y){
				//	float x0 = x;
				//	for(int i=1; i < y; i++){
				//		x *= x0;
				//	}
				//}
				//else{
					// Taylor expansion of a^x for fractional powers (or x^y here shown)
				//	x =  1 + y*log(x) + (y*y/2)*log(x)*log(x) +	(y*y*y/6)*log(x)*log(x)*log(x) +  (y*y*y*y/24)*log(x)*log(x)*log(x)*log(x); 
				//}
				x = pow(x,y);
				printf("%.2f\n",x);

		}
	}
	return 0;
}
