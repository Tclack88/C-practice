#include <stdio.h>
#include <string.h>

int main(){
	char a[8],x[8],b[8];
	int p,q, res;
	char temp[21];
	while( fgets(temp, 21, stdin) ){ // scanf stops at space, fgets will take all 
		sscanf(temp, "%s %s %s", a, x, b); // re-scan the string
		if(strcmp(a,"not")==0){
			q = (strcmp(x,"true")==0 ) ? 1 : 0;
			res = !q;
		}
		else{
			p = (strcmp(a,"true")==0 ) ? 1 : 0;
			q = (strcmp(b,"true")==0 ) ? 1 : 0;

			if (strcmp(x,"xor")==0){
				res = p ^ q;
			}
			else if (strcmp(x,"and")==0){
				res = p && q;
			}
			else if (strcmp(x,"or")==0){
				res = (p || q);
			}
			else{ // implies: below satisfies all conditions of truth table
				res = 1;
				if (p==1 && q==0)
					res = 0;
			}
		}

		printf("%s\n", (res==1) ? "true" : "false");

	}
	return 0;
}
