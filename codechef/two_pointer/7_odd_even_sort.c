// https://www.codechef.com/practice/course/two-pointers/POINTERF/problems/DSAPROB16?tab=Help
/* Given a list of numbers. "sort it" such that odds are on the left and evens are on the right retaining the order

No clever way to do this inplace. Just waste space by making even and odd arrays and traverse the array like 3 times
INPUT:			OUTPUT
5
3 1 2 4 5		3 1 5 2 4
*/
#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int size){
	for (int i=0; i<size; i++)
    	printf("%d ",arr[i]);
	printf("\n");
}
int N;
void sortArrayByParity(int* nums) {
    int even_count = 0;
    int odd_count = 0;
    for (int i=0; i<N; i++){
        if (nums[i] % 2 == 0)
            even_count++;
        else
            odd_count++;
    }
    int evens[even_count];
    int odds[odd_count];
    int a=0; // odd index
    int b=0; // even index
    for (int i=0; i<N; i++){
        if (nums[i] % 2 == 0)
            evens[b++] = nums[i];
        else
            odds[a++] = nums[i];
    }
    for (int i=0; i<odd_count; i++)
        nums[i] = odds[i];
    for (int i=odd_count; i<N; i++)
        nums[i] = evens[i-odd_count];

	printf("odds:\n");
	printArr(odds,odd_count);
	printf("evens:\n");
	printArr(evens,even_count);
	printArr(nums,N);
}

int main() {
    scanf("%d", &N);
    int* nums = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
	printf("in main, N is %d\n",N);

    sortArrayByParity(nums);

    for (int i = 0; i < N; i++) {
        printf("%d ", nums[i]);
    }

    free(nums);
    return 0;
}
