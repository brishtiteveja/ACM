//============================================================================
// Name        : 10261-Ferry Loading.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : DP,Backtrack
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <algorithm>


using namespace std;

#define REP(i,s,e) for(int i = int(s); i <= int(e) ; i++)
#define tr(C,it)\
	for(typeof((C).begin()) it = (C).begin();it != (C).end();it++)
#define Rtr(C,it)\
	for(typeof((C).rbegin()) it = (C).rbegin();it != (C).rend();it++)
#define all(C) (C).begin(),(C).end()


typedef pair<int,int> ii;


#define MAXN 201
#define MAXL 100001


int cars[MAXN + 1];			//length of cars
int sumLength[MAXN + 1] ; 	//sumLenghth[i] = total length of cars from car[0] to car[i]
int choice[MAXN + 1][MAXL + 1];
bool memo[MAXN + 1][MAXL + 1];

void DP_solve(){
	int c;
	cin >> c;

	string s;
	getline(cin,s);	//newline
	getline(cin,s); //newline

	REP(i,0,c-1){
		int flen;	//length of the ferry
		cin >> flen;
		flen *= 100;

		int len;

		sumLength[0] = 0;
		int nCar = 1;				//number of Cars
		while(cin >> len && len){
			if(nCar < MAXN){
				cars[nCar] = len;
				sumLength[nCar] = sumLength[nCar - 1] + len;
				nCar++;
			}
		}
		nCar--;


		memset(memo,false,sizeof(memo));
		memset(choice,-1,sizeof(choice));

		ii longest;

		memo[0][0] = true;

		for(int i = 0 ; i < nCar ; i++){	//number of cars loaded
			for(int j = 0 ; j <= flen ; j++){	//ferry length consumed
				if(memo[i][j]){
					if(j + cars[i+1] <= flen){
						memo[i+1][j + cars[i+1]] = true;
						choice[i+1][j + cars[i+1]] = 1;      //choice for starboard
						longest = ii(i+1,j + cars[i+1]);
					}

					if(sumLength[i] - j + cars[i+1] <= flen){
						memo[i+1][j] = true;
						choice[i+1][j] = 0;					//choice for port
						longest = ii(i+1,j);
					}

					//choice for port and starboard can be interchanged
				}
			}
		}

		vector<string> solution;
		cout << longest.first << endl;
		for(int i = longest.first,j = longest.second; i > 0 && choice[i][j] != -1; i--){

			if(choice[i][j]){
				solution.push_back("port\n");
				j -= cars[i];
			}else{
				solution.push_back("starboard\n");
			}
		}

		tr(solution,it){
			cout << *it;
		}

	}
}

int main() {

	DP_solve();

	return 0;
}
