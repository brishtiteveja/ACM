#include <iostream>

using namespace std;

int main (int argc, char * const argv[]) {
    uint32_t n,i;
	n = 1024 - 1 ;
	
	for (i = 0;; ++i,n >>= 1) {
		cout << n << endl;
		if (!n) {
			break;
		}
	}
	
	cout << i << endl;
}
