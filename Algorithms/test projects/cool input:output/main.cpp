#include <stdio.h>

int main () {

	int h,m;
	
	char digits[100];
	char input[100],ch;
	
	scanf("%d:%d\n",&h,&m);
	scanf("%[^\n]",digits);
	
	printf("%d:%d\n",m,h);
	printf("%s\n",digits);
	
	
	printf("%s\n",input);
	printf("%c\n",ch);
	
		
	return 0;
}
