#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
int main (int argc, char * const argv[]) {
	queue<int> q;
	
	q.push(5);
	
	q.push(4);
	
	q.push(1);
	
	q.push(6);
	
	q.push(2);
	
	q.push(3);
	
	q.push(7);
	
	q.push(9);
	
	q.push(8);
	
	while (!q.empty()) {
		printf("%d ",q.front());
		q.pop();
	}
	printf("\n");
	
	return 0;
	
}
