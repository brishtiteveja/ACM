#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

list<int> l;
list<int>::iterator i;

void print(){
	    
		for (i = l.begin() ; i != l.end() ; i++ ) {
			printf("%d ",*i);
			printf("\n");
		}
	    printf("hello\n");
}

int main () {
   
	l.push_back(3);
	l.push_back(5);
	l.push_back(1);
	l.push_back(2);
	l.push_back(8);
	l.push_back(9);
	l.push_back(10);
	l.push_back(1);
	
	print();

	
	l.sort();
	print();
	
	l.remove(4);
	print();
	
	l.unique();
	print();
	
	l.resize(5);
	print();
	
	i = l.begin();
	i++;
	l.insert(i,1,10);
	print();
	
    return 0;
}
