//============================================================================
// Name        : Quick.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share,copy and distribute
// Description : Quick Sort
//============================================================================

#include <iostream>
using namespace std;


void quickSort(int *a,int l,int r){
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
	int a[10] = {1,10,9,8,7,6,5,4,3,2};
	for(int i = 0; i < 10 ; i++)
			cout << a[i] << " ";
	cout << endl;

	quickSort(a,2,9);

	for(int i = 0; i < 10 ; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}
