#include <stdio.h>

int N = 11 ;

int data[7]={ 8 , 10 , 0 , 10 , 6 , 5 ,2 };

int main () {
    int i,j,k,B[11];
	
	
	for (k = 0; k <= 10; k++) {
		B[k] = 0;
	}
	for (i = 0; i < N ; i++ ) {
		
		printf("B[%d] = %d \n",i ,B[i]);
	}
    for (i = 0; i < N ; i++ ) {
		B[data[i]] = B[data[i]] + 1 ;
	}
	for (i = 0; i < N ; i++ ) {
		
		printf("B[%d] = %d \n",i ,B[i]);
	}
	printf("\n");
	
	
	
	i = 0 ;
	
	for (k = 0 ; k < 7  ; k++){
	    for ( j = k+1 ; j < 7 ;j++ ) {
			if (data[j] < data[k] ) {
				i = data[k];
				data[k] = data[j];
				data[j] = i;
			}
		}
	}
	for (i = 0; i < 7 ; i++ ) {
			printf("data[%d] = %d \n",i ,data[i]);
	}
	
    return 0;
}
