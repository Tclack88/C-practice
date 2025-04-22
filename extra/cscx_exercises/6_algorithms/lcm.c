#include <stdio.h>

int max(int a, int b){
	if (a>b)
		return a;
	return b;
}

int gcf(int a,int b){
        if (b==0){
                return a;
        }
        int r = a % b; // remainder
        return gcf(b,r);
}
// Strategy:
// lcm must be a multiple of gcf. 
// So rather than checking every number
// check every multiple of gcf 
// ------------- Works but slow
/*int lcm(int a, int b){
	int g = gcf(a,b);
	int N = max(a,b)/g;
	int least = N*g;
	while ( least%a != 0 || least%b != 0  ){
		N++;
		least = N*g;
	}
	return least;
}*/

// Strategy 2: less complex, gcf is smaller than the larger of a and b
// So one could check multiples of the larger value until a value
// is found such that the smaller of a,b is divisible with mod of 0
// ------------- Works but also is slow
/*int lcm(int a, int b){
	int N = max(a,b);
	int least = N;
	while (least%b != 0){
		least += N;
	}
	return least;
}*/

// After some research, I found that apparently
// a * b = gfc(a,b) * lcm(a,b)
// Euclid's algorithm is fast and computes gcf leaving
// lcm found by a product and division

int lcm(int a, int b){
	int g = gcf(a,b);
	return (a*b)/g;
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
