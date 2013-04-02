//============================================================================
// Name        : 821- Continued Fractions.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : ACM problem, Number theory
//============================================================================

#include <iostream>
using namespace std;

void calcB(int d,int n){
	if(n == 1){
		cout << d ;
		return;
	}
	if(n != 0){
		if(d%n != 0){
			cout << d / n;
			cout<< ",";
			calcB(n,d%n);

		}else{
			cout << d;
		}
	}

}

int main() {
	int d,n;

	while(cin >> d && !cin.eof() && cin >> n){
		if( n != 0){
			int b0 = d / n;
			cout << "[" << b0 ;
			if(d%n != 0){
				cout << ";";
				calcB(n,d % n);
			}
			cout << "]" << endl;
		}

	}
	return 0;
}
