#include <stdio.h>
#include <string.h>

int negation(int b){
	return (b == 0) ? 1: 0;
}

int main(){
	char a[6];
	int b;
	int c;
	while( scanf("%s",a)==1 ){
		b = (strcmp(a,"true") == 0) ? 1: 0;	
		c = negation(b);
		printf("%s\n",(c == 1) ? "true": "false");
	}
	return 0;
}	
