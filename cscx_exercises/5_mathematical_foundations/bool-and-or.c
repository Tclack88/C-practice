#include <stdio.h>
#include <string.h>

int conjunction(int p, int q){
	return p && q;
}

int disjunction(int p, int q){
	return p || q;
}

int main(){
	char a[6], b[6], x[4];
	int p,q,res;
	while( scanf("%s %s %s", a,x,b)==3 ){
		p = (strcmp(a,"true")) ? 0 : 1;
		q = (strcmp(b,"true")) ? 0 : 1;

		if (strcmp(x,"and")==0 )
			res = conjunction(p,q);
		else
			res = disjunction(p,q);

		printf("%s\n", (res==1) ? "true" : "false");
	}
	return 0;
}
