//============================================================================
// Name        : constTest.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share,copy and distribute
// Description : This file has clarified some concept of c++ :  operator bool() [boolean classes]
//               const after method,const before method
//============================================================================


#include <iostream>

/****************          ***************/

using namespace std;

typedef int myInteger;



struct A
{
    void goo() {}
};

const A foo() {   // A const foo(){...} is same
	A a = A();
	return a;   // or return A();
}



//
class myclass{
private:
	bool isbool;
	int v;
public:
	operator bool() const{ // operator bool has made this class object to return a boolean value
		return isbool;
	}
	myclass(){
		isbool = true;
		v = 0;
	}
	void setBool(bool _isbool){
		isbool = _isbool;
	}
	int method(){
		v = 3;
		return v;
	}
	string constMethod() const{ // constMethod function is a constant function for constant object of the class
		return "const";
	}
};

int m1(){
	myclass m;
	cout << m.method() << endl;// ok
	cout << m.constMethod() << endl; // m can call a constant function

	const myclass m2;
	cout << m2.constMethod()<< endl;

	A x = foo();
	x.goo();
//	foo().goo(); //error

	myInteger a = 5;
	cout << a << endl;

	myclass m3;
	if(m3){//m3 can be used as boolean
		cout << "true" << endl;
	}else{
		cout << "false" << endl;
	}
	m3.setBool(false);
	cout << "after change" << endl;
	if(m3){//m3 can be used as boolean
			cout << "true" << endl;
		}else{
			cout << "false" << endl;
	}

	return 0;
}
