//============================================================================
// Name        : 130-Roman.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : ACM problem (uva online judge)
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define precision(n) setiosflags(ios::fixed) << setprecision(n)
#define FOR(i,s,n) for(i = s ; i < n ; i++)
#define tr(C,it)\
	for(typeof((C).begin()) it = (C).begin(); it < (C).end(); it++)
#define all(C) (C).begin(),(C).end()
#define present(C,x) find(all(C),x) != (C).end()



int main() {
	vector<int> v;
	int n,k,c,a,i;										//c = counter of k, a = number of alive

	for(; cin >> n >> k && n  ;){
		vi p(n);										//n people alive in the beginning
		vi::iterator it;
		tr(p,it){										//reinitialization of p
		  	*it = it - p.begin() + 1;					// storing the index of each people
		 }

		for(it = p.begin(),a = n, c = k; n != 1 ;it++){		//counts k times till there remains only one person
			if(it == p.end())
				it = p.begin();

			while(*it == 0){
				it++;									//dead or no one
				if(it == p.end())
					it = p.begin();
			}

			if(c == 1){
				*it = 0;
				vi::iterator pos;
				for(i = 1, pos = it ;i<= k ;){
					pos++;
					if(pos == p.end())
						pos = p.begin();
					if(*pos != 0){
						i++;
					}
				}
				*it = *pos;											//coming to the victim's position
				*pos = 0  ;											//no one is there
				a--;												//number of alive decreased
				c = k;												//counting again started
			}else
				c--;												//counter decreased

			if(a == 1)
				break;
		}

	  //answer
		if(present(p,1))
			cout << 1 << endl;
		else
			cout << n - (*it - 1) + 1 << endl;						//shifting the count start position to the alive position
																	// and finding out who comes in the first place of the array
	}

	return 0;
}



