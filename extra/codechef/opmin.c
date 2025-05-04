//https://www.codechef.com/practice/course/arrays/ARRAYS/problems/OPMIN

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        // my code starts here
        int min = a[0];
        for (int i=0; i<n; i++){
            if (a[i]<min)
                min = a[i];
        }

        int non_min_count = 0;
        for (int i=0; i<n; i++){
            if (a[i] > min)
                non_min_count++;
        }
        printf("%d\n",non_min_count);
        // my code ends here
    }

    return 0;
}

