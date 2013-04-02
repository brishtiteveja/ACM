//============================================================================
// Name        : set STL concept.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share,copy and distribute
// Description : This file has clarified some concept of c++ : set STL

//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define FOR(i,N) for(i = 0;i < N;i++)
#define traverse(C,it)\
	for(typeof(C.begin()) it = C.begin(); it != C.end(); it++ )
#define all(C) C.begin(),C.end()

int m6(){

//set is a container with following features
//	we need a container with the following features:
//	add an element, but do not allow duples [duplicates?]
//	remove elements
//	get count of elements (distinct elements)
//	check whether elements are present in set

	set<int> s;
	int i;
	FOR(i,100){
		s.insert(i);
	}
	s.insert(42); //does nothing because 42 already exists

	for(int i =2; i <= 100;i += 2){
		s.erase(i);
	}

	set<int>::iterator it;
	traverse(s,it){
		cout << *it << " ";
	}
	cout << endl;

	set<int>::iterator it1;
	set<int>::iterator it2;

	it1 = s.find(11);
	it2 = s.find(77);

	cout << "iterator1 = " << *it1 << "iterator2 = "<< *it2 <<endl;

	set<int> news;
	FOR(i,100){
		news.insert(rand()%100);
	}
	set<int>::iterator itt;
	traverse(news,itt){
		cout << *itt << " ";
	}
	cout << endl;


	//we can use set to create duplicate less sorted vector
	vector<int> v1;
	FOR(i,100){
		v1.push_back(rand()%100);
	}
	vector<int>::iterator itt2;
	itt2 = v1.begin();
	cout << "print vector v1" << endl;
	traverse(v1,itt2){
		cout << *itt2 << " ";
	}
	cout << endl;

	set<int> s1(all(v1));
	vector<int> v2(all(s1));
/****************/
//sorted and non duplicated vector
	itt2 = v2.begin();
	cout << "print vector v2" << endl;
	traverse(v2,itt2){
			cout << *itt2 << " ";
	}
	cout << endl;

	//a string vector
	string strVec[5] = {"ananda","brishti","syum","borno","shohag"};
	FOR(i,5){
		cout << strVec[i] << endl;
	}
	//a set of complex element
	set <pair<string,pair<int,vector<int> > > > SS;
	int k;
	vector<int> v;
	FOR(k,5){
		int anInt = rand() % 100;
		FOR(i,5){
			int a = rand()%100;
			v.push_back(a);
		}
		pair<int,vector<int> > aPair(anInt,v);
		pair<string,pair<int,vector<int> > > thePair(strVec[k],aPair);

		SS.insert(thePair);
	}
//traversing the complex set
	traverse(SS,it){
		cout << it -> first << " " << it ->second.first << " " ;
		FOR(k,5)
			cout << it -> second.second.at(k) << " ";
		cout << endl;
	}


	return 0;
}
