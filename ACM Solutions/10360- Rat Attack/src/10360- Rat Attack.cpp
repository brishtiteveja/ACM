//============================================================================
// Name        : 10360-Rat Attack.cpp
// Author      : Ajmarin
// Version     : 1
// Copyright   : Free to share
// Description : DP
//============================================================================

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define REPI(i,s,e) for(int i = s; i < e;i++)
#define REP(i,e) REPI(i,0,e)
#define N 1048

int c[N][N];
int r[N][N];
int m[N][N];
int maxx,maxy;

int main() {
	int t; // number of test cases
	int d; // gas bomb strength
	int n; // total rat populations
	int ians,jans,maxsum;
	int x,y,s; // rat population coordinate and size

	for(scanf("%d",&t); t-- && scanf("%d %d",&d,&n);){
		maxsum = maxx = maxy = 0;
		REP(i,N){
			REP(j,N){
				c[i][j] = r[i][j] = m[i][j] = 0;
			}
		}

		REP(i,n){
			scanf("%d %d %d",&x,&y,&s);
			m[++x][++y] = s;
			c[y][x] = r[x][y] = s;
			if(x > maxx)
				maxx = x;
			if(y > maxy)
				maxy = y;
		}
		maxx++;
		maxy++;

		REPI(i,1,maxx){
			REPI(j,1,maxy){
				m[i][j] += m[i-1][j-1] + r[i][j-1] + c[j][i-1];
				r[i][j] += r[i][j-1];
				c[j][i] += c[j][i-1];
			}
		}

		REPI(i,1,maxx){
			REPI(j,1,maxy){
				int x1 = max(i-d,1);
				int y1 = max(j-d,1);
				int x2 = min(maxx-1,i+d);
				int y2 = min(maxy-1,j+d);

				int sum = m[x2][y2] - m[x1-1][y2] \
						- m[x2][y1-1] + m[x1-1][y1-1];
				if(sum > maxsum){
					maxsum = sum;
					ians = i;
					jans = j;
				}
			}
		}

		printf("%d %d %d\n", ians - 1, jans - 1, maxsum);
	}

	return 0;
}





