#include <stdio.h>
#define TRUE 1
#define FALSE 0

int iseven(int n){
	return n % 2 == 0 ? TRUE : FALSE ; 
}

int square(int n){
	return n * n;
}

int halve(int n){
	return n/2;
}

int func(int b,int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return iseven( n ) ? func ( square(b) , halve( n ) ) : b * func( b , n-1 ) ; 
	}

}




int main (int argc, const char * argv[]) {
	
	int b , n ;
    // insert code here...
    scanf("%d%d",&b,&n);
	printf("power = %d \n",func( b , n ) );
    return 0;
}
