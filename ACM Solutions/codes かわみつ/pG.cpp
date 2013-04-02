#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  int T;
  cin>>T;
  while(T--){
    string s;
    cin>>s;
    string temp,maxs;
    int head=0;
    for(int i=s.size();i>=0;i--){
      if(s[i]!=s[head]){
	if(temp.size()>maxs.size()){
	  maxs=temp;
	}
	head=0;
	temp=string();
      }
      if(s[i]==s[head]){
	head++;
	temp+=s[i];
      }
    }
    if(temp.size()>maxs.size()){
      maxs=temp;
    }
    reverse(maxs.begin(),maxs.end());
    cout<<maxs<<endl;
  }
  return 0;
}
