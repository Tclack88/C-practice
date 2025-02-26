#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "set_operations.h"

void test_sets() {
    char line[500];
    int set1[5000], set2[5000], new_set[10000];
    int l1, l2;

    // Test 1: Union of {1,2,3} and {3,4}
    strcpy(line, "set 1 2 3 set 3 4");
    l1 = make_set(line, set1, 4);
    l2 = make_set(line, set2, 12);
    get_union(new_set, set1, set2, l1, l2);
    assert(memcmp(new_set, (int[]){1,2,3,4}, 4 * sizeof(int)) == 0);

    // Test 2: Intersection of {1,2,3} and {2,3}
    strcpy(line, "set 1 2 3 set 2 3");
    l1 = make_set(line, set1, 4);
    l2 = make_set(line, set2, 12);
    get_intersection(new_set, set1, set2, l1, l2);
    assert(memcmp(new_set, (int[]){2,3}, 2 * sizeof(int)) == 0);

    // Test 3: Empty set intersection
    strcpy(line, "set 1 2 3 set 4 5 6");
    l1 = make_set(line, set1, 4);
    l2 = make_set(line, set2, 12);
    get_intersection(new_set, set1, set2, l1, l2);
    assert(memcmp(new_set, (int[]){}, 0 * sizeof(int)) == 0);

    printf("All tests passed!\n");
}

int main() {
    test_sets();
    return 0;
}
