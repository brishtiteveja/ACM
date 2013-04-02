//============================================================================
// Name        : 10327-Flip.cpp
// Author      : Dhrubo Abdullah Khan
// Description : ACM UVA Online Problem 10327-Flip Sort
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

#define FOR(i,n) for(i = 0 ;i < n; i++)
#define R_FOR(i,n) for(i = n-1;i >= 0;i--)

void swap(int& x,int& y){
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

int bubbleSort(int *a, int n){
	int i,j;

	int c = 0;

	R_FOR(i,n){
		FOR(j,i){
			if(a[j] > a[j+1]){
				swap(a[j],a[j+1]);
				c++;
			}
		}
	}
	return c;
}

int main() {
	int i,n;
	while(cin >> n && n != EOF){
		int a[n],res = 0;

		FOR(i,n){
			cin >> a[i];
		}
		res = bubbleSort(a,n);
		cout << "Minimum exchange operations : " << res << endl;
	}
	return 0;
}
