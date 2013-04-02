#include <stdio.h>

int ccount(char str[],char c){
    int i=0,count=0;
	
	while (str[i++] != '\0') {
		if (str[i-1]==c) {
			count++;
		}
	}
	return count;
}

int main (int argc, const char * argv[]) {
    
	char *str="hellobrishtiiloveulol";
	
    printf("counted character = %d \n", ccount(str,'m'));
    return 0;
}


