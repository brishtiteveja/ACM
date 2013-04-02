/************************ Wrong Answer , Ajmarin's code ******************************/
//============================================================================
// Name        : 725-Division.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : Iterative Complete Search
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

typedef unsigned long int uli;

#define REP(i,s,e) for(uli i = uli(s) ; i <= uli(e) ; i++)
#define REP2(i,s,e) for(int i = int(s); i <= int(e);i++)


//function to count digit of a number
int digitCount(uli num){
	int c = 0;
	while(num){
		num /= 10;
		c++;
	}
	return c;
}

//find out whether all the digits of a number are different
bool digitDif(uli num){
	if(digitCount(num) <= 5){
		int r[5];
		int k = 0;

		while(num){
			r[k++] = num % 10;

			REP2(j,0,k-2){
				if(r[k-1] == r[j]){
					return false;
				}
			}

			num /= 10;
		};

		return true;
	}
	else{
		return false;
	}
}


//find out whether all the digits of two numbers are different from each other
bool digitDifWithin(uli num1,uli num2){
	int n1 = digitCount(num1);
	int n2 = digitCount(num2);
	int r1[n1];
	int r2[n2];
	int k = 0;

	if(n1 == 4 && n2 == 4){
		return false;
	}

	if(!digitDif(num1) || !digitDif(num2)){
		return false;
	}



	while(num1){
		r1[k++] = num1 % 10;
		num1 /= 10;
	}

	if(n2 == 4){		//the first digit of fghij is zero
		REP(j,0,n1){
			if(r1[j] == 0)			//check if abcde contains zero
				return false;
		}
	}



	k = 0;
	while(num2){
		r2[k++] = num2 % 10;
		REP(j,0,n1){
			if(r2[k-1] == r1[j])
				return false;
		}
		num2 /= 10;
	}

	if(n2 == 4){		//the first digit of fghij is zero
		REP(j,0,n1){
			if(r2[j] == 0)			//check if fghij contains zero
				return false;
			}
	}

	return true;
}

int main() {
	uli abcde,fghij,N,sol;

	bool first = true;
	bool printfirst = true;
	while(cin >> N && N){
		if(!first){
			cout << endl;
		}
		first = false;
		sol = 0;



		for(uli i = 1234; i <= 98765; i++){
			if(digitDif(i)){
				fghij = i;
				abcde = fghij * N;
				if(digitCount(abcde) <= 5 && digitDifWithin(abcde,fghij)){
					if(!printfirst)
							cout << endl;
					printfirst = false;

					abcde = fghij * N;
					cout << ((digitCount(abcde) == 4) ? "0" : "" ) << abcde << " / " << ((digitCount(fghij) == 4) ? "0" : "" ) << fghij << " = " << N;
					sol++;
				}
			}

		}
		if(!sol){
			if(!printfirst)
					cout << endl;
			printfirst = false;
			cout << "There are no solutions for " << N << ".";
		}
	}



	return 0;
}
