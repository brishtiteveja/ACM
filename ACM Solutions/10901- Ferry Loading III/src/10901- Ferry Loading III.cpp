/************************ Wrong Answer ***************************************/

//============================================================================
// Name        : 10901-Ferry Loading III.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : Queue
//============================================================================

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,s,e) for(int i = int(s); i <= int(e) ; i++)
#define tr(C,it)\
	for(typeof((C).begin()) it = (C).begin();it != (C).end();it++)
#define all(C) (C).begin(),(C).end()
#define pb push_back
#define max(a,b) int(a) >= int(b) ? a:b
#define min(a,b) int(a) <= int(b) ? a:b

typedef pair<int,string> is;
typedef pair<int,is> iis;
typedef queue<iis> Queue;
typedef vector<int> vi;


//2
//2 10 10
//0 left
//10 left
//20 left
//30 left
//40 left
//50 left
//60 left
//70 left
//80 left
//90 left
//2 10 3
//10 right
//25 left
//40 left

int main() {
	int c;
	cin >> c;
	Queue L,R;

	REP(i,0,c-1){
		int n,t,m;
		cin >> n >> t >> m;

		REP(j,0,m-1){
			int tm;
			string side;
			cin >> tm >> side;
			if(side == "left")
				L.push(iis(j,is(tm,side)));
			else
				R.push(iis(j,is(tm,side)));
		}

		int time = 0;		//time of the ferry of being in either side
		vi tA(m);

		bool carIs = true;
		string where = "left";	//position of the ferry

		while(!L.empty() || !R.empty()){
			iis car;

			//left side
			if(!L.empty()){
				car = L.front();
				if(where == "right" && car.second.second == "left" && car.second.first <= time){//Ferry was waiting in the right,
																								  //time to come to the left from right
					time = time + t;
				}

				carIs = false;
				//take at most n cars from left
				while(car.second.second == "left" && car.second.first <= time){
					tA[car.first] = time + t;
//					cout << "time = " << time + t<< endl;
					L.pop();
					carIs = true;
					if(L.empty())
						break;
					car = L.front();
				}

				if(carIs){	//at most n cars have been taken, time to go from left side to right side
					time = time + t;
					where = "right";
				}
			}


			//right side
			if(!R.empty()){
				car = R.front();

				if(where == "left" && car.second.second == "right" && car.second.first <= time)  //time to come to the right
					time = time + t;

//				carIs = false;
				while(car.second.second == "right" && car.second.first <= time){
					tA[car.first] = time + t;
//					cout << "time = " << time +t << endl;
					R.pop();
					carIs = true;
					if(R.empty())
						break;
					car = R.front();
				}
				if(carIs){//atmost n cars have been taken from right side, time to go from right side to left side
					time = time + t;
					where = "left";
				}
			}

			if(!carIs){		//no car in either side,ferry will not cross
				time = time + t;
			}
		}
		REP(j,0,m-1)
			cout << tA[j] << endl;
		tA.clear();
		if(i+1 != c)
			cout << endl;
	}

	return 0;
}
