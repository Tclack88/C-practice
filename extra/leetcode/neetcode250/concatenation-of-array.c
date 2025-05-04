// https://leetcode.com/problems/concatenation-of-array/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*) calloc(2*numsSize,sizeof(int));
    for(int i=0; i <numsSize; i++){
        *ans = nums[i];
        ans++;
    }
    // printf("%c %c %c\n",nums[0],nums[1],nums[2]);
    for(int j=numsSize; j<2*numsSize; j++){
        *ans=nums[j-numsSize];
        ans++;
    }
    ans -= 2*numsSize; // reset pointer to start of array
    *returnSize = 2*numsSize;
    return ans;
}
