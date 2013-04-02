//============================================================================
// Name        : 482- Permutation Arrays.cpp
// Author      : Ajmarin
// Version     : 1
// Copyright   : Free to share
// Description : Static Array
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 104876 		//N = 2^20

using namespace std;

int p[N];
char line[N],*v[N];

int main() {
	int T;
	scanf("%d",&T);										//test case
	for(char c = getchar(); c!= 10; c = getchar());		//Taking the newline
	for(int c = 0; c < T;c++){							//For each case
		int i = 0;
		char *ptr;


		cin.getline(line,N);
		cin.getline(line,N);

		if(c) puts("");
		for(ptr = strtok(line," "),i = 0; ptr != NULL; ptr = strtok(NULL," ")){
			p[i++] = atoi(ptr) - 1;
		}
		cin.getline(line,N);
		for(ptr=strtok(line," "),i = 0; ptr != NULL; ptr = strtok(NULL," ")){
			v[p[i++]] = ptr;
		}

		for(int j = 0; j < i ; j++)
			printf("%s\n",v[j]);
	}

	return 0;
}

















