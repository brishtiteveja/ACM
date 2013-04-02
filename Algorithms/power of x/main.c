#include <stdio.h>


double pn(double a,int b){
	
    double remain_x = 1.0 ;
	
	if ( b < 0) {
		
		a = 1.0 / a ;
		
		b = -1 * b ;
		
	}
	
	while ( b > 0 ) {
		
		if ( b % 2 != 0) {
			remain_x =	remain_x * a ;
		}
		
		a =	a * a ;
		
		b = b / 2 ;
	}
	

	return remain_x ;
}




int main () {
    
	double x;
	int n;
	double result;
	
	printf("X=?");
	
	scanf("%lf",&x);
	
	printf("N=?");
	
	scanf("%d",&n);
	
	result = pn(x,n);
	
	printf("%lf to the power %d equals to %lf " ,x , n , result );
	
    return 0;
}


















