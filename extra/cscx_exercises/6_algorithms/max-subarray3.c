#include <stdio.h>
#include <string.h>

int print_arr(int arr[],int len){
	for(int i=0; i < len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int max(int a,int b){
	if (a > b)
		return a;
	return b;
}

int find_subarray(int arr[], int len){
	int current = arr[0];
	int last_max = arr[0];
	int best_max = arr[0];
	for (int i = 1; i < len; i++){
		current = arr[i];
		last_max = max(current,last_max+current);
		best_max = max(best_max,last_max);
	}
	return best_max;
	
}

int main(){
	char input[4000];
	int arr[1001];
	while ( fgets(input, 4000, stdin) != NULL ){
		int i = 0;
		char* token = strtok(input," ");
		while(token != NULL){
			sscanf(token,"%d",&arr[i] );
			i++;
			token = strtok(NULL," ");
		}

		int val = find_subarray(arr, i);
		printf("%d\n",val);
	}
	return 0;
}
