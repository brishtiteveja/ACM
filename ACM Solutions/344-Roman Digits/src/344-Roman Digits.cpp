//============================================================================
// Name        : 344-Roman Digits.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : UVA 344
// Category	   : Ad HOC,Mathematics.
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	vi nr(5,0);
	vvi res;
	res.push_back(nr);

	int n;

	//creating bottom up table from 1 to 100
	for(int n = 1;n <= 100; n++){
					int c = n / 10;
					if(c < 4){
						nr[2] += c;				//x
					}
					else if(c == 4){			// 40 = xl
						nr[2] += 1;				// x
						nr[3] += 1;				// l
					}
					else if(c == 5){			// 50 = l
						nr[3] += 1;
					}
					else if(c < 9){
						nr[3] += 1;				//l
						nr[2] += (c - 5);		//x
					}else if(c == 9){			//90 = cx
						nr[4] += 1;				//c
						nr[2] += 1;				//x
					}else{
						nr[4] += 1;				//c
					}

					int r = n % 10;
					if(r < 4){
							nr[0] += r;			//i
					}
					else if(r == 4){			// 4 = iv
							nr[0] += 1;			// i
							nr[1] += 1;			// v
					}
					else if(r == 5){			// 5 = v
							nr[1] += 1;
					}
					else if(r < 9){
							nr[1] += 1;			// v
							nr[0] += (r - 5);	//i
					}else if(r == 9){			//9 = ix
							nr[2] += 1;			//x
							nr[0] += 1;			//i
					}else{
					}
				res.push_back(nr);
	}

	while(cin >> n && n){
		cout << n <<": "<< res[n][0] <<" i, "<<res[n][1]<< " v, "<<res[n][2]<<" x, "<<res[n][3]<< " l, "<< res[n][4]<<" c"<< endl;
	}

	return 0;
}

