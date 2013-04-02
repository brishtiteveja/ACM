
#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,N) for(i = 0 ; i < N; i++)
#define tr(C,it)\
	for(typeof((C).begin()) it = (C).begin(); it != (C).end(); it++)
#define all(C) (C).begin(),(C).end()


using namespace std;

class edge{
public:
	int u,v,cost;
	edge(int _u,int _v,int _cost):u(_u),v(_v),cost(_cost){}

};

bool operator< (const edge& e1,const edge& e2){
	if(e1.u != e2.u){
		return e1.u < e2.u;
	}
	if(e1.v != e2.v){
		return e1.v < e2.v;
	}
	return e1.cost < e2.cost;
}

ostream& operator<<(ostream& o , const edge& e){
	return o << e.u << " " << e.v << " " << e.cost << " ";
}

int mm(){
	typedef vector<int> vi;
	typedef vector<int>::iterator itr;
	typedef vector<edge> ve;
	typedef vector<edge>::iterator et;

	ve v;


	v.push_back(edge(1,2,10));
	v.push_back(edge(1,3,20));
	v.push_back(edge(1,4,30));
	v.push_back(edge(3,4,40));
	v.push_back(edge(3,5,50));
	v.push_back(edge(3,5,60));

	et it;

	do{
		it = v.begin();
		tr(v,it){
			cout << *it << ", " ;
		}
		cout << endl;
	}while(next_permutation(all(v)));



	return 0;
}
