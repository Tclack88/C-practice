#include <stdio.h>

int main(){
	char name[32];
	scanf("%s", name);
	// scanf splits at space (and isn't immune to stack smashing)
	printf("Hello, %s!\n", name);
	return 0;
}
