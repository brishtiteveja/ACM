//============================================================================
// Name        : 10221-.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

	#include <iostream>
	#include <iomanip>
	#include <cmath>


	using namespace std;

	#define FOR for(i = 0;i < N; i++)
	#define floatN(n) setiosflags(ios::fixed) << setprecision(n)


	int main() {
		int r,t;
		string s;
		int R = 6440;

		for(;cin >> r && !cin.eof() && cin >> t && cin >> s ;){
			double td;
			r = R + r;
			td = ( M_PI / (double)180.0 ) * t ;
			if(td > M_PI){
				td = 2* M_PI - td;
			}
			if(s == "min"){
				td = ( M_PI / (double)180.0 ) * t / 60.0 ;
			}
			double aL = r * td;
			double lL = 2 * r * sin((double)td/2);
			cout << floatN(6) << aL << " " << lL << endl;
		}

		return 0;
	}
