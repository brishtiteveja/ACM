//============================================================================
// Name        : 11239-Open Source.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


#define REP(i,s,e) for(int i = int(s); i <= int(e); i++)
#define tr(C,it)\
	for(typeof((C).begin()) it = (C).begin() ; it != (C).end() ; it++)
#define all(C) (C).begin(),(C).end()
#define pb push_back

typedef set<string> sstr;				//unique userids
typedef pair<string,sstr> pss;			//project with their userids

class compare{
public:
	bool operator()(const pss& p1,const pss& p2){
		return p1.second.size() > p2.second.size();
	}
};
typedef set<pss> vpss;		//vector of projects



int main() {
	string s;
	vpss proj;
	string projn;
	sstr st;

	int idx = -1;

	while(getline(cin,s) && s[0] != '0')
	{
		if(s[0] == '1'){
			tr(proj,it){
				cout << it -> first << endl;
				cout << "size =" << (it->second).size() << endl;
//				tr(it->second,it1){
//					cout <<" " << *it1 << endl;
//				}
			}
		}
		else if(s[0] >= 'A' && s[0] <= 'Z'){

			projn = s;
			idx++;
		}else{
//			cout << "s = " <<s << endl;
			st.insert(s);
			proj.insert(pss(projn,st));
		}
	}
	return 0;
}
