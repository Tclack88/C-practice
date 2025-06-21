#include <stdio.h>

int main(){
	float f;
	char a[31], b[31];
	while( scanf("%f %s %s", &f, a, b) == 3){
		printf("%s owes $%.2f dollars to %s.\n", a, f, b);
	}
	return 0;
}
