/************** Wrong answer **********************/

//============================================================================

// Name        : 11308-Bankrupt Baker.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : map,vector
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(i,s,e) for(int i = int(s); i <= int(e) ; i++)
#define tr(C,it)\
	for(typeof((C).begin()) it = (C).begin(); it != (C).end() ; it++)
#define all(C) (C).begin(),(C).end()
#define pb push_back

typedef map<string,unsigned long int> msi; 		//ingredients
typedef pair<unsigned long int,string> is;
typedef vector<is> vis;

class compare{
public:
	bool operator()(const is& p1,const is& p2){
		if(p1.first < p2.first){
			return true;
		}
		if(p1.first > p2.first){
			return false;
		}
		return p1.second < p2.second;
	}
};

int main() {
	int binder;
	cin >> binder;
	string s;
	getline(cin,s); //newline

	REP(i,1,binder){
		getline(cin,s) ; //name of the binder

		cout << s << endl; //print the name of the binder

		int m,n;
		unsigned long int b;
		cin >> m >> n>> b;

		msi ingr;
		REP(j,1,m){
			cin >> s;
			cin >> ingr[s];
		}
		getline(cin,s);
		vector<is> recipes;
		REP(l,0,n-1){
			string name; 		//name of the recipe
			getline(cin,name);
			int k;
			cin >> k;
			getline(cin,s); 		//newline
			unsigned long int total = 0;
			int unit;
			REP(p,1,k){
				cin >> s >> unit;
				total += (unit * ingr[s]);
			}
			getline(cin,s);	//newline
			if(total <= b)
				recipes.pb(is(total,name));
		}

		if(recipes.empty()){
			cout << "Too expensive!" << endl;
		}else{
			sort(all(recipes),compare());
			tr(recipes,it){
				cout << it->second << endl;
			}
		}

		if(i != binder)
			cout << endl;
	}
	return 0;
}
