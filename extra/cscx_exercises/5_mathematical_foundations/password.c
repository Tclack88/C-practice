#include <stdio.h>
#include <string.h>

int main(){
	char password[] = "supersecretpasswordthatTrevordoesn'tknowwhatitis";
	char password_check[50];

	printf("please enter password: ");
	scanf("%s",password_check);

	if (strcmp(password,password_check)==0)
		printf("##################\n# ACCESS GRANTED #\n##################\n");
	else
		printf("get outta here!\n");
	return 0;
}
