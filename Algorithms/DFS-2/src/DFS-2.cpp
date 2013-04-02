//============================================================================
// Name        : DFS-2.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share,copy and distribute
// Description : Depth First Search
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#define FOR(i,N) for(i = 0 ; i < N; i++)
#define tr(C,it)\
	for(typeof((C).begin()) it = (C).begin(); it != (C).end();it++)
#define all(C) (C).begin(),(C).end()



typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<int>::iterator vit;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<pii>::iterator vpiitr;
typedef vector<vpii> vvpii;
typedef vector<vvpii >::iterator vvpiitr;

int N; 					//Number of Nodes

void DFS(){

}



void initGraph(){
	//Linked list like structure for graph
	//For each vertex , there will be adjacent vertices and edge cost
	vvpii G;
	G.resize(N+1);

	//Node 1
	vpii vp(3);
	vp[0].first = 2;       //1st adjacent node
	vp[0].second = 10;	   //cost of edge(1,2)

	vp[1].first = 3;		//2nd adjacent node
	vp[1].second = 20;		//cost of edge(1,3)

	vp[2].first = 5;		//3rd adjacent node
	vp[2].second = 30;		//cost of edge (1,5)

	G.push_back(vp);

	//Node 2
	vp.resize(2);
	vp[0].first = 4;       //1st adjacent node
	vp[0].second = 20;	   //cost of edge(1,2)

	vp[1].first = 3;		//2nd adjacent node
	vp[1].second = 30;		//cost of edge(1,3)

	//Node 3
	vp[0].first = 5;
	vp[0].first = 4;

	//



}

int main() {
	cout << "DFS" << endl; // prints DFS
	return 0;
}
