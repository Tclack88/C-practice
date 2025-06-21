#include <stdio.h>
#include <string.h>

int main(){
	char profession[50];
	int age;
	int discount;
	while( scanf("%s %d", profession, &age)==2 ){
		discount = 0;
		if (age	>= 65 || age < 18)
			discount = 1;
		else if (strcmp(profession,"student") == 0 && age <= 25)
			discount = 1;
		printf("%s\n", (discount==1) ? "discount" : "full price");
	}
	return 0;
}
