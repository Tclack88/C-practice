// https://www.codechef.com/practice/course/arrays/ARRAYS/problems/RUNCOMPARE
#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n], b[n];
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        // my code starts here
        int happy = 0;
        for(int i=0; i < n; i++){
            if (a[i] <= 2*b[i] && b[i] <= 2*a[i])
                happy++;
        }
        printf("%d\n",happy);
        // my code ends here
    }
    

    return 0;
}

