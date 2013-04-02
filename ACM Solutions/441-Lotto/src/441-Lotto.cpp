//============================================================================
// Name        : 441-Lotto.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : Complete Search
//============================================================================

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP(i,s,e) for(int i = int(s);i <= int(e);i++)
#define REPI(i,e) REP(i,0,e)


int S[13];

void quickSort(int a[],int l,int r){
	int i = l;
	int j = r;
	int pv = a[(l+r)/2]; 				// pivot value of the array

	while(i <= j){
		while(a[i] < pv){
			i++;
		}
		while(a[j] > pv){
			j--;
		}
		if(i <= j){
			swap(a[i++],a[j--]);
		}
	}

	if(j > l)
		quickSort(a,l,j);
	if(i < r)
		quickSort(a,i,r);
}

int main() {
	int i,k;

	for(i = 1 ; scanf("%d",&k) && k ;i++ ){
		REP(j,1,k){
			S[j] = 0;
		}
		REP(j,1,k){
			scanf("%d",&S[j]);
		}
		sort(S,S+k);

		if(i != 1)
			cout << endl;
		REP(p,1,k){
			REP(q,1,k){
			  if(q > p)
				REP(r,3,k){
				  if (r > p && r > q)
					REP(s,4,k){
					  if(s > p && s > q && s > r)
						REP(t,5,k){
						  if(t > p && t > q && t > r && t > s)
							REP(u,6,k){
							  if(u > p && u > q && u > r && u > s && u > t){
								cout << S[p] << " " << S[q] << " " << S[r] << " " << S[s] << " " << S[t] << " " << S[u] << endl;
							  }
							}
						}
					}
				}
			}
		}

	}

	return 0;
}
