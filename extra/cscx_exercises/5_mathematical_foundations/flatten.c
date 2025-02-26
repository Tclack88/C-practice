#include <stdio.h>

void print_set(int set[], int len){
    if (len == 0)
        printf("{}\n");
    else{
        printf("{");
        for (int k=0; k<len-1; k++)
            printf("%d,",set[k]);
        printf("%d}\n",set[len-1]);
    }
}

int flatten(int nums[], int len){
	//assumes all duplicates adjacent (eg. ordered)
	int newlen = len;
	for (int i=0; i<len-1; i++){
		if (nums[i] == nums[i+1]){
			for (int j = i; j < len; j++)
				nums[j] = nums[j+1]; // down shift everything
			newlen -= 1;
			i--; // stay in same spot checking ahead 
		}
		if (i == newlen-1)
			break; // avoid overstepping original length
	}
	return newlen;
}

int flatten2(int nums[], int len){
	//assumes all duplicates adjacent (eg. ordered)
	int newlen = len;
	for (int i=0; i<len-1; i++){
		if (nums[i] == nums[i+1]){
			for (int j = i; j < len; j++)
				nums[j] = nums[j+1]; // down shift everything
			newlen -= 1;
			i--; // stay in same spot checking ahead 
		}
		if (i == newlen-1)
			break; // avoid overstepping original length
	}
	return newlen;
}


int main(){
	int nums[] = {1,1,2,3,2,3,2,3,2,4,5,5,5,5,6,6,1,6};
	int len = sizeof(nums)/sizeof(int);

	int nums2[] = {1,1,2,3,2,3,2,3,2,4,5,5,5,5,6,6,1,6};
	print_set(nums,len);
	printf("------------\n");
	int newlen = flatten(nums,len);

	int len2 = sizeof(nums2)/sizeof(int);
	int newlen2 = flatten2(nums2,len2);

	printf("newlen: %d\n",newlen);
	print_set(nums,newlen);
	printf("newlen2: %d\n",newlen2);
	print_set(nums2,newlen2);
	return 0;
}
