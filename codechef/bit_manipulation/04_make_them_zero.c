// https://www.codechef.com/learn/course/bit-manipulation/BITM04/problems/MAKEZERO
/* Similar to the last one, several numbers' bits are added (really bitwise or'd together) and you must determine how many ones there are unthe pretense of how many steps it would take to subtract the one digit for each number if applicable
INPUT:			OUTPUT:
4				1
3				2
2 2 2			0
4				2
2 2 2 4
2
0 0
3
1 2 3
*/
#include <stdio.h>

int count_bits(int n){
    int n_copy = n;
    int size = 0;
    while(n_copy > 0){
        n_copy /= 2;
        size++;
    }
    int bit_count = 0;
    for(int i=0; i<size; i++)
        bit_count += (1<<i & n ? 1 : 0);
    return bit_count;
}

int main(){
    int T,N,n;
    scanf("%d", &T);
    while (T--){
        int total = 0;
        scanf("%d",&N);
        while(N--){
            scanf("%d",&n);
            total |= n;
        }
        int bit = count_bits(total);
        printf("%d\n",bit);
    }
    return 0;
}
