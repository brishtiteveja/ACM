//============================================================================
// Name        : 10810-Ultra Quicksort.cpp
// Author      : Ajmarin,Dhrubo Abdullah Khan
// Version     : 2
// Copyright   : Free to share
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define FORI(i,s,e) for(int i = int(s);i <= int(e); i++)
#define FOR(i,e) FORI(i,0,e)



void merge(int* a,int l,int c,int r){
	int bs = c - l + 1;
	int buffer[bs];

	int b = l;
	FOR(i,bs-1){
		buffer[i] = a[b++];
	}

	int i,j,k;
	for(k=l,i=0,j=c+1; i < bs && j <= r;){
		if(a[j] < buffer[i]){
			a[k++] = a[j++];
			c++;
		}else{
			a[k++] = buffer[i++];
		}
	}

	while(i < bs){
		a[k++] = buffer[i++];
	}
	while(j <= r){
		a[k++] = a[j++];
	}
}

void mergeSort(int* a,int l,int r){
	if(l < r){
		int c = (l + r) / 2;

		//partition step
		mergeSort(a,l,c);
		mergeSort(a,c+1,r);

		//merge step
		merge(a,l,c,r);
	}
}
int quickSort(int* a,int l,int r,int c){
	int i = l;
	int j = r;
	int pv = a[(l + r) / 2];		//pivot

	while(i <= j){
		for(;a[i] < pv;i++);	//smaller elms than pv in the left of the pv
		for(;a[j] > pv;j--);	//bigger elms than pv in the right of the pv

		if(i < j){
			swap(a[i],a[j]);
			c++;
		}
		i++;
		j--;
	}

	int c1,c2;
	if(j > l)
		c1 = quickSort(a,l,j,c+1);
	if(i < r)
		c2 = quickSort(a,i,r,c+1);
	return c1 + c2;
}


int main() {
	int N;
	while(cin >> N && N){
		int a[N];
		FOR(i,N-1){
			cin >> a[i];
		}
		int k = quickSort(a,0,N-1,0);
		cout << k << endl;
		FOR(i,N-1){
							cout<<  a[i] << " ";
						}
		cout  << endl;
	}

	return 0;
}
