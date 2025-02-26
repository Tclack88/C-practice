#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int DEBUG = 0;

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
	//printf("set entering make_set: ")
	//for (int k =0 ; k < (set[start] - set)
	char *token = strtok(&line[start]," ");
	while( token != NULL && strcmp(token,"set") != 0){
		if (strcmp(token,"set\n")==0 || strcmp(token,"\n")==0){
			token = strtok(NULL," ");
			continue; 	// avoid counting '\n', "set\n" as hits which atoi
						// converts to 0 and mistakenly adds to the set
		}
		//printf("token: '%s' ",token);
		set[i] = atoi(token);
		i++;
		token = strtok(NULL," ");
		num_count++;
		//if (token!= NULL)
		//	num_count++;
	}
	//printf("no more tokens\n");
	return num_count;
}


int make_set2(char line[], int set[], int start){
	int num_count = 0;
	int num;
	char *ptr = &line[start];

	while (sscanf(ptr, "%d", &num) == 1) {
		set[num_count++] = num;
		while (*ptr && *ptr != ' ') ptr++; // Move to next space
		while (*ptr == ' ') ptr++; // Skip extra spaces
		if (strncmp(ptr, "set", 3) == 0 || *ptr == '\n') break;
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
    //for(int i=0; i<len; i++)
    //    printf("%d-",arr[i]);
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
	//int new_set[l1+l2+1];
	int i=0;
	for (int j=0; j<l1; j++){
		new_set[i] = set1[j];
		i++;
	}
	for (int j=0; j<l2; j++){
		new_set[i] = set2[j];
		i++;
	}

	if (DEBUG){
		printf("l1: %d\n",l1);
		printf("l2: %d\n",l2);
		printf("i:%d l1+l2: %d\n",i,(l1+l2));
		printf("after UNION: ");
		print_set(new_set,(l1+l2));
	}
	

	sort(new_set,(l1+l2));
	//sort(new_set,(i));
	
	if (DEBUG){
		printf("DEBUG: after sort: ");
		print_set(new_set,(l1+l2));
	}

	int new_len = flatten(new_set,(l1+l2));// remove duplicates


	if (DEBUG){
		printf("new len: %d\n",new_len);
		printf("DEBUG: after flatten (FINAL): ");
		print_set(new_set,new_len);
		printf("\n");
	}
	else
		print_set(new_set,new_len);
}



void get_intersection(int new_set[], int set1[], int set2[], int l1, int l2){
	int len=0;
	for (int i=0; i<l1; i++){
		for (int j=0; j<l2; j++){
			//printf("comparing set1[%d],set2[%d] %d,%d-- se\n",i,j,set1[i],set2[j]);
			if (set1[i]==set2[j]){
				//printf("MATCH!\n");
				new_set[len]=set1[i];
				len++;
				break;
			}
		}
	}
	
	if (DEBUG){
		printf("l1: %d\n",l1);
		printf("l2: %d\n",l2);
		printf("\nDEBUG: after INTERSECTION:(len: %d) ",len);
		print_set(new_set,len);
	}

	sort(new_set,len);

	if (DEBUG){
		printf("\nDEBUG: after sort: ");
		print_set(new_set,len);
	}

	int new_len = flatten(new_set,len);

	if (DEBUG){
		printf("\nnew length: %d\n", new_len);
		printf("\nDEBUG: after flatten (FINAL): ");
		print_set(new_set,new_len);
		printf("\n");
	}
	else
		print_set(new_set,new_len);
	
	/*if (new_len == 0)
		printf("{}\n");
	else{
		printf("\n\n{");
		for (int k=0; k<new_len-1; k++)
			printf("%d,",new_set[k]);
		printf("%d}\n",new_set[new_len-1]);
	}*/
}


int main(){
	char op[13]; // sized to hold "intersect\n" +2
	char line[500];// hopefully big enough buffer for each line read in
	int set1[100],set2[100];
	int s1,s2;// hold location of "set"
	int l1,l2 = 0;
	int new_set[200]; // max to hold set1+set2


	while( scanf("%s",op)==1 ){
		//int set1[] = {0};
		//int set2[] = {0};
		fgets(line, sizeof line, stdin);
		s1 = find_char(line,'s');
		s2 = find_char(&line[s1],'s');
		s2 += s1; // get abs starting point

		l1 = make_set(line, set1, s1+3);
		l2 = make_set(line, set2, s2+3);
		if (DEBUG){
			printf("TESTING ");
			print_set(set1,l1);
			print_set(set2,l2);
		}

		if (strcmp(op,"union")==0)
			get_union(new_set, set1,set2,l1,l2);
		else if( strcmp(op,"intersection")==0)
			get_intersection(new_set, set1,set2,l1,l2);
		//else
		//	printf("got something else, op: '%s'\n",op);


		/*for (int k=0;k<l1;k++){
			printf("%d\n",set1[k]);
		}
		for (int k=0;k<l2;k++){
			printf("%d\n",set2[k]);
		}*/
	}
}
