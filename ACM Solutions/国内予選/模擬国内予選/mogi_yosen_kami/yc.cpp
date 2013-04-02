#include <iostream>
#include <string>
#include <cctype>
#include <stack>

using namespace std;

int main(){
  for(string si;cin>>si,si!="#";){
      int i;
      for(i=0;i<(1<<11);i++){
          string s=si;
          for(int j=0;j<s.size();j++){
              if(s[j]>='a'&&s[j]<='k'){
                  s[j]=(i&(1<<(s[j]-'a')))?'T':'F';
              }
          }
          bool res[2];
          string sb[2];
          sb[0]=s.substr(0,s.find('=',0));
          sb[1]=s.substr(s.find('=',0)+1);
      //      cout<<i<<sb[0]<<endl<<sb[1]<<endl;
          for(int j=0;j<2;j++){
              stack<char> opr;
              stack<char> val;
              string s=sb[j];
              for(int i=0;i<s.size();i++){
                  if(isalpha(s[i])){
                      val.push(s[i]);
                  }else{
                      if(s[i]==')'){
                          while(opr.top()!='('){
                              while(opr.top()=='-'){
                                  bool t=val.top()!='T';
                                  val.pop();
                                  val.push((t)?'T':'F');
                                  opr.pop();
                              }
                              bool a,b;
                              a=val.top()=='T';
                              val.pop();
                              char o=opr.top();
                              opr.pop();
                              while(opr.top()=='-'){
                                  bool t=val.top()!='T';
                                  val.pop();
                                  val.push((t)?'T':'F');
                                  opr.pop();
                              }
                              b=val.top()=='T';
                              val.pop();
                              swap(a,b);
                              switch(o){
                                  case '*':
                                      val.push((a&b)?'T':'F');
                                      break;
                                  case '+':
                                      val.push((a|b)?'T':'F');
                                      break;
                                  case '>':
                                      val.push((!a|b)?'T':'F');
                              }
                          }
                          opr.pop();
	      //	      cout<<opr.size()<<endl;
                      }else{
                          if(s[i]=='-'){
                              if(s[i+1]=='>'){
                                  opr.push('>');
                                  i++;
                              }else{
                                  opr.push('-');
                              }
                          }else{
                              opr.push(s[i]);
                          }
                      }   
                  }
              }
	//	cout<<opr.size()<<endl;
              while(!opr.empty()&&opr.top()=='-'){
                  bool t=val.top()!='T';
                  val.pop();
                  val.push((t)?'T':'F');
                  opr.pop();
              }
              res[j]=val.top()=='T';
          }
      //	cout<<sb[0]<<endl<<sb[1]<<endl;
      //	cout<<res[0]<<endl<<res[1]<<endl;
          if(res[0]!=res[1]){
              break;
          }
      }
    end:
      cout<<((i<(1<<11))?"NO":"YES")<<endl;
    }
    return 0;
}
