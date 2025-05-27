/*
https://www.codechef.com/learn/course/searching-sorting/SORTSEARCH1/problems/SESO05?tab=statement
INPUT:		OUTPUT 	
4			"yes"
2 3
4 5
3 5   <-- 3 5
1 7
5 3   <-- 5 3
*/

#include <stdio.h>

int main() {
	int n, a,b;
	scanf("%d",&n);
	int arr1[n];
	int arr2[n];
	for (int i=0; i<n; i++){
	    scanf("%d %d",&arr1[i], &arr2[i]);
	}
	scanf("%d %d",&a, &b);
	
	for (int i=0; i<n; i++){
	    if (arr1[i] == a && arr2[i] == b || arr1[i] == b && arr2[i] == a){
	        printf("Yes\n");
	        return 0;
	    }
	}
	printf("No\n");
	return 0;
}

