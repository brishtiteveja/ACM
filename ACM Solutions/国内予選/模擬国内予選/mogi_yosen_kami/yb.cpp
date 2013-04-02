#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct team{
  int np,pe,tn;
  bool operator<(const team &t)const{
    if(np>t.np){
      return true;
    }else if(np==t.np && pe<t.pe){
      return true;
    }else if(np==t.np && pe==t.pe && tn<t.tn){
      return true;
    }else{
      return false;
    }
  }
};

int main(){
  for(int T,P,R;cin>>T>>P>>R,T|P|R;){
    vector<team> tdata;
    int wans[51][11]={{}};
    for(int i=1;i<=T;i++){
      team t={0,0,i};
      tdata.push_back(t);
    }
    while(R--){
      int ti,pi,time;
      string mes;
      cin>>ti>>pi>>time>>mes;
      if(mes=="CORRECT"){
	tdata[ti-1].np++;
	tdata[ti-1].pe+=1200*wans[ti][pi]+time;
      }else{
	wans[ti][pi]++;
      }
    }
    sort(tdata.begin(),tdata.end());
    for(int i=0;i<tdata.size();i++){
      cout<<tdata[i].tn<<' '<<tdata[i].np<<' '<<tdata[i].pe<<endl;
    }
  }
  return 0;
}
