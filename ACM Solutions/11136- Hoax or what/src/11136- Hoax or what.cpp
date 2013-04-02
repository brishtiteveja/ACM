/************** Wrong answer **********************/
//============================================================================
// Name        : 11136-Hoax or WHat.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : multiset
//============================================================================

#include <iostream>
#include <set>
using namespace std;

typedef unsigned int ui;

#define REP(i,s,e) for(int i = int(s) ; i <= int(e);i++)
#define tr(C,it)\
	for(typeof((C).begin()) it =(C).begin(); it != (C).end() ; it++)
#define pb push_back

typedef multiset<unsigned long int> mulli;
typedef unsigned long int uli;

int main() {
	mulli urn;
	int d;
	while(cin >> d && d){				//number of days
		uli total = 0;
		REP(i,0,d-1){
			uli k;				//number of bill
			cin >> k;
//			cout << "k = " << k << endl;
			REP(j,0,k-1){
				uli b;
				cin >> b;
//				cout << b << endl;
				urn.insert(b);
			}
//			cout << "size = " << urn.size() << endl;
			if(urn.size() >= 2)
			{
				uli min = *urn.begin();
				uli max = *urn.rbegin();
				total += (max - min);
				urn.erase(urn.begin());
				mulli::iterator t;
				t = urn.end();
				t--;
				urn.erase(t);
			}
//			cout << "total = " << total << endl;
		}
		cout << total << endl;
	}

	return 0;
}
