#include <stdio.h>

int main(){
	FILE* fptr = fopen("name.txt","r");
	if (fptr == NULL)
		printf("name.txt: file not found\n");
	else{
		char buff[61];
		fscanf(fptr,"%s", buff);
		printf("%s\n",buff);
		fclose(fptr);
	}
	return(0);
}
