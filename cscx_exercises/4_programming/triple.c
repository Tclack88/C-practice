#include <stdio.h>

int triple(int x){
	return 3*x;
}

int main(){
	// lessons learned. If given a decimal when expecting
	// an int, scanf will stop at the "." so for an input
	// of 1.3, it will triple 1 (to 3) then read the "."
	// as invalid then exit
	int x;
	while( scanf("%d", &x) == 1 ){
		printf("%d\n", triple(x));
	}
	return 0;
}
