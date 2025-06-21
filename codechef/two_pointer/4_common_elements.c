/*
https://www.codechef.com/practice/course/two-pointers/POINTERF/problems/PREP17
Given two arrays arr1 and arr2, each of size N, each with distinct elements, find the number of elements that are common in both the arrays.

Strategy: sort. all are distinct, so no need to work about repeats. Set a pointer to the begining of eacb array. advance the smaller one. If they meet, increment a counter. if either reach the end, terminate.
*/

#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int size){
	for (int i=0; i<size; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int comp(const void* a, const void* b){
	return *(int*) a - *(int*) b;
}

int main(){
	int T,N;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&N);
		int arr1[N];
		int arr2[N];
		for (int i=0; i<N; i++)
			scanf("%d",&arr1[i]);
		for (int i=0; i<N; i++)
			scanf("%d",&arr2[i]);
		qsort(arr1,N, sizeof(int),comp);
		qsort(arr2,N, sizeof(int),comp);
		int a = 0, b = 0, count = 0;
		while (a < N && b < N){
			if (arr1[a]==arr2[b]){
				count++;
				a++;
				b++;
			}
			else if (arr1[a] < arr2[b])
				a++;
			else
				b++;
		}
		printf("%d\n",count);
	}
	return 0;
}
