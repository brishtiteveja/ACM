#include <stdio.h>
#include <stdlib.h>

char* STRING = ",Toyohashi,Gijutsu-kagaku,daigaku" ;
int N = 3 ;


int split(const char* string , const char delimeter , char*** strings ,int max ){ //triple pointer is used so that it can be possible to use the double pointer string(array ) of the main function and to be able to make changes of the array from outside of the main function  , *** strings is taking the adress of the **string of the main function 

	int i , len, n_tokens = 0 ;
	const char* token_start;
	const char* s ;
	
    if (string == '\0') {
		return 0 ;
	}
	
	*strings = (char**)malloc(sizeof(char*) * max ) ;
	
	for (i = 0 ; i < max ; i++ ) {
		(*strings)[i] = NULL ; // easy interpretation of the matrix string[i] of the main function 
	}
	
	s = string ;
	token_start = string ;
	
	while (n_tokens != max ) {
		
		while (*s != delimeter && *s != '\0') {
			s++ ;
		}
		
		len = s - token_start ;
		
		(*strings)[n_tokens] = (char*)malloc(sizeof(char) * (len + 1) );
		
		for (i = 0 ; i < len ; i++) {
			(*strings)[n_tokens][i] = token_start[i] ;
		}
		(*strings)[n_tokens][i] = '\0' ;
		
		token_start = s + 1 ;
		
		n_tokens++ ;
		
		if (*s == '\0') {
			break ;
		}
		
		s++;
		
	}
	return n_tokens ;
	
}


int main () {
    
	int n;
	
	char **string ;
	
	n = split( STRING , ',' , &string , N ) ;
	
	printf("n = %d \n STRING[%d]=%s \n",n,3,string[2]);
	return 0;
}
