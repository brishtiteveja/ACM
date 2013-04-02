//============================================================================
// Name        : 11475-Extend to Palindrome.cpp
// Author      : Ajmarin
// Version     : 1
// Copyright   : Free to share
// Description : Palindrome, String Search, KMP search
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int TT = 1 << 18, WW = TT;
char text[TT];
char word[WW]; //(the word to be analyzed)
int T[WW];	//(the table to be filled)
int len;


/*KMP Table*/
//algorithm kmp_table:
//    input:
//        an array of characters, W (the word to be analyzed)
//        an array of integers, T (the table to be filled)
//    output:
//        nothing (but during operation, it populates the table)
//
//    define variables:
//        an integer, pos ← 2 (the current position we are computing in T)
//        an integer, cnd ← 0 (the zero-based index in W of the next
//character of the current candidate substring)
//
//    (the first few values are fixed but different from what the algorithm
//might suggest)
//    let T[0] ← -1, T[1] ← 0
//
//    while pos is less than the length of W, do:
//        (first case: the substring continues)
//        if W[pos - 1] = W[cnd],
//          let cnd ← cnd + 1, T[pos] ← cnd, pos ← pos + 1
//
//        (second case: it doesn't, but we can fall back)
//        otherwise, if cnd > 0, let cnd ← T[cnd]
//
//        (third case: we have run out of candidates.  Note cnd = 0)
//        otherwise, let T[pos] ← 0, pos ← pos + 1

void build_table(){
	T[0] = -1,T[1] = 0;
	for(int cnd = 0,pos = 2; word[pos];){
		if(word[pos-1] == word[cnd]){ //(first case: the substring continues)
			cnd = cnd + 1;
			T[pos] = cnd;
			pos = pos + 1;
		}
		else if(cnd > 0){ //(second case: it doesn't, but we can fall back)
			cnd = T[cnd];
		}else{			  //(third case: we have run out of candidates.  Note cnd = 0)
			T[pos] = 0;
			pos = pos + 1;
		}
	}
}

//algorithm kmp_search:
//    input:
//        an array of characters, S (the text to be searched)
//        an array of characters, W (the word sought)
//    output:
//        an integer (the zero-based position in S at which W is found)
//
//    define variables:
//        an integer, m ← 0 (the beginning of the current match in S)
//        an integer, i ← 0 (the position of the current character in W)
//        an array of integers, T (the table, computed elsewhere)
//
//    while m+i is less than the length of S, do:
//        if W[i] = S[m + i],
//            if i equals the (length of W)-1,
//                return m
//            let i ← i + 1
//        otherwise,
//            let m ← m + i - T[i],
//            if T[i] is greater than -1,
//                let i ← T[i]
//            else
//                let i ← 0
//
//    (if we reach here, we have searched all of S unsuccessfully)
//    return the length of S

int kmp(){
	int i,m;

	for(i = 0,m = 0; text[m + i];){
		if(word[i] == text[m+i]){
			if(word[i] == '\0'){
				return m;
			}
			i++;
		}
		else{
				m = m + i - T[i];
				if(T[i] > -1)
					i = T[i];
				else
					i = 0;
		}
	}

	//(if we reach here, we have searched all of S unsuccessfully)
	//modified part
	while(m--){
		text[len++] = text[m];
	}
	//

	text[len] = '\0';
	return m + i;



}

int main() {

	while(scanf("%s",text) == 1){
		len = strlen(text);
		for(int i = 0; i < len ; i++){
			word[len - i - 1] = text[i];	//the reversed text will be the search word
		}
		word[len] = '\0';
		build_table();
		kmp();
		cout << text << endl;
	}

	return 0;
}
