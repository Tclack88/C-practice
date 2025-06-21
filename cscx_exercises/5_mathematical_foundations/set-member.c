#include <stdio.h>
#include <string.h>

void print_set(int num_list[], int num_list_len){
	if (num_list_len == 0)
		printf("{}\n");
	else{
		printf("{");
		for(int k=0; k < num_list_len-1; k++)
			printf("%d,",num_list[k]);
		printf("%d}\n",num_list[num_list_len-1]);
	}
}

int main(){
	int num_list[100];
	char op[7];
	char num_char[12] = "";
	char c='a';
	int i,j,k,num,check,present;
	int num_list_len = 0;
	while( scanf("%s",op)==1 ){
		j=0;
		present = 0;
		if( strcmp(op,"set")==0 ){

			i = 0;
			c = fgetc(stdin);	
			while( c!='\n' ){
				c = fgetc(stdin);	
				num_char[i]=c;
				i++;
				if (c==' ' || c=='\n'){
					sscanf(num_char, "%d", &num);
					num_list[j]=num;
					j++;
					i=0;
				}
			}
			num_list_len=j;
			printf("using %s ",op); //{",op);
			print_set(num_list,num_list_len);
		}
		else{ // op must be member
			scanf("%d",&check);
			printf("%d is",check);
			for(k=0; k<num_list_len; k++){
				if(num_list[k]==check){
					present = 1;
					break;
				}
			}
			if (!present)
				printf(" not");
			printf(" an element of ");
			print_set(num_list,num_list_len);

		}
	}
	return 0;
}
