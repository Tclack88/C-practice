#include <stdio.h>

int max(int a, int b){
	if (a>b)
		return a;
	return b;
}

int gcd(int a,int b){
        if (b==0){
                return a;
        }
        int r = a % b; // remainder
        return gcd(b,r);
}
// Strategy:
// lcm must be a multiple of gcf. 
// So rather than checking every number
// check every multiple of gcf
/*int lcm(int a, int b){
	int gcf = gcd(a,b);
	int N = max(a,b)/gcf;
	int least = N*gcf;
	while ( least%a != 0 || least%b != 0  ){
		N++;
		least = N*gcf;
	}
	return least;
}*/

int lcm(int a, int b){
	int N = max(a,b);
	int least = N;
	while (least%b != 0){
		least += N;
	}
	return least;
}

int main(){
	int least;
	int a;
	int b;
	while( scanf("%d %d", &a, &b) == 2 ){
		if(a>b)
			least = lcm(a,b);
		else
			least = lcm(b,a);
		printf("%d\n",least);

	}
	return 0;
}

//  3 2 4     24     3 2 5    30
// Q  A  B  R
// 1  30 24 6
// 4  24 6 0
// 	  6  0
