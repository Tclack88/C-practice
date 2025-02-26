#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "set_operations.h"

int find_char(char line[], char chr){
	char c = '\0';
	int i = 0;
	while (c!=chr){
		c = line[i];
		i++;
	}
	return i;
}

int make_set(char line[], int set[], int start){	
	int num_count = 0;
	int num,num_token;
	char num_token_string[4];
	int i = 0;
	char *token = strtok(&line[start]," ");
	while( token != NULL && strcmp(token,"set") != 0){
		if (strcmp(token,"set\n")==0 || strcmp(token,"\n")==0){
			token = strtok(NULL," ");// make next token
			continue; 	// avoid counting '\n', "set\n" as hits which atoi
						// converts to 0 and mistakenly adds to the set
		}
		set[i] = atoi(token);
		i++;
		token = strtok(NULL," ");
		num_count++;
	}
	return num_count;
}

void sort(int arr[], int len){
    int hold;
    for (int i=0; i<len-1; i++){
        for (int j=0; j<(len-1); j++){
            if (arr[j]>arr[j+1]){
                hold = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = hold;
            }
        }
    }
}

int flatten(int nums[], int len){
    //assumes all duplicates adjacent (eg. ordered)
    int newlen = len;
    for (int i=0; i<len-1; i++){
        if (nums[i] == nums[i+1]){
            for (int j = i; j < len; j++)
                nums[j] = nums[j+1]; // down shift everything
            newlen -= 1;
            i--; // stay in same spot checking ahead
        }
        if (i == newlen-1)
            break; // avoid overstepping original length
    }
    return newlen;
}

void print_set(int set[], int len){
	if (len == 0)
		printf("{}\n");
	else{
		printf("{");
		for (int k=0; k<len-1; k++)
			printf("%d,",set[k]);
		printf("%d}\n",set[len-1]);
	}
}

void get_union(int new_set[], int set1[], int set2[], int l1, int l2){
	int i=0;
	for (int j=0; j<l1; j++){
		new_set[i] = set1[j];
		i++;
	}
	for (int j=0; j<l2; j++){
		new_set[i] = set2[j];
		i++;
	}

	sort(new_set,(l1+l2));
	
	int new_len = flatten(new_set,(l1+l2));// remove duplicates

	print_set(new_set,new_len);
}

void get_intersection(int new_set[], int set1[], int set2[], int l1, int l2){
	int len=0;
	for (int i=0; i<l1; i++){
		for (int j=0; j<l2; j++){
			if (set1[i]==set2[j]){
				new_set[len]=set1[i];
				len++;
				break;
			}
		}
	}
	
	sort(new_set,len);

	int new_len = flatten(new_set,len);

	print_set(new_set,new_len);
}

/*
int main(){
	char op[13]; // sized to hold "intersect\n" +2
	char line[500];// hopefully big enough buffer for each line read in
	int set1[5000],set2[5000];
	int s1,s2;// hold location of "set"
	int l1,l2 = 0;
	int new_set[10000]; // max to hold set1+set2

	while( scanf("%s",op)==1 ){
		fgets(line, sizeof line, stdin);
		s1 = find_char(line,'s');
		s2 = find_char(&line[s1],'s');
		s2 += s1; // get abs starting point

		l1 = make_set(line, set1, s1+3);
		l2 = make_set(line, set2, s2+3);

		if (strcmp(op,"union")==0)
			get_union(new_set, set1,set2,l1,l2);
		else if( strcmp(op,"intersection")==0)
			get_intersection(new_set, set1,set2,l1,l2);
	}
}
*/
