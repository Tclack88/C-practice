#include <stdio.h>

int add(int x, int y){
	return x+y;
}

int main(){
	int x;
	int y;
	while( scanf("%d %d", &x, &y) == 2 ){
		printf("%d\n", add(x,y));
	}
	return 0;
}
