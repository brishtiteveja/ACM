//============================================================================
// Name        : 385-Graph Coloring.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : Recursive backtracking
//============================================================================
//
#include <iostream>
#include <cstdio>
using namespace std;

#define FOR(i,s,e) for(int i = int(s);i < int(e);i++)
#define FORI(i,e) FOR(i,0,e)
#define NN 128

int adj[NN][NN],deg[NN],c[NN],s[NN],canbe[NN];
int n;										//number of nodes
int maxblack;								//maximum number of black nodes

void bt(int k,int cnt){
	if(k == n){								//the last node
		if(cnt > maxblack){
			maxblack = cnt;
			FORI(i,n)
				s[i] = c[i];				//saving the marked black node
		}
		return;
	}

	if(n-k + cnt <= maxblack){				//even if adding all the not-yet operated node gives no better solution
		return;
	}

	if(canbe[k]){							//yet a candidate to become a black node
		c[k] = 1;							//marking the k th node black

		int saved[NN];
		FORI(i,deg[k]){
			int x = adj[k][i];				//index of the adjacent nodes
			saved[x] = canbe[x];
			canbe[x] = 0;
		}

		bt(k+1,cnt+1);						//recursively backtracking the next node

											//resetting the adjacent nodes' candidacy
		FORI(i,deg[k]){
			int x = adj[k][i];				//index of the adjacent nodes
			canbe[x] = saved[x];
		}
	}

	c[k] = 0;			//k can't be a black node
	bt(k+1,cnt);
}

int main() {
	int t; 									//test case
	scanf("%d",&t);

	while(t--){
		int k;
		scanf("%d %d",&n,&k);

		FORI(i,n){							//initialization
			deg[i] = 0;				//degree of all vertices are zero
			canbe[i] = 1;					//each vertex can be considered as a candidate
		}

		int a,b;
		FORI(i,k){
			scanf("%d %d",&a,&b);
			a--;
			b--;
			adj[a][deg[a]] = b;
			deg[a]++;											//degree of vertex[a-1] increased
			adj[b][deg[b]] = a;
			deg[b]++;											//degree of vertex[b-1] increased
		}

		int cnt = 0;
		maxblack = 0;						//counter and initial value of maximum black node

											//recursive backtracking started
		bt(0,0);

		printf("%d\n",maxblack);			//printing the maximum number of black nodes

		FORI(i,n){
			if(s[i] && cnt) 				//printing space after every black node except the first one
				printf(" ");
			if(s[i]){
				printf("%d",i + 1);
				cnt++;
			}
		}
		printf("\n");

	}

	return 0;
}
