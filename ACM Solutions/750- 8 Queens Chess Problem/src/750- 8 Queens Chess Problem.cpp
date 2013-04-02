//============================================================================
// Name        : 750-.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share
// Description : Recursive Backtracking
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int x[9], TC, a ,b , lineCounter ;

bool place(int queen,int row){
	for(int prev = 1; prev <= queen - 1; prev++) // check previously placed queens
	{
		if(x[prev] == row || (abs(x[prev] - row) == abs(prev - queen))){
			return false;
		}
	}
	return true;
}

void NQueens(int queen){
	for(int row = 1 ; row <= 8 ; row++){
		if(place(queen,row)){	//if can place this queen at this row?
			x[queen] = row;	//put this queen in this row
			if(queen == 8 && x[b] == a){	//a candidate solution & (a,b) has 1 queen
				printf("%2d      %d",++lineCounter,x[1]);
				for(int j = 2 ; j <= 8 ; j++)
					printf(" %d",x[j]);
				cout << endl;
			}else{
				NQueens(queen + 1);
			}
		}
	}
}

int main(){
	cin >> TC;
	while(TC--){
		cin >> a >> b;
		memset(x,0,sizeof(x));
		lineCounter = 0;
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" <<endl<<endl;
		NQueens(1);
		if(TC)
			cout << endl;
	}
	return 0;
}

/****************Solution by Ajmarin ****************************/

//#include <iostream>
//#include <cstdio>
//using namespace std;
//
//#define REP(i,s,e) for(int i = int(s); i <= int(e);i++)
//
//
//bool row[8] = {0,0,0,0,0,0,0,0};
//bool d1[16] = {0,0,0,0,0,0,0,0,
//			   0,0,0,0,0,0,0,0};
//bool d2[16] = {0,0,0,0,0,0,0,0,
//			   0,0,0,0,0,0,0,0};
//int qrow[8] = {0,0,0,0,0,0,0,0};
//
//int sol;
//
//void paint(int r,int diag1,int diag2,int busy){
//	row[r] = d1[diag1] = d2[diag2] = busy;
//}
//
//void bt(int k){
//	if(k == 8){
//		printf("%2d     ", sol++);
//		for(int i = 0;i < 8 ; i++)
//			printf(" %d",qrow[i]);
//		cout << endl;
//		return;
//	}
//
//	if(qrow[k])
//	{
//		bt(k+1);
//		return;
//	}
//
//	int diag1,diag2;
//	for(int i = 0;i < 8 ; i++){
//		diag1 = 7 + i - k;
//		diag2 = i + k;
//		if(!row[i] && !d1[diag1] && !d2[diag2]){
//			paint(i,diag1,diag2,1);
//			qrow[k] = i + 1;
//			bt(k+1);
//			qrow[k] = 0;
//			paint(i,diag1,diag2,0);
//		}
//	}
//
//}
//
//int main() {
//
//	int n,r,c;
//	cin >> n;
//
//	while(n--)
//	{
//		cout << "SOLN       COLUMN" << endl;
//		cout << " #      1 2 3 4 5 6 7 8" <<endl<<endl;
//		cin >> r >> c;
//
//		sol = 1;
//		paint(r-1,7+r-c,r+c-2,1);
//		qrow[c-1] = r;
//		bt(0);
//		qrow[c-1] = 0;
//		paint(r-1,7+r-c,r+c-2,0);
//		if(n)
//		  cout << endl;
//
//	}
//
//	return 0;
//}
