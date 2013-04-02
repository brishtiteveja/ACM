//============================================================================
// Name        : 442-Matrix.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : ACM problems
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> vc;

//9
//A 50 10
//B 10 20
//C 20 5
//D 30 35
//E 35 15
//F 15 5
//G 5 10
//H 10 20
//I 20 25
//A
//B
//C
//(AA)
//(AB)
//(AC)
//(A(BC))
//((AB)C)
//(((((DE)F)G)H)I)
//(D(E(F(G(HI)))))
//((D(EF))((GH)I))
//
//
//(A)
//(AB)



int main() {
	int n;
	cin >> n;
	int m[n][2];

	char c;
	for(int i = 0 ; i < n ; i++){
		cin >> c >> m[i][0] >> m[i][1];
	}



	string s;
	while(cin >> s && !cin.eof()){
		long long int ans = 0;
		bool e = false; 	//error flag

		vc stack;
		top = 0;
		for(int i = 0; s[i] != '\0';i++){
			char a;
			char b;
			if(s[i] == ')'){
				a = stack[top--];
				b = stack[top--];
				ans = m[a-'A'][0] * m[a-'A'][1] * m [b-'A'][1];
			}
		}

		if(!e){
			cout << ans << endl;
		}else{
			cout << "error" << endl;
		}

	}



	return 0;
}
