/* https://www.codechef.com/learn/course/searching-sorting/SORTSEARCH1/problems/SESO04
INPUT:				OUTPUT
HelloHowYouDoing	7
w

HelloFriends		-1
P
*/
#include <stdio.h>

int main() {
	char str[400];
	char letter;
	scanf("%s\n%c",str,&letter); // *
	printf("str: %s\n",str);
	printf("letter: %c\n",letter);
    for (int i=0; i<sizeof(str)*sizeof(char); i++){
        if (str[i]==letter){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n",-1);
    return 0;
}
// * previously I've been able to scanf regardless of the 
// whitespace between. i.e. when taking in numbers, I could do:
// scanf("%d",&m);
// scanf("%d",&n);
// and it didn't matter whether they were space or newline sep.
// BUT with taking in something followed by a char
// the newline will be read and placed in the char variable
