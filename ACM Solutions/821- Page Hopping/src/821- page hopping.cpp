//============================================================================
// Name        : 821- page hopping.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : ACM problem, Dijkstra, Graph Theory,Search
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <set>

using namespace std;

#define fp(n) setiosflags(ios::fixed) << setprecision(n)
#define tr(C,it)\
	for(typeof(C.begin()) it = C.begin(); it != C.end(); it++)
#define all(C) C.begin(),C.end()
#define pb push_back

#define INF 1000000000

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii p2p(101);											//page to page connection list
vi exist(101,0);										//page exist flag vector


int* D;													//distance vector from source page to a page for djkstra

void djkstra(int s){
	set<ii> Q;											//the Q
	Q.insert(ii(0,s));									//inserting the source vertex into the queue
	D[s] = 0;											//distance from source to source

	while(!Q.empty()){
		ii top = *Q.begin();							//least distant node from source since Q is sorted
		Q.erase(Q.begin());
		int u = top.second;								//that node index
		int d = top.first;								//distance of that node from source

		vvii::iterator it;
		tr(p2p[u],it){									//all neighbors of u
 			int v = it->second;
 			int cost = it->first;						//cost(u,v)

			if(D[v] > D[u] + cost){
				if(D[v] != INF){
						Q.erase(Q.find(ii(D[v],v)));					//erase from Q if already updated
				}
				D[v] = D[u] + cost;
				Q.insert(ii(D[v],v));
			}

		}
	}
}

long int nPr(int n,int r){
	long int res = 1;
	for(int i = 1;i <= n-r; i++,n--){
		res *= (n/i);
	}

	return res;
}

int main() {
int c = 0;
	while(1){
		p2p.resize(101);
		exist.resize(101);

		int p1,p2; 										//page 1 and page 2
		int max = 0;									//maximum index of the page
		bool f = false;
		int pc = 0;										//page counter

		while(cin >> p1 >> p2 && p1 && p2){
			f = true;									//entered into the while loop once
			p2p[p1].pb(ii(1,p2));						//cost is set to 1 from p1 to p2
			exist[p1] = 1;								//page p1 exists
			exist[p2] = 1;
			if(p1 > max)
				max = p1;
		}
		vi::iterator itt;
		tr(exist,itt){
			if(*itt == 1)
				pc++;
		}


		if(!f && !p1 && !p2)
			break;

		p2p.erase(p2p.begin() + max + 1,p2p.end());		//erasing unnecessary page to page lists
		cout << "Case "<< ++c <<": average length between pages = ";

		int total = 0;

		D = new int[max + 1];							//Distance vector
		for(int s = 1 ; s <= max ;s++){  				//start vertex
			if(exist[s]){								//if page exists
				//initializing distance vector
				for(int i = 1;i <= max;i++){
					if(exist[i])
						D[i] = INF;
				}

				djkstra(s);

				for(int i = 1;i <= max;i++){
					if(exist[i]){
						if (D[i] == INF){
							break;
						}
						total += D[i];
					}
				}
			}
		}
		if(total >= INF){
			cout << "Some nodes in Graph not reachable" << endl;
		}else{
			cout << fp(3) << (double)total / (pc*(pc-1)) << " clicks"<< endl;
		}
		p2p.clear();
		exist.clear();
	}

	return 0;
}

