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
	int with[2];
	int without[2];
	int current_max = arr[0];
	for (int i = 0; i < len; i++){
		if ( i ==0 ){
			with[0] = arr[0];
			without[0] = arr[0];
			continue;
		}
		with[1] = max(arr[i-1] + arr[i], with[0] + arr[i]);
		without[1] = max(arr[i-1], with[0]);
		current_max = max(current_max, max(arr[i],max(with[1],without[1])));
		with[0] = with[1];
		without[0] = without[1];

	}
	return current_max;
	
}

int main(){
	//char input[4000];
	//int arr[1001];
	//while ( fgets(input, 4000, stdin) != NULL ){
	char input[400000];
	int arr[100001];
	while ( fgets(input, 400000, stdin) != NULL ){
		int i = 0;
		char* token = strtok(input," ");
		while(token != NULL){
			sscanf(token,"%d",&arr[i] );
			i++;
			token = strtok(NULL," ");
		}
		int val = find_subarray(arr, i);
		//print_arr(arr,i);
		//print_arr(with,i);
		//print_arr(without,i);
		printf("%d\n",val);
	}
	return 0;
}
