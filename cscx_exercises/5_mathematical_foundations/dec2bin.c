#include <stdio.h>
#include <string.h>

void dec2bin(int dec, char bin[]){
	// syntactic sugar for  dec2bin(int dec, char *bin)
	// the pointer to the string location. C doesn't take or
	// return  strings, so we just create the var in stack memory,
	// then pass that location into the function
	char temp[30];
	int i = 0;
	while(dec > 0){
		if (dec % 2 == 1)
			temp[i] = '1';
		else
			temp[i] = '0';
		dec /= 2;
		i++;
	}
	temp[i] = '\0'; // add nullbyte to remove trailing 0's/1's
	// reverse temp
	int len = strlen(temp);
	for(int i=0; i <= len ; i++)
		bin[i] = temp[len-1-i];
}


int main(){
	int dec;
	char bin[30];
	while(scanf("%d", &dec)==1 ){
		if (dec==0)
			printf("0\n");
		else{
			dec2bin(dec,bin);
			printf("%s\n",bin);
		}
	}
	return 0;
}
