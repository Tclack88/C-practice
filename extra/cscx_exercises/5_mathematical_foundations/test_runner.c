#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set_operations.h"

#define MAX_LINE 500
#define MAX_SET_SIZE 5000

void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    FILE *test_cases = fopen("test_cases.txt", "r");
    FILE *expected_results = fopen("expected_results.txt", "r");
    
    if (!test_cases || !expected_results) {
        printf("Error: Could not open test files.\n");
        return 1;
    }

    char line[MAX_LINE], expected[MAX_LINE], op[20];
    int set1[MAX_SET_SIZE], set2[MAX_SET_SIZE], new_set[MAX_SET_SIZE];
    int l1, l2;

    while (fgets(line, sizeof(line), test_cases) && fgets(expected, sizeof(expected), expected_results)) {
        remove_newline(line);
        remove_newline(expected);

        sscanf(line, "%s", op);
        char *set_start = strstr(line, "set");
        if (!set_start) continue;

        char *set2_start = strstr(set_start + 3, "set");
        if (!set2_start) continue;

        l1 = make_set(line, set1, set_start - line + 3);
        l2 = make_set(line, set2, set2_start - line + 3);

        printf("Input: %s\n", line);
        printf("Expected: %s\n", expected);
        printf("Output: ");

        if (strcmp(op, "union") == 0)
            get_union(new_set, set1, set2, l1, l2);
        else if (strcmp(op, "intersection") == 0)
            get_intersection(new_set, set1, set2, l1, l2);

        printf("\n");
    }

    fclose(test_cases);
    fclose(expected_results);
    return 0;
}

