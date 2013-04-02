////============================================================================
//// Name        : different Concepts.cpp
//// Author      : Dhrubo Abdullah Khan
//// Version     : 1
//// Copyright   : Free to share,copy and distribute
//// Description : This file has clarified some concept of c++ :  vector,pair,sort,custom comparison
////============================================================================
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//#define FOR(i,N) for(i = 0; i < N ;i++)
//#define tr(C,it)\
//	for(typeof((C).begin()) it = (C).begin(); it != (C).end();it++)
//#define all(C) (C).begin(),(C).end()
//#define pb push_back
//
//using namespace std;
//
//typedef vector<int> vi;
//typedef vector<int>::iterator itr;
//typedef vector<vi> vvi;
//typedef pair<int,int> pii;
//typedef vector<pii> vpii;
//typedef vector<pair<double,pii> >vpdpii;
//
//template<class T>
//class compareClass{
//private:
//	T v;
//public:
//	bool operator()(const T& e1,const T& e2){
//		return e1 < e2;
//	}
//
//	T someFunction(T a);
//};
//
//template<class T>
//T compareClass<T>::someFunction(T a){
//	v = a;
//	return v;
//}
//
//
//
//
//
////custom compare function
//bool compareFunc(const pair<double,double>& p1, const pair<double,double>& p2){
//	if(p1.first > p2.first){
//		return true;
//	}
//	else if(p1.first < p2.first){
//		return false;
//	}else{
//		return p1.second > p2.second;
//	}
//}
//
////custom compare structure , the myCompare struct object is used
//struct myComparison{
//	bool operator()(const pair<double,double >& p1,const pair<double,double >& p2) const{
//		if(p1.first > p2.first){
//				return true;
//		}
//		else if(p1.first < p2.first){
//			return false;
//		}else{
//			return p1.second > p2.second;
//		}
//	}
//}myCompare;
//
////custom compare class, an object of this class is used
//class myComparisonClass{
//public:
//	bool operator() (const pair<double,double>& p1,const pair<double,double >& p2) const{
//		if(p1.first > p2.first){
//			return true;
//		}
//		else if(p1.first < p2.first){
//			return false;
//		}else{
//			return p1.second > p2.second;
//		}
//	}
//};
//
//void someFuntion(const vector<int>& v){
//	//v[3] = 4;
////	can't modify vector because of the const
//}
//void modifyVector(vector<int>& v){
//	v[3] = 4;
//}
//
//int main() {
//	vector<int> a(3); //vector with 3 elements
//
//
//	//initializing a 2 dimensional array
//	vector<vector<int> > v(5,vector<int>(7,random()% 10));
//
//	int i,j;
//	FOR(i,5){
//			FOR(j,7){
//				v[i][j] = rand() % 5;
//			}
//
//		}
//	sort(v.begin(),v.end());
//
//	FOR(i,5){
//		FOR(j,7){
//			cout << v[i][j] << " " ;
//		}
//		cout << endl;
//	}
//
//
//
//	//learning pairs
//	pair<int,int> b;
//
//	FOR(i,4){
//		FOR(j,5){
//			b.first = rand()%10+1 ;
//			b.second = rand()%20+1;
//		}
//	}
//
//	//cout << b.first << endl;
//	//cout << b.second << endl;
//
//	pair<int,pair<int,int> > P[2];
//	string s = "ananda";
//	P[0].first = 1;
//	P[0].second.first = 20;
//	P[0].second.second = 30;
//
//	cout << P[0].first << " " << P[0].second.first << " "<< P[0].second.second << endl;
//
//	vector<pair<double,double> > pv;
//	FOR(i,5){
//		pair<double,double> p;
//		p.first = 10;//rand() % 5;
//		p.second = rand() % 20;
//		pv.push_back(p);
//	}
//
//	//sorting the pair<double, double> vector in a descending order firstly of the first element of the pair,if they are equal then the second element of the pair
//	//sorting with the custom compare function
////	sort(pv.begin(),pv.end(),compareFunc);
//
//
//	//sorting with the custom compare struct object
////	sort(pv.begin(),pv.end(),myCompare);
//
//
//	//sorting with the custom compare class object
//	myComparisonClass compareObj;
//	sort(pv.begin(),pv.end(),compareObj);
//	//or,
////	sort(pv.begin(),pv.end(),myComparisonClass());
//
//	FOR(i,5){
//		cout << "first = " << pv[i].first << "second = " << pv[i].second << endl;
//	}
//
//
//	//vector of pairs
//	//polar angles of the points in cartesian coordinates
//	vector<pair<double,pair<double,double> > > pcP;
//
//
//	FOR(i,10){
//		pair<double,pair<double,double> > P;
//		P.first = rand()% 180;
//		P.second.first = rand() %10;
//		P.second.second = rand() %20;
//		pcP.push_back(P);
//	}
//
//	sort(pcP.begin(),pcP.end());
//
//	FOR(i,10){
//		cout << "x : " << pcP[i].second.first  << " ";
//		cout << "y : " << pcP[i].second.second  << " ";
//		cout << "Polar Angle: " << pcP[i].first << " " ;
//		cout << endl;
//	}
//	cout << v[2][3] << " ";
//	cout << v[3][2] << "\n";
//	//swap function
//	swap(v[2][3],v[3][2]);
//	cout << v[2][3] << " ";
//	cout << v[3][2] << "\n";
//
//
////
////	FOR(i,4){
////		FOR(j,5){
////			cout << b[i][j] << " ";
////		}
////		cout << endl;
////	}
//
//
////all permutation check of vectors
//	vi vc;
//
//	FOR(i,5){
//		vc.pb(rand()%100);
//	}
//
//	compareClass<int> cmp;
//	sort(all(vc),cmp);
//
//	itr it;
//	tr(vc,it){
//		cout << *it << " " ;
//	}
//	cout << endl;
//
//	while(next_permutation(all(vc))){
//		itr itt; // iterator
//		tr(vc,itt){
//			cout << *itt << " " ;
//		}
//		cout << endl;
//	}
//
//	return 0;
//}
