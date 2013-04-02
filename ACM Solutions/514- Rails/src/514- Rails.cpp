
///////******* Runtime Error *******////////


//============================================================================
// Name        : 514-Rails.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : Stack
//============================================================================

#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

#define REP(i,s,e) for(int i = int(s); i <= e ; i++)
#define tr(C,it,s)\
	for(typeof((C).begin()) it = (typeof((C).begin()))s ; it != (C).end();it++)
#define all(C) (C).begin(),(C).end()
#define pb push_back


typedef stack<int> stk;				//stack of integers
typedef vector<int> vi;				//vector of integers

int main() {
	int N;							//number of elements each case
	while(cin >> N && N){
		stk trackA,station,trackB;	//trackA,trackB and station as stack, once train left,can't enter

		for(;;){
			vi final(N);
			cin >> final[0];
			if(final[0] == 0){
				break;
			}
		    for(int i = 1; i < N;i++){
		    	cin >> final[i];
		    }
			REP(i,1,N){
					trackA.push(N - i + 1);			//trackA contains rail no. 1,2,..,N
			}

			unsigned int i;
			for(i = 0; !trackA.empty(); i++){
				int a = final[i];
//				cout << "a = " << a << endl;
				while(!trackA.empty() && trackA.top() != a){
					int tmp = trackA.top();
					station.push(tmp);
					trackA.pop();
					i++;
				}

				int tmp = trackA.top();
				trackA.pop();
				station.push(tmp);

				while(!station.empty()){
					int t = station.top();
					trackB.push(t);
					station.pop();
				}

			}

			if(trackA.empty() && trackB.size() != final.size()){
				cout << "No" << endl;
				continue;
			}

			i = N - 1;

			while(!trackB.empty()){
				int tmp = trackB.top();
				trackB.pop();
				if(tmp != final[i])
					break;
				i--;

			}
			if(trackB.empty()){
				cout << "Yes" << endl;
			}else{
				cout << "No" << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
