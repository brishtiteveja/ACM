//============================================================================
// Name        : Google-2.cpp
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



using namespace std;

#define tr(C,it)\
	for( typeof((C).begin()) it = (C).begin(); it != (C).end() ; it++)
#define all(C) (C).begin(),(C).end()
#define present(C,x) find(all((C)),x) != (C).end()

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<string,string>  ss;
typedef vector<ss> vss;



int main() {
	ifstream iff("/Users/zehadyzbdullahkhan/Desktop/input-task-2.txt");
	ofstream off("/Users/zehadyzbdullahkhan/Desktop/output-task-2.txt");

	if(iff.is_open()){
		int C;
		iff >> C;
		for(int i = 0;i < C;i++){
			int K,J;
			iff >> K >> J;

			vss P;
			ss p;

			string s;
			getline(iff,s);
			for(int k = 0 ; k < K ;k++){
				getline(iff,s);
				p.first = s.substr(0,1);
				p.second = s.substr(12);
				P.push_back(p);
				cout << P[k].first << " " << P[k].second << " " << endl;
			}
			cout << endl;

			vs delay(J);
			for(int j = 0; j < J;j++){
				iff >> delay[j];
			}

		}
	}

	return 0;
}
