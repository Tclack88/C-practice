#include <stdio.h>
#include <string.h>

void int2bin(int num){
	for(int i=7; i>=0; i--)
		printf("%d",(num >> i)&1);
	printf("  ");
}

int main(int argc, char *argv[]){
	char input[100];
	strcpy(input,argv[1]);
	//scanf(argv[1],input);
	int len = strlen(input);

	/*printf("input is %s\n\n",input);
	for(int i=0; i<len; i++)
		printf("%s\t\t", input[i]);*/
	
	printf("\nASCII:\t");
	for(int i=0; i<len; i++)
		printf("%8c  ", input[i]);
	printf("\nHex:\t");
	for(int i=0; i<len; i++)
		printf("%8X  ", input[i]);
	printf("\nDec:\t");
	for(int i=0; i<len; i++)
		printf("%8d  ", input[i]);
	printf("\nBin:\t");
	for(int i=0; i<len; i++)
		int2bin(input[i]);		
	printf("\n");
	return 0;
}
