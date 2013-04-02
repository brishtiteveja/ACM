#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int main(){
  vector<int> prime;
  for(int i=2;i*i<=1000000000;i++){
    vector<int>::iterator it;
    for(it=prime.begin();it!=prime.end();it++){
      if(i%*it==0)break;
    }
    if(it==prime.end()){
      prime.push_back(i);
    }
  }
  for(int a,b;cin>>a>>b,a|b;){
    int diff=abs(a-b);
    int cnt=1;
    for(int i=0;i<prime.size()&&diff!=1;i++){
      int j=0;
      while(diff%prime[i]==0){
	j++;
	diff/=prime[i];
      }
      cnt*=(j+1);
    }
    cnt*=(diff!=1)+1;
    cout<<cnt<<endl;
  }
  return 0;
}
