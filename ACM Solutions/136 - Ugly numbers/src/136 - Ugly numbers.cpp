//============================================================================

// Name        : 136- Ugly numbers.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : ACM Problem,
// Status	   : Unsolved
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

#define maxPrime 1000000

long int primes[maxPrime];

void primeTable(){
	int idx = 1;
	primes[idx++] = 2;

	for(int n = 3;idx <= maxPrime ; n += 2){
		int k = 1;
		bool f = false;
		for(int d = primes[k];d*d < n; d = primes[++k]){
			if(n % d == 0){
				f = true;
				break;
			}
		}
		if(!f)
			primes[idx++] = n;
	}
}

int dividedBy(long int n){
	if(n %2 != 0 && n % 3 != 0 && n % 5 != 0)    //not divided by 2 , 3 and 5
		return 0;

	for(long int k = 4;primes[k] < sqrt(n) ;k++){
//		cout << "prime =" << primes[k] << endl;
		if(n % primes[k] == 0){		//divided by a prime not 2 , 3 or 5
			return 0;
		}
	}
	cout << endl<< "n = "<< n ;
	cout << endl;

	return 1;						//divided by only 2,3 or 5
}

int main() {
	primeTable();
//	for(int i = 1; i <= 30001;i++)
//		cout << primes[i] << " ";

	int c = 1;
	long int n;
	for(n = 2 ; ; n++ ){
		if(dividedBy(n)){
			c++;
		}
		if(c == 1500)
			break;
	}
	cout << endl;
	cout << "The 1500'th ugly number is " << n << "."<< endl;
	return 0;
}
