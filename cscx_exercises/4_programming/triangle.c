#include <stdio.h>

int MIN(int a, int b){
	return a < b ? a : b;
}

int MAX(int a, int b){
	return a > b ? a : b;
}

int main(){
	int a, b, c, min, max, med;
	while( scanf("%d %d %d", &a, &b, &c) == 3 ){
		if (a+b <= c || b+c <= a || c+a <= b)
			printf("impossible\n");
		else if (a == b && b == c)
			printf("equilateral acute\n");
		else if (a != b && b != c && a != c){
				printf("scalene ");
				// strategy: all sides are different, get smallest, largest
				// and medium. check with pythag. to find if they connect
				min = MIN(MIN(a,b),c);
				max = MAX(MAX(a,b),c);
				med;
				if (a > min && a < max)
					med = a;
				else if (b > min && b < max)
					med = b;
				else
					med = c;
				if (max*max > min*min + med*med)
					printf("obtuse\n");
				else if (max*max < min*min + med*med)
					printf("acute\n");
				else
					printf("right\n");
		}
		else{
			printf("isosceles ");
			// strategy: two sides are the same length, one is different
			// find if the equal sides follow pythag. it's right.
			// if the different side is shorter then the sum square of two
			// small ones, it's acute, if it's longer, it's obtuse, else right
			int same;
			int diff;
			if (a == b){
				same = a; // or b
				diff = c;
			}
			else if (a == c){
				same = a; // or c
				diff = b;
			}
			else{
				same = c; // or b
				diff = a;
			}
			if (diff*diff > 2*same*same)
				printf("obtuse\n");
			else if (diff*diff < 2*same*same)
				printf("acute\n");
			else
				printf("right\n");
		}
	}
	return 0;
}
