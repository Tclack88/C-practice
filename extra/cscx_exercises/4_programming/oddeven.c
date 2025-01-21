#include <stdio.h>

int main(){
	// note: practicing ternary operator.
	// also I noticed if there's on argument, while loop doesn't need {}
	// I knew it was true with for loops. cool it works with while loops as well
	int x;
	while( scanf("%d", &x) == 1 )
		printf("%s\n", x%2 == 0 ? "even" : "odd");
	return 0;
}
