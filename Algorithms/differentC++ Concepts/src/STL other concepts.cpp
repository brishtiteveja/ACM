//============================================================================
// Name        : set STL concept.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share,copy and distribute
// Description : This file has clarified some concept of c++ : other concepts of STL

//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

#define FOR(i,N) for(i = 0; i < N; i++)
#define tr(C,it) \
	for(typeof((C).begin()) it = (C).begin(); it != (C).end();it++)
#define all(C) (C).begin(),(C).end()

using namespace std;

int ms2(){
	typedef vector<pair<string,int> > vpsi;
	typedef map<string,int> msi;
	typedef vector<pair<string,int> >::iterator vpsiit;
	typedef vector<int> vi;
	typedef vector<int>::iterator viit;

	msi m;
	m["ananda"] = 20;
	m["brishti"] = 30;
	m["syum"] = 50;

	vpsi v(all(m));
	vpsiit it;

	tr(v,it){
		cout << it->first << " " << it ->second << endl;
	}


	vi v1;
	vi v2;

	int i;
	FOR(i,10){
		v1.push_back(rand()%100);
	}

	viit it1;

	//resizing v2
	v2.resize(v1.size());

	//copying all elements of v1 into v2
	copy(all(v1),v2.begin());

	cout << endl;

	FOR(i,10){
		v2[i] = rand()%100;
	}

	cout << "print v1" << endl;
	tr(v1,it1){
			cout << *it1 << " ";
	}
	cout << endl;
	cout << "print v2" << endl;
		tr(v2,it1){
				cout << *it1 << " " ;
		}
	cout << endl;
	v1.resize(v1.size()+v2.size());
	//copying v2 after v1
	copy(all(v2),v1.end()-v2.size());
	cout << "print after copying" << endl;
	tr(v1,it1){
				cout << *it1 << " ";
	}
	cout << endl;

	//resetting v2 and v1
	v2.resize(5,0);
	FOR(i,5){
		v2[i] = rand()%100;
	}
	srand(time(NULL));
	cout << endl;
	v1.resize(5,0);
	cout << "print new v1" << endl;
	FOR(i,5){
		v1[i] = rand()%100;
	}
	tr(v1,it1){
			cout << *it1 << " ";
	}
	cout << endl;
	cout << "print new v2" << endl;
	tr(v2,it1){
		cout << *it1 << " " ;
	}
	cout << endl;
	//merging vectors: union A ∪ B,intersection A ⋂ B,difference A-B ,symmetric difference (A\B)U (B\A)
	//set intersection

	cout << "set intersection" << endl;
	vi res(min(v1.size(),v2.size()));
	viit endIntsct =set_intersection(all(v1),all(v2),res.begin());

	res.resize(endIntsct - res.begin());
	tr(res,it1){
		cout << *it1 << " " ;
	}
	cout << endl;



	//set union
	cout << "set union" << endl;
	res.resize(v1.size()+v2.size(),0);
	viit endUnion = set_union(all(v1),all(v2),res.begin());
	res.resize(endUnion-res.begin());

	tr(res,it1){
		cout << *it1 << " " ;
	}
	cout << endl;

	//set difference
	cout << "set difference" << endl;
	res.resize(v1.size());
	viit endDiff = set_difference(all(v1),all(v2),res.begin());
	res.resize(endDiff - res.begin());

	tr(res,it1){
		cout << *it1 << " ";
	}
	cout<< endl;
	//accumulating all elements of v1
	int s = accumulate(all(v1),(double)0);
	cout << "total of v1 = " << s << endl;
	//multiplying all elements of v
	int p = accumulate(all(v1),(int)1,multiplies<int>());
	cout << "mul =" << p << endl;

	int r = inner_product(all(v1),v2.begin(),0);
	cout << r << endl;

	return 0;
}
