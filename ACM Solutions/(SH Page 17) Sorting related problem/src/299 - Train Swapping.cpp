//============================================================================
// Name        : 299.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define FOR(i,n) for(i=0;i<n;i++)
#define R_FOR(i,n) for(i=n-1;i>=0;i--)

void swap(int &x,int &y){
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

int main() {
	int i,j,k,l,N,M;
	int res = 0;

	cin >> N;

	FOR(i,N){
		cin >> M;
		int a[M];
		FOR(j,M){
			cin >> a[j];
		}
		R_FOR(k,M)
			FOR(l,k){
				if(a[l] > a[l+1]){
					swap(a[l],a[l+1]);
					res++;
				}
			}
		cout << "Optimal train swapping takes "<< res << " swaps." << endl;
		res = 0;

	}
	return 0;
}
