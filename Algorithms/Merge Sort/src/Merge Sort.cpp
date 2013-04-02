//============================================================================
// Name        : Merge.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share,copy and distribute
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define FOR(i,n) for(i = 0; i < N; i++)
#define space " "
using namespace std;

//merging two partition
void merge(int *a,int left, int right,int center){
	int *buffer; // buffer for left partition
	int bs = center - left + 1; // buffer size
	buffer = new int[bs];

	int i,b;
	//storing left partition inside the buffer so that we can overwrite the left partition
	for(b=0,i = left;b < bs;){
		buffer[b++] = a[i++];
	}

	//comparing the right partition with the buffer and sorting
	int k = left; //index of the two partition
	for(b=0,i=center+1; b<bs && i<=right; ){  // b: index of the left partition i: index of the right partition
		if(a[i] < buffer[b]){
			a[k++] = a[i++];
		}else{
			a[k++] = buffer[b++];
		}
	}

	//rest of the elements from the left partition
	for(;b < bs;){
		a[k++] = buffer[b++];
	}

	//rest of the elements from the right partition
	for(;i <= right;){
		a[k++] = a[i++];
	}
}

//merge Sort
void mergeSort(int *a,int left,int right){
	if(left < right){
		int center = (left + right) /2 ;

		//partition step
		mergeSort(a,left,center);
		mergeSort(a,center+1,right);

		//merge Sort
		merge(a,left,right,center);
	}
}

int main(){
	int N;
	cin >> N;
	int a[N];
	int i;
	FOR(i,N){
		cin >> a[i];
	}

	//merge sort call
	mergeSort(a,0,N-1);

	FOR(i,N){
		cout << a[i] << space;
	}

	return 0;
}


//
//
//void merge(int *a,int l,int c,int r)
//{
//	int bs = (c-l) + 1;
//	int buffer[bs];
//
//	int b = 0,i = l;
//	for(;b < bs;)
//		buffer[b++] = a[i++];
//
//	int k = l;
//	b = 0;i = c + 1;
//	for(;b < bs && i <= r;){
//		if(a[i] > buffer[b]){
//			a[k++] = a[i++];
//		}else{
//			a[k++] = buffer[b++];
//		}
//	}
//
//	while(b < bs)
//		a[k++] = buffer[b++];
//	while(i <= r)
//		a[k++] = a[i++];
//}
//
//void mergeSort(int *a,int l,int r){
//	if(l < r){
//		int c = (l+r) / 2;
//
//		//partition step
//		mergeSort(a,l,c);
//		mergeSort(a,c+1,r);
//
//		//merge step
//		merge(a,l,c,r);
//	}
//}
//
