#include <stdio.h>
/*  https://www.codechef.com/practice/course/sorting/SORTING/problems/FACEBOOK?tab=statement
In this problem, two sets of arrays are given. 
1. # of likes on a post
2. # of comments on a post
A post is "popular" if it has the most likes, but if likes are equal,
then the most comments gets priority. Must return index (starting from 1)
of the most popular post


INPUT:				OUTPUT:
4					1
3					2
5 4 4				3
1 2 3				2
3
10 10 9
2 5 4
3
3 3 9
9 1 3
4
2 8 1 5
2 8 1 9

I chose to do a radix sort, to practice and it seems fitting. Used merge
sort as the sorting agent. First sorting by comment, then by likes
Using a reverse merge sort (givving the greatest val first)*/
void printArr(int arr[], int size){
    for (int k=0; k<size-1; k++)
        printf("%d ",arr[k]);
    printf("%d\n",arr[size-1]);
}

void rev_merge(int* L, int* L1, int* L2, int lsize, int* R, int* R1, int *R2, int rsize, int* ret, int* ret1, int* ret2){
    int i=0,j=0,k=0;
    while (i<lsize && j<rsize){
        if (L[i] >= R[j]){ // KEY right here! previously I did >, 
			// which meant when there were two repeated vals,
			// The one to the right would be chosen first, removing
			// the "stable" nature of the sort
            ret[k] = L[i];
            ret1[k] = L1[i];
            ret2[k] = L2[i];
            i++;
        }
        else{
            ret[k] = R[j];
            ret1[k] = R1[j];
            ret2[k] = R2[j];
            j++;
        }
        k++;
    }
    while (i<lsize){
        ret[k] = L[i];
        ret1[k] = L1[i];
        ret2[k] = L2[i];
        i++;
        k++;
    }
    while (j<rsize){
        ret[k] = R[j];
        ret1[k] = R1[j];
        ret2[k] = R2[j];
        j++;
        k++;
    }
}

void rev_merge_sort(int arr[], int size, int arr1[], int arr2[]){
    if (size <= 1)
        return;
    int lsize = size/2; // middle
    int rsize = size - lsize;
    rev_merge_sort(arr,lsize,arr1,arr2);
    rev_merge_sort(&arr[lsize],rsize,&arr1[lsize],&arr2[lsize]);
    int ret[size];
    int ret1[size];
    int ret2[size];
    rev_merge(arr,arr1,arr2,lsize,&arr[lsize],&arr1[lsize],&arr2[lsize],rsize,ret,ret1,ret2);
    for (int i=0; i<size; i++){
        arr[i] = ret[i];
        arr1[i] = ret1[i];
        arr2[i] = ret2[i];
    }
}


void radix_sort(int* A, int* B, int* idx, int size){
    // not using counting sort because I don't know hashtables yet an
    // the potential size is too large for an array to store the counts
    rev_merge_sort(B,size,A,idx);
    rev_merge_sort(A,size,B,idx);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n], b[n], idx[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            idx[i] = i+1; // set an index array
        }
        
        radix_sort(a,b,idx,n);
		printf("%d\n",idx[0]);
    }
    return 0;
}
