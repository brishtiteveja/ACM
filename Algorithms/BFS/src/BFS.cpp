//============================================================================
// Name        : BFS.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share,copy and distribute
// Description : BFS
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>


using namespace std;

#define tr(C,it)\
	for( typeof((C).begin()) it = (C).begin(); it != (C).end() ; it++)
#define all(C) (C).begin(),(C).end()
#define present(C,x) find(all((C)),x) != (C).end()


typedef vector<int> vi;
typedef vector<vector<int> > vvi;


int N;						//Number of vertices

bool connectedGraphBFS(vvi& G){
		queue<int> Q;
		vi V(N,false);		//vector of visited vertices

		int sv = 0;  		//start vertex
		V[sv] = true;
		Q.push(sv);			//push start vertex

		while(!Q.empty()){
			int i = Q.front();    //get the old item
			Q.pop();			  //decrease queue size

			V[i] = true;		 //make i visited

			vvi::iterator it;

			tr(G[i],it){
				if(V[*it] == false){
					V[*it] = true;
					Q.push(*it);
				}
			}
		}

		return !(present(V,0)) ;
}


//int graph[][] = { {2,3,4},
//				  {3,4,},
//				  {4,5},
//				  {1,2,3},
//				  {2,3}
//};

void init(vvi& G){
		//pushing data
		//.....
		//Node 1
			vi vp1(3);
			vp1[0] = 2;       //1st adjacent node
			vp1[1] = 3;		//2nd adjacent node
			vp1[2] = 4;		//3rd adjacent node

			G.push_back(vp1);

			//Node 2
			vi vp2(2);
			vp2[0] = 3;       //1st adjacent node
			vp2[1] = 4;		//2nd adjacent node

			G.push_back(vp2);

			//Node 3
			vi vp3(2);
			vp3[0] = 4;
			vp3[1] = 5;

			G.push_back(vp3);
			//Node 4

			vi vp4(3);
			vp4[0] = 1;
			vp4[1] = 2;
			vp4[2] = 3;

			G.push_back(vp4);
			//Node 5
			vi vp5(2);
			vp5[0] = 2;
			vp5[1] = 3;
			G.push_back(vp5);
}


int main(){
	N = 5;
	vvi G;						// List of adjacent vertex
	init(G);
	cout << G.size() << endl;

	vvi::iterator it1;
	vi::iterator it2;

	tr(G,it1){
		tr(*it1,it2){
			cout << *it2 << " ";
		}
		cout << endl;
	}

	if(connectedGraphBFS(G)){
		cout << "connected" << endl;
	}else {
		cout << "not connected" << endl;
	}

	return 0;
}
