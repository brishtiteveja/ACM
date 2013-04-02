//============================================================================
// Name        : 11462-Age Sort.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : Sort,Merge Sort
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,s,e)\
	for(int i = int(s); i <= int(e); i++)

typedef vector<int> vi;
vi A;
int n;


void merge(int l,int c,int r){
	int bs = c - l + 1;
	int buf[bs];		//buffer for left partition

	int k = l;			//start from left
	REP(i,0,bs-1){
		buf[i] = A[k++];
	}

	int i,j;
	k = l; 		//start from left again
	for(i = 0,j = c + 1; i < bs && j <= r;){
		if(A[j] < buf[i]){
			A[k++] = A[j++];
		}else{
			A[k++] = buf[i++];
		}
	}

	while(i < bs){
		A[k++] = buf[i++];
	}

	while(j <= r){
		A[k++] = A[j++];
	}
}

void mergeSort(int left,int right){
	if(left < right){
		int center = (left + right) / 2.0;
		//partition step
		mergeSort(left,center);
		mergeSort(center+1,right);

		//merge step
		merge(left,center,right);
	}
}

int main() {

	while(cin >> n && n){
		A = vi(n);
		REP(i,0,n-1){
			cin >> A[i];
		}
		mergeSort(0,n-1);
		REP(i,0,n-1){
			cout << A[i];
			if (i < n-1)
				cout << " ";
		}
		cout << endl;
		A.clear();
	}



	return 0;
}
