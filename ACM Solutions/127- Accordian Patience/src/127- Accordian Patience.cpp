////////******* Wrong Answer pile numbers are correct but piles are different ***********//


//============================================================================
// Name        : 127- Accordian Patience.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define REP(i,s,e) for(int i = int(s);i <= int(e) ;i++)
#define tr(C,it,s)\
	for(typeof((C).begin()) it = (typeof((C).begin()))s; it != (C).end();it++)
#define all(C) (C).begin(),(C).end()
#define pb push_back

struct card{
	char suit;
	char rank;
public:
	bool operator==(const card& c){
		return (suit == c.suit) || (rank == c.rank);
	}
};

typedef stack<card> stk;
typedef vector<stk> vs;



int main() {


	int cnt = 0;
	string s ;


	vs vst;	//vector of stacks

	while(cin >> s && s[0]!= '#'){
		stk st;	//a stack of cards
//		cout << s;
		card c;
		c.suit = s[0];
		c.rank = s[1];			//card retrival
		st.push(c);
		vst.pb(st);	//pushing the card in the last card stack
		cnt++;					//card counter


//		QD AD 8H 5S 3H 5H TC 4D JH KS 6H 8S JS AC AS 8D 2H QS TS 3S AH 4H TH TD 3C 6S
//		8C 7D 4C 4S 7S 9H 7C 5D 2S KD 2D QH JD 6D 9D JC 2C KH 3D QC 6C 9S KC 7H 9C 5C

		//check the immediate neighbor and 3rd left neighbor

		//at first the only movable card will be the new card because previously all cards were properly moved
		for(vs::iterator it = vst.begin(); it != vst.end();){
			int sx = it - vst.begin() ; 	//start index
			if(sx >= 3 && c == (it-3)->top()){
				card top = it->top();		//the top card of the current stack
				it->pop();					//popping that card
				if((*it).size() == 0){	//if after popping the size of the stack is zero, then erase the stack from the stack vectors
					vst.erase(it);
				}
				(it-3)->push(top);
				if(it-3 >= vst.begin())
					it = it - 3;	// new card has been pushed in 3rd left so go to the 6th left
			}
			else if(sx >= 1 && c == (it-1)->top()){
				card top = it->top();
				it->pop();
				if((*it).size() == 0){	//if after popping the size of the stack is zero, then erase the stack from the stack vectors
					vst.erase(it);
				}
				(it-1)->push(top);
				if(it-3 >= vst.begin())
					it = it - 3;    //new card has been pushed in left so go to the 3rd left of the left
			}
			else{
				it++;
			}
		}

		if(cnt == 52){
			//show answer
			cout << vst.size() << " ";
			cout <<"piles remaining ";
			cout << endl;
			tr(vst,it,vst.begin()){
				cout << it->size() << " ";

				for(int k = 0; k < it->size();k++){
					cout << it->top().suit << it->top().rank << " ";
					it->pop();
				}
				cout << endl;
			}

			cnt = 1;
		}
	}

	return 0;
}
