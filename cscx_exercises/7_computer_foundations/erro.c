#include <stdio.h>

int main(int argc, char* argv[]){
	char out[]  = "This is stdout.";
	char err[] = "This is stderr.";
	fprintf(stdout,"%s\n",out);
	fprintf(stderr,"%s\n",err);
	return 0;
}
