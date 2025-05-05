// https://www.codechef.com/practice/course/arrays/ARRAYS/problems/RATINGINPRAC
// NOTE: this gave a runtime error (after printing out the expected output) on the
// website, but it works locally and I can't see why not.
/*
4
3
1 2 3
3
1 1 2
5
100 200 300 400 350
5
1000 2000 5000 3000 1000

Yes
Yes
No
No*/
#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int d[n];
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &d[i]);
        }
        
        // Your code goes here
        if (n==1){
            printf("YES\n");
            continue;
        }
        int val = d[0];
        for(int i=0; i<n; i++){
            if (d[i] >= val)
                val = d[i];
            else{
                printf("No\n");
                break;
            }
            if (i+1 == n)
                printf("Yes\n");
        }
    }
    return 1;
}

