//============================================================================
// Name        : DFS.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share,copy and distribute
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i,N) for(i = 0;i < N; i++)
#define tr(C,it) \
	for(typeof((C).begin()) it = (C).begin();it != (C).end();it++)
#define all(C) (C).begin(),(C).end()
#define present(C,x) if( find( all((C)),x ) != (C).end() )

typedef vector<int> vi;
typedef vector<int>:: iterator vit;
typedef vector<vector<int> > vvi;

//We want to show whether our graph is connected or not

int N; 														// Number of vertices
int sv,gv;													//start and goal vertex
bool gr;													//goal reached flag
vi Visited; 												// visited vertex vector
vvi Graph; 													// Graph
vvi cost;													// Path Cost Vector
vi Parent;													// Parent Vector to create path
vi Path;													// Path Vector

int tmpParent = -1;
void DFS(int v){

	if(!Visited[v]){ 										//vertex not reachable are -1 by value.
															//So only the reachable and non visited vertex will be accessed
		Visited[v] = 1;  									// make this vertex visited
															// DFS is being given the w[i][0~5] values
		Parent[v] = tmpParent;
		tmpParent = v;
		if(v == gv - 1){
				gr = true;
		}
		vi V = vi(Graph[v]);
		vit it;
		tr(V,it){
			int i = it - V.begin();
			if(*it)
				DFS(i);
		}

	}
}

bool check_graph_is_connected(){
	sv = 1;													//start vertex
	gv = 5;													//goal vertex
	tmpParent = - 1;

	Visited.resize(N,0); 									// making all nodes non visited
	Parent.resize(N,-5);									// initializing the parent vector
	Parent[sv - 1] = -1;										//parent -1 means this is the start vector
	DFS(sv - 1);   											// starting from the start vertex

															// if there's at least one 0 in
															//visited vector i.e. that vertex denoted by its index is not visited
	present(Visited,0){										//in that case graph is not connected
		return false;
	}else{
		return true;
	}
}

void initGraph(){
	N = 5;
	Graph= vvi(N,vi(N));
	int graph[5][5] =  {   {  0,  0,  1,  0,  0 },			//declaration of data
						   {  0,  0,  0,  1,  0 },
						   {  0,  1,  0,  0,  0 },
						   {  0,  0,  0,  0,  1 },
						   {  1,  0,  0,  0,  0 }
						 };


	int i;
	FOR(i,N){
		Graph[i] = vi(graph[i], graph[i] + sizeof(graph[i])/sizeof(graph[i][0]));
	}

	// Print the Graph Structure
		int j,k;
		FOR(j,5){
			FOR(k,5){
				cout << Graph[j][k] << " ";
			}
			cout << endl;
		}
}

void findPath(int v){
	if(Parent[v] >= 0){
		Path.push_back(v);
		findPath(Parent[v]);
	}
}

int main() {

	initGraph(); 											//initialize the graph
	cout << "Find out Graph is connected or not" << endl;

	if(check_graph_is_connected()){
		cout << "connected" << endl;

		if(gr){
			cout << endl;
			findPath(gv - 1);								// find the path
															// print the path
			vi::iterator it;
			cout << sv << "->";
			reverse(all(Path));
			tr(Path,it){
				cout << *it + 1;
				if(it + 1 != Path.end()){
					cout << "->";
				}
			}
		}
	}else{
		cout << "not connected" << endl;
 	}

	return 0;
}
