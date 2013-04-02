#include <iostream>

using namespace std;

int main (int argc, char * const argv[]) {
  
	int table[500][500];
	
	int v;
	
	string a,b;
	
	while(cin>>a>>b){
		cout << "1st string: "<< a <<endl<< "2ndstring: "<<b<<endl;
	     memset(table, 0, sizeof(table));
		
		for (int y = 1; y <= a.size(); y++) {
			for (int x = 1; x <= b.size(); x++) {
			   cout << table[y-1][x-1]<<" ";
			}
			cout << endl;
		}
		cout<<endl;
	
	     for (int y = 1; y <= a.size(); y++) {
		  for (int x = 1; x <= b.size(); x++) {
			if (a[y-1] == b[x-1]) {
				v = table[y-1][x-1] + 1;
			}
			else{
				v = table[y-1][x-1];
			}
					
			
			if (table[y-1][x] > v) {
				v = table[y-1][x] ;
			}
			if (table[y][x-1]>v) {
				v = table[y][x-1];
			}
			  table[y][x]=v;
			  
			//cout<<"    ";
			for (int p = 1; p <= b.size(); p++) 
				  cout <<b[p-1]<<" ";
			  cout<<endl;
			for (int m = 1; m <= a.size(); m++) {
				//if (m!=1) 
				  cout <<a[m-1]<<" ";
				//else
				  //cout << "   ";
				  for (int n = 1; n <= b.size(); n++) {
					 
					  cout << table[m-1][n-1]<<" ";
				  }
				  cout << endl;
			}
			  cout<<endl;
		  }
		}
			 
		cout << table[a.size()][b.size()]<<endl;
	}
	
		
	
    return 0;
}
