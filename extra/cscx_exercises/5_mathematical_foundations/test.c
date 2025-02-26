#include <stdio.h>
#include <string.h>

int main(){
	char in[30];
	char out[30];
	int a = 2;
	int b = 8;
	int ratio = b/a;
	char section[ratio];
	scanf("%s",in);
	int len = strlen(in);
	sprintf(secion, in[len-ratio -1], ratio);
	printf("section: %s\n",section);
	return 0;
}
