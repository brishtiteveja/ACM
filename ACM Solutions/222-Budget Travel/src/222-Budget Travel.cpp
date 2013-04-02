//============================================================================
// Name        : 222-Budget.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long
#define MX 100000
#define MOD 1000000007


struct Z{
    double dst; //distance from previous station to present station
    double prc; //price
};

vector<Z>stn;   //stations
double t_dst,c,spd,price,progress; //t_dst=total distance, c=capacity, spd= miles/gasoline, price=starting station price
int n;

void take_input()
{
    stn.clear();
    Z z;

    cin>>c>>spd>>price>>n;
    cin>>z.dst>>z.prc;
    progress=z.dst;
    stn.PB(z);
    int now=0;

    for(int i=1;i<n;i++)
    {
        cin>>z.dst>>z.prc;
        if(z.dst==stn[now].dst && z.prc<stn[now].prc) //if same distance, consider the one with less price
            stn[now].prc=z.prc;
        else
        {
            z.dst-=progress;
            stn.PB(z);
            progress+=z.dst;
            now++;
        }
    }
}


double func(int pos, double rem)
{
    if(pos>=n-1)                            //last station
    {
        if((t_dst-progress)/spd<=rem)       //without buying
            return 0.0;
        else
            return 200.0+stn[pos].prc*(c-rem);          //need to buy
    }

    double ret;
    if(rem>(c/2.0) && (stn[pos+1].dst/spd)<=rem)        //remaining gasoline and possible to go next station
            ret=func(pos+1, rem - stn[pos+1].dst/spd);

    else if(rem < (stn[pos+1].dst/spd))                 //can't go without buy
        ret=200.0+stn[pos].prc*(c-rem)+ func(pos+1, c - stn[pos+1].dst/spd);

    else
    {
        double x= 200.0+stn[pos].prc*(c-rem)+ func(pos+1, c-stn[pos+1].dst/spd); //buy gasoline
        double y=func(pos+1, rem-stn[pos+1].dst/spd);                  //dont buy
        ret=min(x,y);
    }

return ret;
}


int main()
{
    int kk=1;
    while(cin>>t_dst && t_dst>=0)
    {
        take_input();
        n=stn.size();

        double res=price*100;
        res+=func(0,c-(stn[0].dst/spd));
        //cout<<res/100<<endl<<endl;
        cout<<"Data Set #"<<kk++<<endl<<"minimum cost = $"<<setprecision(2)<<fixed<<res/100.0<<endl;
    }
return 0;
}
