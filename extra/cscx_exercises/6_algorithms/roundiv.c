#include <stdio.h>

/*  Strong note: mod in c is different from that in python. In python, the "denominator" sign
	decided the sign of the remainder. But in C, it seems to take that of the "numerator"
	eg. 4 % -3. Numerator is positive. -3 goes into 4 -1 times with a remainder -1
*/

int roundup(int q, int sign){
	// helper function. rounds "up"
	// (in absolute magnitude)
	// Previously I used q for the sign, but that didn't work for small nums, 
	//eg 3/2 gives q=0
	if (sign > 0)
		return q+1;
	else
		return q-1;
}

int roundiv(int n, int d){
	int sign = 1; // previously I calculated sign as n * d (but for large numbers, integer overflow occurred leading to eg. 1000000000*1000000000 = -1486618624 (negative)
	if ((n < 0 && d > 0) || (d < 0 && n > 0))
		sign = -1;
	int q = n/d;
	int r = n % d;
	if (d<0)
		d = -d;
	if (r<0)
		r = r+d;
	if (r == 0)
		return q;
	if (d-r == r-0){ // exactly in middle, return nearest even
		if (q % 2 == 0){
			return q;
		}	
		else{
			return roundup(q,sign);
		}
	}
	if (n > 0){
		if(d-r < r - 0){
			return roundup(q,sign);
		}
		else
			return q;
	}
	else{
		if(d-r > r-0){
			return roundup(q,sign);
		}
		else
			return q;
	}
}

int main(){
	int n,d,round;
	while ( scanf("%d %d",&n,&d)==2 ){
		round = roundiv(n,d);
		printf("%d\n",round);
	}
	return 0;
}

/*
AI solution after I figured it out myself:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int roundiv(int n, int d) {
    if (d == 0) return 0; // Avoid division by zero

    int sign = (n > 0) == (d > 0) ? 1 : -1;
    int q = n / d;
    int r = abs(n % d);

    if (r >= abs(d / 2)) {
        return q + (sign > 0); // Use the sign to round up or down
    } else if (r == abs(d / 2) && (q % 2 != 0)) {
          return q + sign; // Correct halfway round to even
    } else {
        return q;
    }
}
*/
