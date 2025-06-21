#include <stdio.h>

int main(){
	char string[61];
	int x;
	while (scanf("%s %d", string, &x) == 2)
		printf("%c\n", string[x]);
	return 0;
}
