#include <stdio.h>
#include <math.h>
#include <string.h>

int bin2dec(char* bin, int len){

	int total = 0; // previously I used float here, which resulted
					  // in errors after around 24 digits due to rounding
	for (int i=len-1; i >= 0; i--){
		if(bin[i] == '1')
			total += pow(2,len - 1 - i);
	}
	return total;
}


int main(){
	char bin[31];
	while( scanf("%s", bin)== 1)
		printf("%d\n", bin2dec(bin,strlen(bin)));
	return 0;
}
