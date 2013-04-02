#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    
	vector<int> v;
	
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(7);
	v.push_back(6);
	v.push_back(5);
	v.push_back(4);
	v.push_back(8);
	
	vector<int>:: iterator i;
	
	printf("Unsorted version\n");
	
	for (i=v.begin(); i!=v.end(); i++) {
		printf("%d ",*i);
		printf("\n");
	}
	
	sort(v.begin(), v.end());
	
	printf("Sorted version\n");

	for (i = v.begin(); i != v.end(); i++) {
		printf("%d ",*i);
		printf("\n");
	}
	
	return 0;
}
