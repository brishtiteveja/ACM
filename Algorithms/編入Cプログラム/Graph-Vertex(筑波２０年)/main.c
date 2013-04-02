#include <stdio.h>
#include <stdlib.h>


int **a , N ;

int maxrank() { // 最も多くの矢印が向けられている頂点を探し、その頂点に向けられている矢印の数を返す関数
	int i , j , rank , max = 0 ;
	
	for ( i = 0 ; i < N ; i++ ) {
		rank = 0 ;
		
		for ( j = 0 ; j < N ; j++ ) {
			
			if ( a[j][i] ) {
				rank ++ ;
			}
		}
		
		if (rank > max) {
			max = rank ;
		}
	}
	
	return max ;
}

int reachable ( int start ,int goal ) {
 
	int i , j ,visited[N] , checked[N] ;
	
	for ( i = 0 ; i < N ; i++ ) {
		visited[i] = 0 ;
		checked[i] = 0;
		
	}
	
	i = start ;
	
	while (1) {
		if (i == goal ) {
			return 1 ;
		}
		
		visited[ i ] = 1 ;
		
		printf("visited vertex : %d \n " , i);
		for ( j = 0 ; j < N ; j++ ) {
			if (a[i][j]) {
				checked[j] = 1 ;
				
				printf("checked vertex : %d  \n", j );
			}
		}
		
		for ( j = 0; j < N ; j++ ) {
			if (!visited[j] && checked[j]) {
				i = j ;
				
				printf(" going to visit next -> vertex %d \n", i );
				break ;
			}
		}
		
		if ( j == N && i != goal ) {
			return 0 ;
		}
	}

}


int main () {
    // insert code here...
	int  i , j , k ;
	
	int start = 0 ;
	int goal = 3 ;
	
	printf("Number of the vertex \n");
	scanf("%d",&N);
	printf("Create the adjoint matrix.. \n");
	
	a = ( int** )malloc( sizeof( int* ) * N );
	
	for ( k = 0 ; k < N ; k++ ) {
		*(a+k) = ( int* ) malloc (sizeof(int) * N );
	}
	
	for (i = 0 ; i < N; i++ ) {
		for (j = 0 ; j<N ; j++) {
			scanf( "%d" , &a[i][j] );
		}
	}
	
	printf("maxrank = %d \n " , maxrank());
	
	if ( reachable( start , goal )) {
		printf("vertex no %d is reachable from vertex no %d \n" ,goal , start);
	}
	else {
		printf("vertex no %d is not reachable from vertex no %d \n " ,goal ,start);
	}

	
	
    return 0;
}
