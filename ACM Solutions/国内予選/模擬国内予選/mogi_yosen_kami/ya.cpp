#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  for(int N;cin>>N,N;){
    bool know[101][101]={{}};
    for(int i=1;i<=N;i++){
      int M;
      cin>>M;
      for(int j=0;j<M;j++){
	int p;
	cin>>p;
	know[i][p]=true;
      }
    }
    int K;
    cin>>K;
    bool dk[101]={};
    for(int i=0;i<K;i++){
      int l;
      cin>>l;
      for(int j=1;j<=N;j++){
	if(know[j][l]==false){
	  dk[j]=true;
	}
      }
    }
    if(count(dk+1,dk+1+N,false)==1){
      cout<<find(dk+1,dk+1+N,false)-dk<<endl;
    }else{
      cout<<-1<<endl;
    }    
  }
  return 0;
}
