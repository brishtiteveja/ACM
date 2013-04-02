//============================================================================
// Name        : 639-Don't Get Rooked.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>

using namespace std;

#define REP(i,s,e) for(int i = int(s);i <= int(e);i++)
#define REPI(i,e) REP(i,0,e)

char a[4][4];
bool ok[4][4];
bool r[4];
bool c[4];

void resetBoard(int n){
	REPI(i,n-1)
		r[i] = c[i] = 0;

	REPI(j,n-1){
		REPI(i,n-1){
			if(a[i][j] == 'X')
				ok[i][j] = 0;
			else
				ok[i][j] = 1;
			}
	}
}

int countBoard(int n){
	int c = 0;
	REPI(j,n-1){
		REPI(i,n-1){
			if(ok[i][j])
				c++;
		}
	}
	return c;
}

void showOk(int n){
	REPI(j,n-1){
		REPI(i,n-1){
			cout << ok[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

int main() {
	int n;
	for(; scanf("%d\n",&n) && n;){

		REPI(i,n-1)
			r[i] = c[i] = 0;

		REPI(j,n-1){
			REPI(i,n-1){
				scanf("%c",&a[i][j]);
				if(a[i][j] == 'X')
					ok[i][j] = 0;
				else
					ok[i][j] = 1;
			}
			char c;
			scanf("%c",&c);
		}




	  int cnt;
	  int ans = -1;

	  REP(s,0,n-1){
	     REP(t,0,n-1){
	       if(ok[s][t]){
	    	  cnt = 0;
	    	  resetBoard(n);
	    	  REP(j,s,n-1){
	    		  REP(i,t,n-1){
	    			  if(ok[i][j]){
	    				  REP(p,i+1,n-1){
	    					  if(a[p][j] != 'X'){
	    						  ok[p][j] = 0;
	    					  }else{
	    						  break;
	    					  }
	    				  }
	    				  for(int p = i-1;p >= 0;p--){
	    				  	   if(a[p][j] != 'X'){
	    				  	    	ok[p][j] = 0;
	    				  	   }else{
	    				  	    	break;
	    				  	   }
	    				  }
	    				  REP(q,j+1,n-1){
	    					  if(a[i][q] != 'X'){
	    						  ok[i][q] = 0;
	    					  }else{
	    						  break;
	    					  }
	    				  }
	    				  for(int q = i-1;q >= 0;q--){
	    				  	  if(a[i][q] != 'X'){
	    				  		  ok[i][q] = 0;
	    				  	  }else{
	    				  	      break;
	    				  	  }
	    				  }
	    				  cout << "i = " << i << "j = " << j << endl;
	    				  showOk(n);
	    			  }
	    		  }
	    	  }
	    	  cout << "s = " << s << "t = " << t << endl;
	    	  showOk(n);
	    	  cnt = countBoard(n);
	    	  cout << "c = " << cnt << endl;
	    	  if(cnt > ans){
	    	  	    ans = cnt;
	    	  }
	       }

	     }
	  }

	  cout << ans << endl;
	}

	return 0;
}

