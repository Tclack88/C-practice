#include <stdio.h>

int main(){
	// lessons learned: I was previously noting that
	// using sscanf ocnverting a string to a decimal
	// that if the string was not numeric (eg. was "abc"
	// instead of "123" that it would return 0
	// but that behavior didn't always work
	//
	// Now I use the return of sscanf, it will be 0 or 1
	// depending on if the operation was successful
	char a[31];
	char b[31];
	int an, bn; // n for "number"
	while(scanf("%s %s", a, b) == 2){
		if ( sscanf(a, "%d", &an) == 1){ // a is number
			printf("%s %d\n", b, an);
		}else{ // b is number
			sscanf(b, "%d", &bn);
			printf("%d %s\n", bn, a);
		}
	}
	return 0;
}

