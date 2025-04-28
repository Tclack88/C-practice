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

int find_subarray(int arr[], int len, int with[], int without[]){
	int current_max = arr[0];
	for (int i = 0; i < len; i++){
		if ( i ==0 ){
			with[0] = arr[0];
			without[0] = arr[0];
			continue;
		}
		with[i] = max(arr[i-1] + arr[i], with[i-1] + arr[i]);
		without[i] = max(arr[i-1], with[i-1]);
		current_max = max(current_max, max(arr[i],max(with[i],without[i])));

	}
	return current_max;
	
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
		int with[i];
		int without[i];
		int val = find_subarray(arr, i,  with, without);
		//print_arr(arr,i);
		//print_arr(with,i);
		//print_arr(without,i);
		printf("%d\n",val);
	}
	return 0;
}
