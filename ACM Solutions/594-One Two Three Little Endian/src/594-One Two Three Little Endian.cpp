//============================================================================
// Name        : 594-One,Two,Three Little Endian.cpp
// Author      : Ajmarin,Dhrubo Abdullah Khan
// Version     : 2
// Copyright   : Free to share
// Description : Static Array, bitset
//============================================================================

#include <iostream>
#include <cstdio>
using namespace std;

int a,i,n;
bool bin[33];

int main() {
	bin[33] = 0;

	while(scanf("%d",&n) != EOF){		// 4 groups of 8 bits(1 byte) for each integer
										// just reverse the group
		a = 0;
		for(i = 0 ; i < 32; i++){
			if(n & (1<<i)){			//if the i-th bit of n is 1
				 a |= 1 << ((3 - (i >> 3)) << 3) + (i % 8);
			}
		}
		printf("%d converts to %d\n",n,a);
	}

	return 0;
}
