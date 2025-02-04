#include <stdio.h>
/* WARNING: SLOOOW on the order of 1 million. this is nto the most efficient way of doing this */
#define N 100000 // cannot set n in main 
				 // "variable-sized object may not be initialized"
				 // so I set it up here as a define

void elim(int num_list[], int prime, int j){
	// note: Although I realize I linked list is a better data
	// structure. Quicker, much easier to implement. I will stick
	// with a less sophisticated algorithmic way of doing this
	// for the sake of misery and practice
	num_list[j] == '\0';	
	for (int k=j; k<N; k++){
		num_list[k] = num_list[k+1];
		if (num_list[k] == '\0')
			break; // break early, don't pull in junk data
	}
}

void print_list(int num_list[]){
	int count = 0;
	for (int i = 0; i < N; i++){
		if (num_list[i] == '\0')
			break;
		printf("%d,",num_list[i]);
		count++;
	}
	printf("\n\tsize of list: %d\n",count);
}


int main(){
	int num_list[N+2] = {0};
	int prime;
	for (int i=2; i<=N; i++)
		num_list[i-2] = i;// build list starting from 2
	num_list[N] = '\0'; // terminate with nullbyte
	//print_list(num_list);
	//printf("\n");
	
	for (int i=0; i<N/2; i++){
		prime = num_list[i];
		if (prime == 0 || prime >= N/2)
			break; // means we've gone past our provided list
		//printf("checking out %d\n",prime);
		for (int j=i+1; j<N/2+1; j++){
			if (num_list[j]=='\0')
				break;
			if (num_list[j]%prime == 0){
				//printf("\t%d is divisible by %d, eliminating...\n", num_list[j],prime);
				elim(num_list,prime,j);
			}
		}
	}
	print_list(num_list);
	printf("\n");

	return 0;
}
