	//============================================================================
	// Name        : 612-DNA.cpp
	// Author      : Dhrubo Abdullah Khan
	// Version     :
	// Copyright   : Your copyright notice
	// Description : Hello World in C++, Ansi-style
	//============================================================================

	#include <iostream>
	#include <map>

	#define FOR(i,n) for(i = 0; i < n ; i++)
	#define R_FOR(i, n) for(i = n-1 ; i >= 0 ; i--)

	using namespace std;

	void swap(int &x,int &y){
		int tmp;
		tmp = x;
		x = y;
		y = tmp;
	}

	int bubbleSort(char **a,int w,int h){
		int i,j;
		int c = 0;

		R_FOR(i,w){
			FOR(j,i){
				if(a[h][j] > a[h][j+1]){
					swap(a[h][j],a[h][j+1]);
					c++;
				}
			}
		}
		return c;
	}

	void bubbleSort(int *a,int n){
		int i,j;

		R_FOR(i,n){
			FOR(j,i){
				if(a[j]>a[j+1])
					swap(a[j],a[j+1]);
			}
		}
	}

	int main() {

		int M,i,j,k,t;
		char **a,**b;

		cin >> M;
		FOR(i,M){
			cin.get();
			int w,h;
			cin >> w >> h;

			a = new char*[h];
			b = new char*[h];

			FOR(j,h){
				a[j] = new char[w];
				b[j] = new char[w];
			}

			FOR(j,h)
				FOR(k,w){
					cin >> a[j][k];
					b[j][k] = a[j][k];		//storing in b
				}

			int o[h];
			map<int,int> m;

			FOR(j,h){
				o[j] = bubbleSort(a,w,j);		//storing the swap value in vector o
				m[o[j]] = j;					//storing the index j for o[j]
			}

			bubbleSort(o,h);					//sorting o[]

			FOR(j,h){
				t = m[o[j]];					//retrieving the index of o[]
				FOR(k,w){
					cout << b[t][k];
				}
				cout << endl;
			}
			cout << endl;
		}

		return 0;
	}
