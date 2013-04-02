//============================================================================
// Name        : 146-ID Codes.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : ACM problems,
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define tr(C,it)\
	for(typeof(C.begin()) it = C.begin(); it != C.end();it++)
#define all(C) C.begin(),C.end()
#define pb push_back

typedef vector<char> vc;

int main() {
	string s;
	while(cin >> s && s[0] != '#') {
		string st(s);

		bool f = false;
		while(next_permutation(all(s))){
			f = true;
			tr(s,it)
				cout << *it;
			cout << endl;
			break;
		}
		if(!f)
			cout << "No Successor" << endl;
	}
	return 0;
}
