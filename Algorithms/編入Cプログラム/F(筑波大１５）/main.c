#include <stdio.h>

#include <math.h>
#include <string.h>

int N=5;

void f(char x[N]){
	int i ;
	for ( i = 0 ;  x[i] != '\0' ; i++ ) {
		if ( i > 0 && x[i-1] == '1' && x[i] == '1') {
			putchar('0');
		}
		else {
			putchar(x[i]);
		}

	}
	
}

int toInt(char x[]){
	int i,num ;
	num = 0 ;
	
	for (i=0; x[i] != '\0'; i++ ) {
		int a , j ;
		
		a = (x[i] - '0') ;
		for (j = 1; j < strlen(x) - i; j++) {
			a *= 2 ;
		}
		
		num += a ;
		
	}
	
	return num ;

}


int count (char x[N]) {

	int i ,len ,maxlen ;
	len = 0 ;
	maxlen = 0;
	
	for ( i = 0 ; x[i] != 0 ; i++ ) {
		
		int j;
		
		for ( j=i ; x[j] != '\0' ; j++ ) {
		    if (x[j] == '1') {
			    len++ ;
		    }
			else {
				break;
			}

		}
		if (len > maxlen) {
			maxlen = len ;
		}	
		len = 0 ;
	}
	
	return maxlen ;
}

int main () {
	
    printf("integer = %d \n" , toInt("1111111111111111111111111110101"));	
    printf("maxlenth of the string = %d \n",count("1101111011101111100001111111111"));
	return 0;
}
