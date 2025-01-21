#include <stdio.h>

int main(){
	char name[32];
	int age;

	scanf("%s %d",name, &age);
	printf("%s is %d years old.\n", name, age);
	return 0;
}
