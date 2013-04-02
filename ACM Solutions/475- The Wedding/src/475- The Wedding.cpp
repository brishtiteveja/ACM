//============================================================================
// Name        : 475-.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>

using namespace std;

#define NN 20
#define FORI(a,b,c) for(int a = b ; a < c; ++a)
#define FOR(a,b) FORI(a,0,b)

int ch[NN],cr[NN],ct[NN];
bool TR[NN][NN],RH[NN][NN],HT[NN][NN];


int main() {
	for(int H,R,T; scanf("%d %d %d",&T,&R,&H) == 3;){
		int cost,mincost = 0x7fffffff;
		int hidx,ridx,tidx;
		hidx = ridx = tidx = -1;
		FOR(i,T){
			scanf("%d",&ct[i]);
			FOR(j,R)
				scanf("%d",&TR[i][j]);
		}

		FOR(i,R){
			scanf("%d",&cr[i]);
			FOR(j,H)
				scanf("%d",&RH[i][j]);
		}

		FOR(i,H){
			scanf("%d",&ch[i]);
			FOR(j,T)
				scanf("%d",&HT[i][j]);
		}

		FOR(t,T){
			FOR(r,R){
				if(TR[t][r])
					continue;
				FOR(h,H){
					if(RH[r][h] || HT[h][t])
						continue;
					cost = ct[t] + cr[r] + ch[h];
					if(cost < mincost){
						mincost = cost;
						hidx = h;
						ridx = r;
						tidx = t;
					}
				}
			}
		}
		if(tidx == -1)
			cout << "Don't get married!" << endl;
		else{
			printf("%d %d %d:%d\n",tidx,ridx,hidx,mincost);
		}
	}

	return 0;
}

























