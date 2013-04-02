// ============================================================================
// Name        : 423- MPI Maelstotm.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : ACM Problem
// ============================================================================

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

#define INF 1e9

typedef pair<int,int> ii;

int n;													//number of nodes
int **G;												//Graph
int *D;

void dijkstra(int s){
	set<ii> Q;											//the Q
	Q.insert(ii(0,s));									//inserting the source vertex
	D[s] = 0;											//source to source distance = 0

	while(!Q.empty()){
		ii top = *Q.begin();							//popping the least distant node from the source as set is ordered
		Q.erase(Q.begin());								//erasing it
		int u = top.second;								//vertex index
		int d = top.first;
//		cout << "u = " << u << endl;
		for(int v = 0;v < n; v++){
			if(u != v && G[u][v] != INF){				//neighbor nodes of u
				int cost = G[u][v];						//cost(u,v)
//				cout << "v = " << v << "cost = " << cost << endl;
				if(D[v] > D[u] + cost){					//relaxation step
//					cout << D[v] << endl;
					if(D[v] != INF){
						Q.erase(Q.find(ii(D[v],v)));
					}
					D[v] = D[u] + cost;
					Q.insert(ii(D[v],v));
				}
			}
		}
	}
}

int main() {
	cin >> n;

	G = new int* [n];
	D = new int [n];
	for(int i = 0 ; i < n; i++){
		G[i] = new int [n];
		D[i] = INF;									//initializing distance vector
	}

	G[0][0] = 0;
	for(int i = 1;i < n ;i++){
		G[i][i] = 0;
		for(int j = 0;j < i ;j++){
			string s;
			cin >> s;
			if(s[0] != 'x'){
				char cv[15];
				sprintf(cv,"%s",s.c_str());
				G[i][j] = G[j][i] = atoi(cv) ;
			}
			else{
				G[i][j] = G[j][i] = INF;
			}
		}
	}

	dijkstra(0);

	int total = 0;
//	cout << "print" << endl;
	int min = INF;
	for(int i = 1;i < n;i++)
		if(min > D[i])
			min = D[i];
//	cout << endl;
	cout << min << endl;

//	cout << endl;
//
//	for(int i = 0;i < n ;i++){
//		for(int j = 0 ; j < n ; j++){
//			cout << G[i][j] << "                    ";
//		}
//		cout << endl;
//	}

	return 0;
}
