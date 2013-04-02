#include <stdio.h>

int isprime(int n)
{
	int i ;
	for (i = 2 ; i <= n-1 ; i++ ) {
		if (n%2 == 0 && n!=2) {
			return 0;
		}
	}
/**	
	i = 2 ;
	while (i<= n -1 ) {
		if (n%2 == 0 && n!=2) {
			return 0;
		}
	}
**/
	return 1;
}


int main () {

    printf("%d = %d  \n	" , 93 , isprime(94));
    return 0;
}
