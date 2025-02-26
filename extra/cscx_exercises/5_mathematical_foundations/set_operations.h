#ifndef SET_OPERATIONS_H
#define SET_OPERATIONS_H

void get_union(int new_set[], int set1[], int set2[], int l1, int l2);
void get_intersection(int new_set[], int set1[], int set2[], int l1, int l2);
int make_set(char line[], int set[], int start);
void print_set(int set[], int len);

#endif
