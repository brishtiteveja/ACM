#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  for(int a,b;cin>>a>>b,a!=-1&&b!=-1;){
    int lo,hi;
    lo=min(a,b);
    hi=max(a,b);
    cout<<min(hi-lo,lo+100-hi)<<endl;
  }
  return 0;
}
