//============================================================================
// Name        : 11495-Bubbles.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
#define REP(i,s,e) for(int i = int(s) ; i <= int(e) ; i++)
#define tr(C,it)\
	for(typeof((C).begin()) it = (C).begin(); it != (C).end(); it++)
#define all(C) (C).begin(),(C).end()
#define pb push_back

typedef vector<int> vi;

vi v;
int N;					//number of elements in each step
int cnt = 0; 			//swap count

void merge(int l,int c,int r){
	int bs = c - l + 1 ; //buffer size;
	int buf[bs];

	int k = l;			//start storing into the buffer from the left
	REP(i,0,bs-1){
		buf[i] = v[k++];
	}

	k = l;			//resetting left
	int i,j;
	for(i = 0,j = c+1 ; i < bs && j <= r ;){
		if(v[j] < buf[i]){
			v[k++] = v[j++];
			cnt++;
		}else{
			v[k++] = buf[i++];
		}
	}

	while(i < bs){
		v[k++] = buf[i++];
	}
	while(j <= r){
		v[k++] = v[j++];
	}
}

void mergeSort(int l,int r){
	if(l < r){
		int c = (l + r) / 2;

		//partition
		mergeSort(l,c);
		mergeSort(c+1 , r);

		//merge
		merge(l,c,r);
	}
}


void kindOfBucketSort(){
	int aux;

	for(int i = 1; i < v.size();){
		if(v[i] != i){
			aux = v[i];
			v[i] = v[v[i]];
			v[aux] = aux;
			cnt++;
		}else{
			i++;
		}
	}

}


void bubbleSort(){
	for(int i = N - 1; i > 0 ; i--){
		for(int j = 0 ; j < i;j++){
			if(v[j] > v[j + 1]){
				swap(v[j],v[j+1]);
				cnt++;
			}
		}
	}
}

int main() {
	string l;		//line
	while(getline(cin,l) && l[0] != '0'){
		stringstream s(l);


		s >> N;
		v.pb(0);
		int p;
		while(s >> p){
			v.pb(p);
		}

		kindOfBucketSort();

		if(cnt % 2 == 0){
			cout << "Carlos" << endl;
		}else{
			cout << "Marcelo" << endl;
		}
		v.clear();
		cnt = 0;
	}
	return 0;
}
