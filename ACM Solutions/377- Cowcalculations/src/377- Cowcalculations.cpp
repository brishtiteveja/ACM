////============================================================================
//// Name        : 377-Cowcalculations.cpp
//// Author      : Dhrubo Abdullah Khan
//// Version     :
//// Copyright   : Free to share
//// Description : UVA 377
//// Category	   : Ad Hoc,Mathematics(base 4 calculations)
////============================================================================
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
	return 0;
}

//
//#define pb push_back
//
//typedef pair<char,char> cc;				// pair for result and carry
//typedef vector<cc> vcc;
//typedef vector<vcc> vvcc;
//typedef map<cc,char> mccc;
//
//map<cc,char> res;
//map<cc,char> carry;
//
//void makeChart(){
//		//first row
//		res[cc('V','V')] = 'V';
//		carry[cc('V','V')] = 'X';
//		res[cc('V','U')] = 'U';
//		carry[cc('V','U')] = 'X';
//		res[cc('V','C')] = 'C';
//		carry[cc('V','C')] = 'X';
//		res[cc('V','D')] = 'D';
//		carry[cc('V','D')] = 'X';
//
//
//		//second row
//		res[cc('U','V')] = 'U';
//		carry[cc('U','V')] = 'X';
//		res[cc('U','U')] = 'C';
//		carry[cc('U','U')] = 'X';
//		res[cc('U','C')] = 'D';
//		carry[cc('U','C')] = 'X';
//		res[cc('U','D')] = 'V';
//		carry[cc('U','D')] = 'U';
//
//		//third row
//		res[cc('C','V')] = 'C';
//		carry[cc('C','V')] = 'X';
//		res[cc('C','U')] = 'D';
//		carry[cc('C','U')] = 'X';
//		res[cc('C','C')] = 'V';
//		carry[cc('C','C')] = 'U';
//		res[cc('C','D')] = 'U';
//		carry[cc('C','D')] = 'U';
//
//		//first row
//		res[cc('D','V')] = 'D';
//		carry[cc('D','V')] = 'X';
//		res[cc('D','U')] = 'V';
//		carry[cc('D','U')] = 'U';
//		res[cc('D','C')] = 'U';
//		carry[cc('D','C')] = 'U';
//		res[cc('D','D')] = 'C';
//		carry[cc('D','D')] = 'U';
//}
//
//string addition(string& n1,string& n2){
//	int i;
//	string r;
//	char c = 'X';
//	int k = 0;
//	cc p;				//pair of chars
//	for(i = 0; n2[i] != '\0' ; i++){
//		r[k] = n2[i];
//		while(c != 'X'){
//			p = cc(r[k],c);
//			r[k] = res[p];
//			c = carry[p];
//		}
//		p = cc(r[k],n1[i]);
//		r[k++] = res[p];
//		c = carry[p];
//	}
//
//	return res;
//}
//
//string rightShift(string& n2){
//
//	return n2;
//}
//
//string leftShift(string& n2){
//
//	return n2;
//}
//
//
//int main() {
//	makeChart(res,carry);
//
//	int n;
//
//	cin >> n;
//
//	cout << "COWCULATIONS OUTPUT" << endl;
//	for(int i = 1 ;i <= n; i++){
//		string num1,num2,fres;
//		cin >> num1 >> num2;
//		char op[5];
//		for(int o = 1 ; o <= 4 ; o++){
//			cin >> op[o];
//			if(op[o] == 'A'){
//				num2 = addition(num1,num2);
//			}else if(op[o] == 'R'){
//				num2 = rightShift(num2);
//			}else if(op[o] == 'L'){
//				num2 = leftShift(num2);
//			}else{
//
//			}
//		}
//		cin >> fres;
//
//		if(num2 == fres){
//			cout << "YES" << endl;
//		}else{
//			cout << "NO" << endl;
//		}
//
//	}
//	cout << "END OF OUTPUT" << endl;
//
//
//
//	return 0;
//}


