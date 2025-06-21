#include <stdio.h>

int main(){
	char str[] = "Hello file system.\n";
	FILE* fptr = fopen("message.txt","w");	
	fputs(str, fptr);
	fclose(fptr);
	printf("Created text file message.txt\n");
	return 0;
}
