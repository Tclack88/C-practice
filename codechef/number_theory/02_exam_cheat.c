//https://www.codechef.com/learn/course/number-theory/LINTDSA02/problems/EXAMCHTPRIME?tab=statement
/* Weird story about two people trying to cheat on an exam and it's only possible if (a-1)%p == (b-1)%p
where a and b are the exam number assigned to each student and p is like any integer. (return -1 if infinite)
Strategy: (a-1)%p == (b-1)%p is the same as checking if a%p == b%p, which is true for all factors of p where abs(a-b) is evenly divisible. We don't have to check all factors up to a-b, just the factors up to the square root of a-b. If the value happens to be the square root of a-b, then we increment the count by 1 (because we're looking just for the unique factors), otherwise, any other divisible number needs to be incremented by 2 (because there are pairs.
INPUT:		OUTPUT:
4
1 2			1
2 6			3
2 7			2
36 1		4
*/
#include <stdio.h>
#include <stdlib.h>

void find_vals(int a, int b){
    if (a==b)
            printf("-1\n");
    else{
        int count = 0;
        int val = abs(a-b);
        if (val == 1)
            printf("1\n");
        else{
            for (int i=1; i*i <= val; i++){
                if (i*i == val)
                    count++;
				else if (val%i == 0)
					count += 2;
            }
            printf("%d\n",count);
        }
    }
}

int main() {
    int T, a, b;
    scanf("%d",&T);
    while (T--){
        scanf("%d %d",&a, &b);
        find_vals(a,b);
    }
    return 0;
}
