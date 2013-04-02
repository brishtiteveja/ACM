//============================================================================
// Name        : 10015-Josph.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

#define tr(C,it) \
	for(typeof((C).begin()) it = (C).begin(); it != (C).end();it++)
#define all(C) (C).begin(),(C).end()
#define pb push_back
#define present(C,x) find(all(C),x) != (C).end()

typedef vector<int> vi;


void findPrimes(vi& Primes,int n){
	Primes.pb(2);

	int d ; //prime divisors

	for(int i = 3; i <= n;i++){
		bool f = false;
		int k = 0;
		for(d = Primes[k]; d * d <= i; d = Primes[++k]){
				if(i % d == 0){
					f = true;
					break;
				}
		}
		if(!f)
			Primes.pb(i);
	}

}

int main() {
	int n;
	vi Primes;
	findPrimes(Primes,40000);

	for(;cin >> n && n;){
		vi v(n);
		vi::iterator it;
		tr(v,it){ 						//initializing the vector
			*it = it - v.begin() + 1;
		}



		int k = 0;			// Prime index
		int i = n;			// number of people
		int next = -1;
		for(;i > 1;i--){
			int m = Primes[k++];
//			cout << m << endl;
			next = (next + 1) % n;
			for(int c = 0;c < m; next = (next + 1) % n){
				if(v[next] == 0){
					continue;
				}else{
					c++;
				}
				if(c == m){
					v[next] = 0;
					break;
				}
			}
//			tr(v,it){
//				cout << *it << " " ;
//			}
//			cout << endl;
		}

		int res;
		vi::iterator it1;
		tr(v,it1){
			if(*it1 != 0){
				res = *it1;
				break;
			}
		}

		cout << res << endl;

	}

	return 0;
}
