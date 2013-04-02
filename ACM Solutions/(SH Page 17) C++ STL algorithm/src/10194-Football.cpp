//============================================================================
// Name        : 10194-Football.cpp
// Author      : Joseph Murrugarra,Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share
// Description : C++ STL,algorithm
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back
#define all(i) (i).begin(), (i).end(), cmp


struct data
{
    int points;
    int games;
    int win;
    int tie;
    int lost;
    int df;
    int goalsf;
    int goalsc;

};

string toMayus(string s)
{
    unsigned int i=0;
    for(i=0; i<s.size(); ++i)
        s[i] = toupper(s[i]);
    return s;
}

bool cmp(pair<string,data>par1 , pair<string,data>par2)
{
    if(par1.second.points!=par2.second.points)
        return(par1.second.points>par2.second.points);
    if(par1.second.win!=par2.second.win)
        return(par1.second.win>par2.second.win);
    if(par1.second.df!=par2.second.df)
        return(par1.second.df>par2.second.df);
    if(par1.second.goalsf!=par2.second.goalsf)
        return(par1.second.goalsf>par2.second.goalsf);
    if(par1.second.games!=par2.second.games)
        return(par1.second.games!=par2.second.games);
    if(toMayus(par1.first)!=toMayus(par2.first))
        return toMayus(par1.first)<toMayus(par2.first);
    return false;
}

int main()
{
/*
   freopen("input.txt","r",stdin);
*/
    int test,n,g;
    string tournament,cad,cad1;
    scanf("%d\n",&test);
    while(test--)
    {
        map< string,data > football;

        getline(cin,tournament);
        scanf("%d\n",&n);
        while(n--)
        {
            getline(cin,cad);
            football[cad].points=0;
            football[cad].games=0;
            football[cad].win=0;
            football[cad].tie=0;
            football[cad].lost=0;
            football[cad].df=0;
            football[cad].goalsf=0;
            football[cad].goalsc=0;
        }
        scanf("%d\n",&g);
        while(g--)
        {

            int t1,t2,flag=1;
            char a;
            string eq1,eq2;
            while((a=getchar()))
            {
                if(a=='\n')
                    break;
                if(flag==0)
                    eq2+=a;
                else if(a=='#')
                {
                    scanf("%d@%d#",&t1,&t2);
                    flag=0;
                }
                if(flag)
                    eq1+=a;
            }
            //partidos jugados;
            football[eq1].games++;
            football[eq2].games++;
            //goles a favor, goles en contra, dif de goles
            football[eq1].goalsf+=t1;
            football[eq2].goalsf+=t2;

            football[eq1].goalsc+=t2;
            football[eq2].goalsc+=t1;

            football[eq1].df+=(t1-t2);
            football[eq2].df+=(t2-t1);


            //points,wins,lost,ties...
            if(t1>t2)
            {
                football[eq1].win++;
                football[eq2].lost++;
                football[eq1].points+=3;
            }
            else if(t1<t2)
            {
                football[eq2].win++;
                football[eq1].lost++;
                football[eq2].points+=3;
            }
            else
            {
                football[eq1].tie++;
                football[eq2].tie++;
                football[eq1].points++;
                football[eq2].points++;

            }

        }
        printf("%s\n",tournament.c_str());

        int tam=football.size(),i;
        REP(i,tam)
        {
            pair<string,data> res;
            res=*min_element(all(football));
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,res.first.c_str(),res.second.points,res.second.games,res.second.win,res.second.tie,res.second.lost,res.second.df,res.second.goalsf,res.second.goalsc);
            football.erase (res.first);
        }
        if(test)
            printf("\n");

    }
/*
    fclose(stdin);
*/
   return 0;
}

//Wrong answer : Ananda

//#include <iostream>
//#include <vector>
//#include <map>
//#include <set>
//#include <algorithm>
//using namespace std;
//
//#define REP(i,s,e) for(int i = int(s);i <= int(e);i++)
//#define tr(C,it)\
//	for(typeof((C).begin()) it = (C).begin() ; it != (C).end() ;it++)
//#define all(C) (C).begin(),(C).end()
//
//class team{
//public:
//	int ng;			//number of games
//	int w;			//number of wins
//	int t;			//number of ties
//	int l;			//number of losses
//	int gs;			//goal scored
//	int gt;			//goal taken
//	int p;			//points
//	int gd; 		//goal difference
//
//	team(){
//		ng = w = t = l = gs = gt = p = gd = 0;
//	}
//
//};
//
//typedef map<string,team> mst;
//typedef pair<string,team> st;
//typedef set<st>  mset;
//
//class compare{
//	bool operator()(const st& p1,const st& p2)
//	{
//		if((p1.second).p > (p2.second).p)
//			return true;
//		if((p1.second).w > (p2.second).w)
//			return true;
//		if((p1.second).gd > (p2.second).gd)
//			return true;
//		if((p1.second).gs > (p2.second).gs)
//			return true;
//		if((p1.second).ng < (p2.second).ng)
//				return true;
//		return p1.first < p2.first;
//	}
//};
//
//typedef vector<team> vt;
//
//int main() {
//	int N;
//	string nl;
//	cin >> N;
//	getline(cin,nl);//skipping new line
//
//	string Tr;	//Tournament name
//	getline(cin,Tr);
//
//	int T;			//number of teams
//	mst tinf;
//	REP(i,0,N-1){
//
//		cin >> T;
//		getline(cin,nl);	//skipping new line
//
//		tinf.resize(T);	//resizing the teams vector
//
//		REP(j,0,T-1){
//			getline(cin,tinf[j].n);
//			cout << teams[j].n<< endl;
//		}
//
//		int G;	//games
//
//		cin >> G;
//
//		string gs;	//game result string
//		REP(j,0,T-1){
//			getline(cin,gs);
//			int idx = gs.find('#',0);
//			string t1 = gs.substr(0,idx);  //the 1st team
//
//			int ti = find(all(teams),t1) - teams.begin();  //team index in the team vector
//			teams[ti].ng ++;
//			teams[ti].gs += gs[idx + 1];					//goal scored
//			teams[ti].gt += gs[idx + 3];					//goal taken
//			int dif = gs[idx + 1] - gs[idx + 3];			//goal difference
//			teams[ti].gd += dif  ;							//increase by goal diff
//			if(dif > 0){
//				teams[ti].w ++;
//				teams[ti].p += 3;
//			}else if(dif == 0){
//				teams[ti].t ++;
//				teams[ti].p += 1;
//			}else{
//				teams[ti].l ++;
//			}
//
//			string t2 = gs.substr(idx + 5);
//			ti = find(all(teams),t2) - teams.begin();
//			teams[ti].ng ++;
//			teams[ti].gs += gs[idx + 3];
//			teams[ti].gt += gs[idx + 1];
//			dif = gs[idx + 3] - gs[idx + 1] ;
//			teams[ti].gd += dif;
//			if(dif > 0){
//					teams[ti].w ++;
//					teams[ti].p += 3;
//			}else if(dif == 0){
//					teams[ti].t ++;
//					teams[ti].p += 1;
//			}else{
//					teams[ti].l ++;
//			}
//		}
//	}
//	REP(ti,0,T-1){
//		cout << teams[ti].n << endl;
//		cout << teams[ti].ng << endl;
//		cout << teams[ti].gs << endl;
//		cout << teams[ti].gt << endl;
//		cout << teams[ti].gd << endl;
//		cout << teams[ti].w << endl;
//		cout << teams[ti].l << endl;
//		cout << teams[ti].t << endl;
//	}
//
//
//	return 0;
//}
