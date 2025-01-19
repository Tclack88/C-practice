#include <stdio.h>

int main(){
	char word[61];
	int i;
	char s;
	while( scanf("%s %d %c", word, &i, &s) == 3){
		word[i] = s;
		printf("%s\n", word);
	}
	return 0;
}

