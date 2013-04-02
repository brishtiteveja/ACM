//============================================================================
// Name        : string Concepts.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share,copy and distribute
// Description : This file has clarified some concept of c++ :string

//============================================================================


#include <iostream>
#include <algorithm>
#include <vector>
#include <boost/regex.hpp> //regular expression header of boost library

using namespace std;
using namespace boost;

#define FOR(i,N) for(i = 0 ; i < N; i++)
#define RFOR(i,N) for(i = N-1 ; i >= 0 ; i--)
#define tr(C,it)\
	for(typeof((C).begin()) it = (C).begin(); it != (C).end(); it++) //traverse the container C with the iterator it

template<class T>
void showC(const T& C){
	tr(C,it){
		cout << *it << " " ;
	}
	cout << endl;
}

void input(const string& s){
	istringstream is(s);

	// creating a vector of integers from a input string
	vector<char> v;
	char tmp;
	while(is >> tmp){
		v.push_back(tmp);
	}
}

string f(const vector<int>& v) {

     // Constucvt an object to do formatted output
     ostringstream os;

     // Copy all elements from vector<int> to string stream as text
     tr(v, it) {
          os << ' ' << *it;
     }

     // Get string from string stream
     string s = os.str();

     // Remove first space character
     if(!s.empty()) { // Beware of empty string here
          s = s.substr(1);
     }

     return s;
}

int main(){
	int data[5] = {4,6,8,3,10};
	vector<int> v(data,data + sizeof(data)/sizeof(data[0]));
	showC(v);

	//char*  and char arraya
	char *s3 = "borno";
	char s4[5] = {'s','y','u','m'};
	int i;

	string ss5 = string(s3);
	cout << "inset a string:" << endl;
	getline(cin,ss5);
	cout << ss5 << endl;

	cout << "insert another string" << endl;
	char ss6[20];
	cin.getline(ss6,256);
	ss5 = string(ss6);
	cout << ss5 << endl;

	FOR(i,5){
		cout << s3[i] << " ";
	}
	cout << endl;
	FOR(i,5){
		cout << s4[i] << " ";
	}
	cout << endl;

	//string class
	string ss = "ananda loves brishti";
	string ss2;
	//cout << "Plz input a string: ";
	//getline(cin,ss2);
	//cout << s2 << endl;

	ss2 = string(s3);
	cout << ss2 << endl;
	cout <<"size = "<< ss2.size() << endl;
	cout << "inserting a from ss2[0]~ss[3]" << endl;
	ss2.insert(0,4,'a');
	cout << ss2 << endl;

	string ss3 = ss2.substr(2,4);
	cout << ss3 << endl;

	string st = "ananda loves brishti";

	string pattern = "love";
	int pos = st.rfind("love");
	string subst = st.substr(pos,pattern.length());
	cout << "substring = " << subst << endl;

	string r = "loves";
	st.replace(7,5,"likes");

	cout << st << endl;
//	int posdoc = doc.rfind()

	string line ="D009 Several";

	//need to include libboost_regex.a static library
	boost::match_results<string::const_iterator > matches;

	boost::regex pat("(D[0-9]*)\\s(\\S*)",regex::perl); // perl pattern matching
	if(boost::regex_match(line,matches,pat)){
		cout << matches[1] << " " << matches[2] <<endl;
	}

	string pat1 = "Several";
	int pos1 = line.rfind(pat1);   // searching from backword
	cout << "position of D: " << pos1 << endl;

	string patn = " ";
	int posn = line.find(patn);
	string first = line.substr(0,posn - 0);  //startposition and length = posn - 0
	string second = line.substr(posn + 1,line.length() - (posn + 1)); // startposition and length = line.length() - (posn+1)
	cout << first <<  " " << second << endl;



	return 0;
}
