#include <iostream>
#include <algorithm>

using namespace std;

int win[1001];
int lose[1001];

bool nega(int s,int t){
  if(s<=t)return true;
  if(t>=win[s])return true;
  if(t<=lose[s])return false;
  for(int t2=t;t2;t2--){
    if(nega(s-t2,t2*2)==false){
      win[s]=t2;
      return true;
    }
  }
  lose[s]=t;
  return false;
}

int main(){
  fill_n(win,1001,1<<30);
  for(int n;cin>>n,n;){
    if(nega(n,n-1)){
      cout<<"Alicia"<<endl;
    }else{
      cout<<"Roberto"<<endl;
    }
  }
  return 0;
}
