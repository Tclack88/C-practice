// https://www.codechef.com/practice/course/sorting/SORTING/problems/RACE400M?tab=statement
/* 
INPUT			OUTPUT
3
1 2 8			ALICE
4 100 1			CHARLIE
7 3 5			BOB
*/
#include <stdio.h>
#include <string.h>

int min(int a, int b){
    if (a<b)
        return a;
    return b;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y, z;
        char name[10];
        scanf("%d %d %d", &x, &y, &z);
        int m; // min
        m = min(min(x,y),z);
        if (m==x)
            strcpy(name, "ALICE");
        else if (m==y)
            strcpy(name,"BOB");
        else
            strcpy(name,"CHARLIE");
        printf("%s\n",name);
    }
    return 0;
}

