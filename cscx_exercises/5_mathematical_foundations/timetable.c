#include <stdio.h>

int main(){
	int a,b,c,d,e,f,g,h;
	float s1, e1, s2, e2;
	while (scanf("%d:%d %d:%d %d:%d %d:%d",&a,&b,&c,&d,&e,&f,&g,&h)==8 ){
		s1 = a + (float) b/100;	
		e1 = c + (float) d/100;	
		s2 = e + (float) f/100;	
		e2 = g + (float) h/100;	
		if (s2 > e1 || s1 > e2)
			printf("ok\n");
		else
			printf("conflict\n");
	}
	return 0;
}
