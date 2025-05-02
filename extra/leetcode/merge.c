#include <stdio.h>

// This worked locally, but not in leetcode (overflow error caused by not ensuring a < m and b < n or something , so I had to change it (below)
/*void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int spare[nums1Size];
    int a = 0;
    int b = 0;
    for (int  i = 0; i < nums1Size; i++){
        if ((nums1[a] < nums2[b]) && (a < m)){
            spare[i] = nums1[a];
            a++;
        }
        else{
            spare[i] = nums2[b];
            b++;
        }
    }

    for (int i=0; i < nums1Size; i++){
        nums1[i] = spare[i];
    }
}*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int spare[nums1Size];
    int a = 0;
    int b = 0;
    int i = 0;
    while (a < m && b < n){
        if(nums1[a] < nums2[b] && a < m){
            spare[i] = nums1[a];
            a++;
		}
        else{
            spare[i] = nums2[b];
            b++;
        }
        i++;
    }

	while(a < n){
        spare[i++] = nums1[a++];
    }

    while(b < n){
        spare[i++] = nums2[b++];
    }

    for (int i = 0; i < nums1Size; i++) {
        nums1[i] = spare[i];
    }
}

int main(){
	int nums1Size = 6;
	int nums1[] = {1,2,3,0,0,0};
	int m = 3;
	int nums2Size = 3;
	int nums2[] = {2,5,6};
	int n = 3;

	merge(nums1, nums1Size, m, nums2,nums2Size, n);
	for(int i=0; i <nums1Size; i++){
		printf("%d\n",nums1[i]);
	}
	return 0;
}
