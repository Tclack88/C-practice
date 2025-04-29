#include <stdio.h>

int main(){
	int n;
	FILE *fptr = fopen("runcount.txt","r+");
	if (fptr == NULL){
		FILE *fptr2 = fopen("runcount.txt","w");
		fputs("1", fptr2);
		fclose(fptr2);
		printf("run #1\n");
	}
	else{
		fscanf(fptr, "%d",&n);
		n++;
		rewind(fptr);
		fprintf(fptr,"%d",n);
		fclose(fptr);
		printf("run #%d\n",n);
	}

	return 0;
}
