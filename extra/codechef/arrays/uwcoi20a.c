//https://www.codechef.com/practice/course/arrays/ARRAYS/problems/UWCOI20A
#include <stdio.h>

int main() {
    int T,N, num, max;
    scanf("%d",&T);
    for(int test = 1; test <= T; test++){
        scanf("%d",&N);
        for(int i=0; i < N; i++){
            scanf("%d",&num);
            if (i == 0)
                max = num;
            else
                if (num > max)
                    max = num;
        }
        printf("%d\n",max);
    }
    return 0;
}
