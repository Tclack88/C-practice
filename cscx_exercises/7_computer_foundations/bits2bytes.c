#include <stdio.h>

int main(){
	int n;
	int m;
	while( scanf("%d",&n)==1 ){
		m = n/8;
		if (n%8 != 0)
			m++;
		printf("%d\n",m);
	}
	return 0;
}
