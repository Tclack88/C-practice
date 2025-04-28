#include <stdio.h>
#include <string.h>

int max(int a,int b){
	return a > b ? a : b;
}

int main(){
	char input[4000];
	int current, last_max, best_max;
	while ( fgets(input, 4000, stdin) != NULL ){
		char* token = strtok(input," ");
		sscanf(token,"%d", &current);
		//printf("starter: %d,",current);
		last_max = current;
		best_max = current;
		token = strtok(NULL," ");
		while(token != NULL){
			sscanf(token,"%d",&current );
			last_max = max(current,last_max+current);
			best_max = max(best_max,last_max);
			token = strtok(NULL," ");
			//printf("best max: %d,",best_max);
		}

		printf("%d\n",best_max);
	}
	return 0;
}
