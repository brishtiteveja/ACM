#include <iostream>
#include <stack>

using namespace std;

int main () {
	stack<int> s;
	
	s.push(10);
	s.push(9);
	s.push(7);
	s.push(6);
    s.push(8);
	s.push(3);
    s.push(4);
	s.push(5);
	
	while (!s.empty()) {
		printf("%d ",s.top());
		s.pop();
	}
	printf("\n");
	
    return 0;
}
