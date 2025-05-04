//https://www.codechef.com/practice/course/arrays/ARRAYS/problems/LARGESECOND

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
        int largest = a[0];
        int second_largest = a[0];
        for(int i=0; i<n; i++){
            if(a[i] > largest)
                largest = a[i];
            if(a[i] < second_largest)
                second_largest = a[i]; //
        }
        for(int i=0; i<n; i++){
            if(a[i] > second_largest &&  a[i] < largest)
                second_largest=a[i];
        }
        printf("%d\n",largest+second_largest);
        // my code ends here
    }
    return 0;
}

