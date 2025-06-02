#include <stdio.h>

void printArr(int arr[], int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void merge(int* L, int lsize, int* R, int rsize, int* ret){
	int i=0,j=0,k=0;
	while (i<lsize && j<rsize){
		if (L[i] < R[j]){
			ret[k] = L[i];
			i++;
		}
		else{
			ret[k] = R[j];
			j++;
		}
		k++;
	}
	while (i<lsize){
		ret[k] = L[i];
		i++;
		k++;
	}
	while (j<rsize){
		ret[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[], int size){
	if (size <= 1)
		return;
	int lsize = size/2; // middle
	int rsize = size - lsize;
	merge_sort(arr,lsize);
	merge_sort(&arr[lsize],rsize);
	int ret[size];
	merge(arr,lsize,&arr[lsize],rsize,ret);
	for (int i=0; i<size; i++)
		arr[i] = ret[i];
}

int main(){
	int arr[] = {5};
	int size = sizeof(arr)/sizeof(arr[0]);
	printArr(arr,size);
	merge_sort(arr,size);
	printArr(arr,size);
	return 0;
}
