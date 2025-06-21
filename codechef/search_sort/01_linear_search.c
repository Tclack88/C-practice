#include <stdio.h>

int main() {
	int size, n;
	scanf("%d %d",&size, &n);
	int arr[n];

	for(int i=0; i<size; i++)
	    scanf("%d",&arr[i]);
	    
	for(int i=0; i<size; i++){
	    if (arr[i] == n){
	        printf("Yes\n");
	        return 0;
	    }
	}
	printf("No\n");
	return 0;
}

