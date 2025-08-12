//https://www.codechef.com/learn/course/dynamic-programming/LIDPDSA06/problems/CNTWAYP?tab=Help
/*
The purpose of this code is "ribbon cutting" a ribbon of length N units is given and it must be cut into even units of max length L units (0,2,4...L)
Strategy: Dynamic programming using tabulation tables (2nd half of this long video https://www.youtube.com/watch?v=oBt53YbR9Kk).
Note: The online version requires you to change the values to mod (10^9 + 7) because they will be very large. I removed that here because it obscures and confuses the algorithm
INPUT:			OUTPUT:
4
6 4				3
4 2				1
2 2				1
8 6				7
*/
#include <stdio.h>
#include <string.h>

void printArr(int arr[], int size){
    for (int i=0; i<size; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void fillArr(int arr[], int N, int L){
    arr[0] = 1;
    for(int i=0; i<=N; i++){
        for(int j=2; j<=L; j+=2){
            if (i+j <= N)
                arr[i+j] += arr[i];
        }
    }
}

int main() {
    int T, N, L;
    scanf("%d", &T);
    while (T--){
        scanf("%d %d",&N, &L);
        int arr[N+1];
        memset(arr, 0, (N+1)*sizeof(int) );
        fillArr(arr, N+1, L);
        printf("%d\n",arr[N]);
    }
    return 0;
}
