#include <iostream>

using namespace std;

int main () {
    
	unsigned int takeout;
	float acBalance;
	
	cin>>takeout>>acBalance;
	
	if (takeout % 5 == 0 && takeout + 0.50 <= acBalance) {
		printf("%.2f\n",acBalance - takeout - 0.50);
	}
	else {
		printf("%.2f\n",acBalance);
	}

	
    return 0;
}
