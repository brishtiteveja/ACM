//============================================================================
// Name        : Djkstra.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share,copy and distribute
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define FOR(i,N) for(i = 0 ; i < N; i++)
#define tr(C,it)\
	for(typeof((C).begin()) it = (C).begin();it != (C).end(); it++)
#define all(C) (C).begin(),(C).end()

#define MAX 1e9
#define MIN 0

//typedef vector<int> vi;
//typedef vector<vi > vvi;
//typedef pair<int,int> ii;
//typedef vector<ii> vii;
//typedef vector<vii> vvii;
//
//vvii G; 		//Graph
//int n;			//Number of Nodes
//vi D(n,MAX);	//Distance from source to vertex n
//
//
//void Djkstra(int s){
//	set<ii> Q;				//Queue using set ( set is always sorted ,default:ascending order)
//	Q.insert(ii(0,s));		//inserting the source vertex and its cost
//							//cost in the first element so that set can sort it automatically
//	D[s] = 0;				//source to source distance = 0
//
//	while(!Q.empty()){
//		ii p = *Q.begin();	//the least distance element of the set
//		Q.erase(p);
//		int d = p.first;
//		int u = p.second;
//
//		vi::const_iterator  it;
//		tr(G[u],it){
//			int v = it->first;
//			int cost = it ->second;
//
//			if(D[v] > D[u] + cost  ){
//					D[u] = D[u] + cost;
//			}
//			Q.insert(ii(u,D[u]));
//		}
//	}
//
//}

#define INF 1e9
#define MIN 0

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii G;
int n;
vi D(n,INF);  						//initialize the distance vector with infinity


void Djkstra(int s){
	set<ii> Q;						//Queue using set ( set is always sorted ,default:ascending order)
	Q.insert(ii(0,s));           	//inserting the source vertex and its cost
									//cost in the first element so that set can sort it automatically
	D[s] = 0;						//source to source distance = 0

	while(!Q.empty()){
		ii top = *Q.begin();		//the least distance element of the set
		Q.erase(Q.begin());			//removing it from Q
		int u = top.second;
		int d = top.first;

		vi::const_iterator it;
		tr(G[u],it){
			int v = it ->second;
			int cost = it ->first;

			if(D[v] > D[u] + cost){
				if(D[v] != INF){
					Q.erase(Q.find(ii(D[v],v)));		//erasing the vertices which are already updated
				}
				D[v] = D[u] + cost;
				Q.insert(ii(D[v],v));
			}

		}
	}
}


int main() {

	return 0;
}
