#include <stdio.h>

/* OLD Works but runtime can be large for large numbers. Strategy: use for loop 1 to size of number to
Append all factors, pass both arrays to a function to determine largest common factor */

/*
int is_divisor(int a,int b){
	if (a/b == (float) a / b)
		return 1;
	return 0;
}

void find_factors(int factors[], int n){
	int k = 0;
	for(int i=1; i <= n; i++){
		if (is_divisor(n,i)){
			factors[k] = i;
			k++;
		}
	}
	for (int i = k; i<n; i++) // zero-fill remainder of array
		factors[i] = 0;
}

int gcd(int arr1[], int size1, int arr2[], int size2){
	int greatest = 0;
	for (int i = 0; i < size1; i++){
		for (int j=0; j<size2; j++){
			if (arr1[i] == arr2[j] && arr1[i] > greatest)
				greatest = arr1[i];
			if (arr1[i] == 0 || arr2[j] == 0)
				break;
		}
		if (arr1[i] ==  0)
			break;
	}
	return greatest;
}

void print_arr(int arr[] ,int size){
	for (int i = 0; i < size; i++)
		printf("%d ",arr[i]);
}

int main(){
	int a;
	int b;
	while( scanf("%d %d",&a,&b) == 2 ){
		if (a == 0){
			printf("%d\n", b);
			continue;
		}
		else if (b == 0){
			printf("%d\n", a);
			continue;
		}
	
		int a_factors[a];
		int b_factors[b];

		//int a_max = (a / 2) + 1;
		//int b_max = (b / 2) + 1;

		find_factors(a_factors, a);
		find_factors(b_factors, b);

		//print_arr(a_factors, a_max);
		//print_arr(b_factors, b_max);
	
		int greatest =  gcd(a_factors, a, b_factors, b);
		printf("%d\n", greatest);
	}
		return 0;
	
}

*/

int gcd(int a,int b){
	if (b==0){
		return a;
	}
	int r = a % b; // remainder
	return gcd(b,r);
}

int main(){
	int a;
	int b;
	while( scanf("%d %d",&a,&b) == 2 ){
		if (a == 0){
			printf("%d\n", b);
			continue;
		}
		else if (b == 0){
			printf("%d\n", a);
			continue;
		}
	
		int greatest;
		if (a > b){
			greatest = gcd(a,b);
		}
		else{
			greatest = gcd(b,a);
		}
		printf("%d\n", greatest);
	}
	return 0;
	
}
