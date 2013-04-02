//============================================================================
// Name        : 10131-Is.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define tr(C,it) \
	for(typeof(C.begin()) it = C.begin(); it != C.end();it++)
#define all(C) C.begin(),C.end()
#define pb push_back


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<iii> viii;

class comp{
public:
	bool operator()(const iii& p1,const iii& p2){
		if(p1.first.first < p2.first.first)
			return true;
		if(p1.first.first > p2.first.first)
			return false;
		return p1.first.second > p2.first.second;
	}
};

bool cond(iii& p1,iii& p2){
	return (p1.first.first > p2.first.first) && (p1.first.second < p2.first.second);
}

int main() {
	viii vP;
	int ww,ss,c = 1;

	while(cin >> ww && !cin.eof() && cin >> ss){
		iii p;
		p.first.first = ww;
		p.first.second = ss;
		p.second = c++;
		vP.pb(p);
	}
	c--;

	sort(all(vP),comp());

	viii::iterator it1,it2;
//
//	tr(vP,it){
//		cout << (it ->first).first << " " << (it->first).second <<" " <<it->second <<  endl;
//	}

	int sz;
	int max = 0;					//maximum size of the subsequence
	int fidx = 0;					//final starting index of the subsequence
	int prev;
	for(int idx = 0; idx <= c; idx++){
		sz = 1;						// initially size is 1, current idx will be taken
		prev = idx;				// previous one that satisfied the condition
		for(int i = idx + 1; i <= c ;i++){
			if(cond(vP[i],vP[prev])){
				prev = i;			// update the index with which next comparison will happen
				sz++;				// increase size
			}
		}
		if(sz > max){
			max = sz;
			fidx = idx;
		}
	}

	cout << max << endl;				//size of the sequence printed
	cout << vP[fidx].second << endl;	//the starting element index

	prev = fidx;
	for(int i = fidx + 1; i <= c ;i++){
		if(cond(vP[i],vP[prev])){
			prev = i;
			cout << vP[i].second << endl;
		}
	}

	return 0;
}



