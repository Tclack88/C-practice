#include <stdio.h>
#include <string.h>

int main(){
	char set[4];
	char op[12]; // intersection or union
	int i,j;
	char c;
	char num[100];
	int set1[100],set2[100];

	/*char temp1[10];
	int res1;
	scanf("%s",set);
	res1 = strcmp(set,"set");
	printf("testing: %d",res1);*/
	while (scanf("%s",op)==1 ){
		j=0;
		scanf("%s",set);
		c = fgetc(stdin); // will scan a space
		while( c!='\n'){
			c = fgetc(stdin);
			printf("inside while loop c reads: '%c'\n",c);
			if(strcmp(set,"set")==0 || strcmp(set,"et")==0){
				printf("sucessful stringcmp with 'set' or 'et': %s\n",set);
				i = 0;
				while( c!='s' ){// looking for next "set" string
					num[i] = c;//sscanf(c,"%c",num[i]);
					if(c==' '){
						num[i]='\0'; // set nullbyte
						sscanf(num,"%d",&set1[j]);	
						j++;
						i=0;
					}
					else
						i++;
					c = fgetc(stdin);
				}
				printf("hit an s char, think I'm at next 'set'\n");
				for(int k=0; k<j; k++){
					printf("%d ",set1[k]);
				}
				j=0;
			}
			scanf("%s",set);
			printf("scanned set again, result: %s\n",set);
		}
		printf("I am at a new line!\n");
	}
}
