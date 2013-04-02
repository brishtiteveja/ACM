//============================================================================
// Name        : map STL.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share,copy and distribute
// Description : This file has clarified some concept of c++ :map STL

//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define FOR(i,N) for(i = 0;i < N; i++)
#define all(C) C.begin(),C.end()
#define tr(C,it)\
	for(typeof((C).begin()) it = (C).begin(); it != (C).end();it++)
#define push_back pb
#define present(C,e) if((C).find(e) != (C).end())

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector< pair<double,pii> > vpdpii;

bool compareFunc(const string& e1,const string& e2){
	return e1 < e2;
}

struct compareStruct{
	bool operator()(const string& e1,const string& e2){
		return e1 > e2;
	}
};

class compareClass{
public:
	bool operator()(const string& e1,const string& e2){
		return e1 > e2;
	}
};

template<typename T>
class compareClass2{
public:
	bool operator()(const T& e1,const T& e2){
		return e1 > e2;
	}
};

void function(const map<string,int>& m){
//	if(m["themeaning"] == 42){  //can't map like this in constant map object
//		cout << "wrong" << endl;
//	}

	map<string,int>::const_iterator it = m.find("Top");//const iterator

	if(it != m.end() && it->second == 42){
		cout << "correct" << endl;
	}
}

int m8(){
	//map is sorted and non duplicated
	bool (*fnP)(const string&,const string&) = compareFunc;


	map<string,int,bool(*)(const string&,const string&)> m(fnP); // with __Compare& comp
	m["Top"] = 30;
	m["Coder"] = 40;
	m["SRM"] = 50;
	m["SRM"] = 100; // last value exists

	map<string,int>::iterator it;
	tr(m,it){
		cout << it->first << " " << it ->second << endl;
	}
	cout << endl;


	it = m.find("Top");
	cout << it ->second << endl;

	cout << endl;
	//map with custom compare class
	map<int,int,compareClass2<int> > m2;

	m2[1] = 30;
	m2[100] = 40;
	m2[20] = 50;
	map<int,int>::iterator itt = m2.begin();
	tr(m2,itt){
		cout << itt->first << " " << itt ->second << endl;
	}

	return 0;
}
