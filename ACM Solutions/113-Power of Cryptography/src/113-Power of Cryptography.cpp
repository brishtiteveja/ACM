//============================================================================
// Name        : 113-Power Of Cryptography.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to Share
// Description : ACM problem
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define floatN(n) setiosflags(ios::fixed)<< setprecision(n)

int main() {
	long double n,p,res;
	while(cin >> n && !cin.eof() && cin >> p){
		res = exp(log(p)/n);
		cout << floatN(0) << res << endl;
	}

	return 0;
}
