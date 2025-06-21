// https://www.codechef.com/learn/course/trees/TREES/problems/DSCPP81
/* given a size N (for a symmetric NxN matrix) and a set of nodes input and outputs, build an adjacency matrix showing the tree links
INPUT:		OUTPUT:	
6			0 1 1 0 0 0
0 1			0 0 0 1 1 0
0 2			0 0 0 0 0 1
1 3			0 0 0 0 0 0
1 4			0 0 0 0 0 0
2 5			0 0 0 0 0 0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArr(int* arr,int N){
    for(int i=0;i<N;i++){
        for(int j=0; j<N; j++)
            printf("%d ",arr[N*i + j]);
        printf("\n");
    }
}

int main() {
    int N,a,b;
    scanf("%d",&N);
    int arr[N][N];
	memset(arr,0,sizeof(arr));
    for (int i=0; i<N; i++){
        scanf("%d %d", &a,&b);
        arr[a][b] = 1;
    }
    printArr(&arr[0][0],N);
    
    return 0;
}
