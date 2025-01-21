#include <stdio.h>

int main(){
	char k;
	printf("Enter the super secret password: ");
	scanf("%c", &k);
	if (k=='Q')
		printf("ACCESS GRANTED!\n");
	return 0;
}
