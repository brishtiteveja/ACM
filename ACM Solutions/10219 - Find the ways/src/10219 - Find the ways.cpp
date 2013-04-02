//============================================================================
// Name        : 10219.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

//
////works for small combinatorials
//int countDigit(int r){
//	if(r == 0){
//		return 0;
//	}else{
//		return 1 + countDigit(r / 10);
//	}
//}
//
//int main() {
//	long long n ,k ;
//	while(cin >> n >> k){
//		int dn = 1,nn = 1;      	//denominator and nominator
//		while(k > 0){
//			dn *= k--;
//			nn *= n--;
//		}
//		cout << dn << " " << nn << endl;
//		int res = nn / dn;
//		cout << res << endl;
//		cout << countDigit(res) << endl;
//	}
//	return 0;
//}


int main(){
	long long n,k;
	while(cin >> n >> k){
		double r = 0;
		while(k > 0){
			r += (log10(n--) - log10(k--));
		}

		cout << floor(r) + 1<< endl;
	}
}
