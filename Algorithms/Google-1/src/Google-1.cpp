//============================================================================
// Name        : Google-1.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share,copy and distribute
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>


using namespace std;

#define tr(C,it)\
	for( typeof((C).begin()) it = (C).begin(); it != (C).end() ; it++)
#define all(C) (C).begin(),(C).end()
#define present(C,x) find(all((C)),x) != (C).end()


typedef vector<int> vi;
typedef pair<string,int> si;
typedef vector<si> vsi;

//struct classcomp {
//  bool operator() (const char& lhs, const char& rhs) const
//  {return lhs>rhs;}
//};

class compareClassLess{
public:
	bool operator()(const si& e1,const si& e2){
		if(e1.first < e2.first){
			return true;
		}
		if(e1.first > e2.first){
			return false;
		}
		return e1.second < e2.second;

	}
};

class compareClassBig{
public:
	bool operator()(const si& e1,const si& e2){
		if(e1.first < e2.first){
			return true;
		}
		if(e1.first > e2.first){
			return false;
		}
		return e1.second > e2.second;

	}
};


int main() {
	ifstream iff("/Users/zehadyzbdullahkhan/Desktop/input-task-1.txt");
	ofstream off("/Users/zehadyzbdullahkhan/Desktop/output-task-1.txt");

	if(iff.is_open()){
		int c;  			//number of cases

		iff >> c;

		for(int k = 0;k < c;k++){
			off << "Case #" << k+1<< ":" << endl;
//			cout << "Case #" << k+1<< ":" << endl;
			int l;			//line number
			iff >> l;
			vsi P(l);				//all pair vectors
			for(int i = 0;i < l;i++){
				string s;
				int n;
				iff >> s >> n;
				P[i].first = s;
				P[i].second = n;
			}

			//sorting all pairs
			sort(all(P),compareClassLess());

			map<string,int> mSmall(all(P));				//map with lowest value

			vsi Q(all(P));
			sort(all(Q),compareClassBig());

			map<string,int> mBig(all(Q));				//map with highest value



			int ms = mBig.size();						//item number = map size
			vi avg(ms,0);								//average vector
			vi cnt(ms,0);								//how many same thing?

			vsi::iterator it = P.begin();
//			tr(P,it){
//				cout << it->first << " " << it->second << endl;
//			}

			string s = it ->first;
			int i = 0;
			avg[i] = it ->second;
			cnt[i]++;
			for(it = P.begin() + 1 ;it != P.end(); it++ ){
//					cout << it ->first << " " << it -> second << endl;
					if(it->first == s){
						avg[i] += it->second;
						cnt[i] ++;
//						cout << avg[i] << " " << cnt[i] << endl;
					}
					else{
						avg[i] = round(avg[i] / cnt[i]);
						i++;

						//for next element
						s = it->first;
						avg[i] = it->second;
						cnt[i] ++;
//						cout << endl<< s << " " << avg[i] << " " << cnt[i] << endl;
					}
			}
			avg[i] = round(avg[i] / cnt[i]);

			map<string,int>::iterator it1,it2;
			vi::iterator it3,it4;
			for(it1 = mSmall.begin(),it2 = mBig.begin(),it3 = avg.begin(),it4 = cnt.begin(); it1 != mSmall.end();it1++,it2++,it3++,it4++){
				off << it1->first << " "<<it1->second << " " << it2->second << " " << *it3 << " count =" << *it4 << endl;
			}
		}
	}


	return 0;
}


//
//3
//3
//banana 90
//apple 100
//apple 260
//5
//grapefruit 120
//grape 200
//grapefruit 150
//grapefruit 150
//grape 180
//2
//apple 100
//apple 101

////output
//Case #1:
//apple 100 260 180
//banana 90 90 90
//Case #2:
//grape 180 200 190
//grapefruit 120 150 140
//Case #3:
//apple 100 101 100
