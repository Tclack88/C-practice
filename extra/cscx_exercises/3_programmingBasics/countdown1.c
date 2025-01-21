#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	while (n > 0){
		printf("%d\n", n--);
	}
	printf("Go!\n");
	return 0;
}
