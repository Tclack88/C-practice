#include <stdio.h>

int main(){
	int time;
	scanf("%d", &time);
	if (time >= 4 && time <= 11){
		printf("Good morning\n");
	}else if (time >= 12 && time <= 17){
		printf("Good afternoon\n");
	}else if (time >= 18 && time <= 23){
		printf("Good evening\n");
	}else
		printf("Hi\n");
	return 0;
}
