#include <stdio.h>

int main(){
	int a,b,c,d,e,f,g,h;
	while( scanf("%d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h)==8 ){
		if(e>c || f>d || a>g || b>h)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}
