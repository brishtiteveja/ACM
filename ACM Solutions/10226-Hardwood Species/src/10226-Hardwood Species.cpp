//============================================================================
// Name        : 10226-Hardwood.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share
// Description : Sort,map
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define f(n) setiosflags(ios::fixed) << setprecision(n)
#define REP(i,s,e) for(int i = int(s);i <= int(e);i++)
#define tr(C,it)\
	for(typeof((C).begin()) it = (C).begin();it != (C).end();it++)
#define all(C) (C).begin(),(C).end()
#define pb push_back


typedef pair<string,int> si;
typedef multimap<string,int> vstr;


int main() {
	int C;
	cin >> C;

	string s;
	getline(cin,s);	//newline
	getline(cin,s); //newline
	REP(i,1,C){
		vstr trees;
		string s;
		int cnt = 0;
		while(getline(cin,s)){
			if(s != ""){
				trees.insert(si(s,1));
				cnt++ ;
			}else{
				vstr::iterator it,st;
				for(it = trees.begin() ; it != trees.end();){
					st = it;
					while((++it) != trees.end() && !((*st).first.compare((*it).first))){
						(*st).second++;
						trees.insert(it,si((*st).first,(*st).second)) ;
					}
					cout << st->first << " " << f(4) << st->second/(double)cnt * 100.0 << endl;
				}
				break;
			}
		}
		if(i!= C)
			cout << endl;
	}

	return 0;
}


//int main() {
//	int C;
//	cin >> C;
//
//	string s;
//	getline(cin,s);	//newline
//	getline(cin,s); //newline
//	REP(i,1,C){
//		vstr trees;
//		msi m;
//		string s;
//		int cnt = 0;
//		while(getline(cin,s)){
//			if(s != ""){
//				//cout << s << endl;
//				trees.pb(s);
//				cnt++ ;
//			}else{
//				sort(all(trees));
//				vstr::iterator it,tmp,start;
//				cout << trees.size()<< endl;
//				for(it = trees.begin() ; it != trees.end();it++){
//					m[*it] = 1;												//initial value of a species
//					start = it;
//					while((it + 1) != trees.end() && !(*(it + 1)).compare(*it)){
//						it++;
//						m[*start] ++;
//					}
//				}
//				tr(m,it){
//					cout << it->first << " " << f(4) << it->second/(double)cnt * 100.0 << endl;
//				}
//				if(i != C)
//					cout << endl;
//				break;
//			}
//		}
//	}
//
//	return 0;
//}
