// https://www.codechef.com/practice/course/arrays/ARRAYS/problems/KITCHENCOST

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, x;
        scanf("%d %d", &n, &x);
        int a[n], b[n];
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[j]);
        }
        
        // my code starts here
        int cost = 0;
        for(int i=0; i<n; i++){
            if (a[i] >= x)
                cost += b[i];
        }
        printf("%d\n",cost);
        // my code ends here
    }
}

