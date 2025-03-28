// wordinator challenge on 0de5 as explained here
// 0de5.net/stimuli/just-enough-c-to-have-fun
// in brief it takes numeric values and converts to spoken words
// 2002 -> "two thousand and two", 147000000 "one hundred and forty-seven million", etc.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void spell_single(int num){
	switch (num){
		case 1: printf("%s","one"); break;
		case 2: printf("%s","two"); break;
		case 3: printf("%s","three"); break;
		case 4: printf("%s","four"); break;
		case 5: printf("%s","five"); break;
		case 6: printf("%s","six"); break;
		case 7: printf("%s","seven"); break;
		case 8: printf("%s","eight"); break;
		case 9: printf("%s","nine"); break;
	}
	
}

void spell_tens(int num){
	num /= 10;
	switch (num){
		case 2: printf("twenty"); break;
		case 3: printf("thirty"); break;
		case 4: printf("forty"); break;
		case 5: printf("fifty"); break;
		case 6: printf("sixty"); break;
		case 7: printf("seventy"); break;
		case 8: printf("eighty"); break;
		case 9: printf("ninety"); break;
	}
}

void spell_teens(int num){
	if (num==10 || num%10 > 0){
		switch (num){
			case 10: printf("ten"); break;
			case 11: printf("eleven"); break;
			case 12: printf("twelve"); break;
			case 13: printf("thirteen"); break;
			case 14: printf("fourteen"); break;
			case 15: printf("fifteen"); break;
			case 16: printf("sixteen"); break;
			case 17: printf("seventeen"); break;
			case 18: printf("eighteen"); break;
			case 19: printf("nineteen"); break;
		}
	}
}

void spell_triplet(int in_num){
	int tmp = in_num;

	if (in_num/100 > 0){
		tmp = in_num/100;
		spell_single(tmp);
		printf(" hundred ");
		tmp = in_num%100;
		if (tmp > 0)
			printf("and ");
	}
	if (tmp > 0){
		if (tmp >=20){
			spell_tens(tmp);
			if (tmp%10 > 0)
				printf("-"); // eg: 47 -> forty-seven, not fortyseven
			spell_single(tmp%10);
		}
		else if (tmp > 9)
			spell_teens(tmp);
		else{
			spell_single(tmp%10);
		}
	}
}

int main(){
	int size,offset;
	//char input[] = "1337";
	//char input[] = "147000001";
	char input[] = "2123087128";
	char tmp[10], slice[4];
	int i = 0;
	sscanf(&input[i], "%s", tmp);
	size = strlen(tmp);
	printf("%s:\t",tmp);
	if (strcmp(input,"0")==0){ // zero edge-case
		printf("zero\n");
		return 0;
	}
	if (size > 9 && size <= 12){
		spell_triplet(atoi(tmp)/1000000000);
		printf(" billion");
		if (atoi(tmp)%1000000000 > 0)
			printf(",");
		printf(" ");
		offset = size - 9;
		i += offset;
		sscanf(&input[i], "%s", tmp);
		size = strlen(tmp);
	}
	if (size > 6 && size <= 9){
		spell_triplet(atoi(tmp)/1000000);
		if (atoi(tmp)/1000000 > 0){
			printf(" million");
			if (atoi(tmp)%1000000 > 0)
				printf(",");
		printf(" ");
		}
		offset = size - 6;
		i += offset;
		sscanf(&input[i], "%s", tmp);
		size = strlen(tmp);
	}
	if (size > 3 && size <= 6){
		spell_triplet(atoi(tmp)/1000);
		if (atoi(tmp)/1000 > 0){
			printf(" thousand");
			if (atoi(tmp)%1000 > 0)
				printf(",");
		printf(" ");
		}
		offset = size - 3;
		i += offset;
		sscanf(&input[i], "%s", tmp);
		size = strlen(tmp);
	}
	if (size > 0 && size <= 3){
		if (atoi(tmp)%100 == atoi(tmp) && atoi(tmp) != 0)  
			printf("and ");
		spell_triplet(atoi(tmp));
		offset = size;
		i += offset;
		sscanf(&input[i], "%s", tmp);
		size = strlen(tmp);
	}

	printf("\n");
	return 0;
}
