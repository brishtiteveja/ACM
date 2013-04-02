//============================================================================
// Name        : 154-Recycling.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : Complete Search
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define REP(i,s,e) for(int i = int(s); i <= int(e) ; i++)
#define REPI(i,e) REP(i,0,e)
#define N 100

int city[N][5];	//city data
int cId = 0;		//city id

int colorToVal(char c){
	if(c == 'r'){
		return 0;
	}else if(c == 'o'){
		return 1;
	}else if(c == 'y'){
		return 2;
	}else if(c ==  'g'){
		return 3;
	}else{
		return 4;
	}
}

void assign(char c,char m){
	int k;
	if(m == 'P'){
		k = 0;
	}else if(m == 'G'){
		k = 1;
	}else if(m == 'A'){
		k = 2;
	}else if(m == 'S'){
		k = 3;
	}else{
		k = 4;
	}
	city[cId][colorToVal(c)] = k;
}

int main() {
	char line[20];

	while(scanf("%s",line) == 1){
		if(line[0] == '#'){
			break;
		}


		if(line[0] == 'e'){
			if(cId == 1){
				printf("1\n");
			}

			int min = 1000;
			int sum = 0;
			int ans = 0;
			REP(i,0,cId-1){
				sum = 0;
				REP(j,0,cId-1){
					if(i == j)
						continue;
					REP(k,0,5){
						if(city[i][k] != city[j][k]){  // comparing i with all other cities
							sum++;
						}
					}
				}
				if(sum < min){
						min = sum;
						ans = i;
				}
			}

			printf("%d\n",ans + 1);

			cId = 0;
		}else{
			char* ptr;
			ptr = strtok(line,",");

			while(ptr != NULL){
				assign(ptr[0],ptr[2]);
				ptr = strtok(NULL,",");
			}

			cId++;
		}

	}

	return 0;
}
