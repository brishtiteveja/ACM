//============================================================================
// Name        : 336-A Node Too Far.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share
// Description : Hello World in C++, Ansi-style
//============================================================================

//16
//10 15   15 20   20 25   10 30   30 47   47 50   25 45   45 65
//15 35   35 55   20 40   50 55   35 40   55 60   40 60   60 65
//35  2   35  3    0  0
//
//14
//1 2   2 7   1 3   3 4   3 5   5 10   5 11
//4 6   7 6   7 8   7 9   8 9   8  6   6 11
//1 1   1 2   3 2   3 3   0 0
//
//0

#include <iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#define tr(c, it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
using namespace std;
unsigned int a,b,cnum,cttl,current,i,ida,idb,n,s,t,ttl,visited;
vector< vector<int> > adj(50);
bool v[50];
map <int, int> m;
typedef pair<int,int> ii;
queue< ii >q;



void bfs(){
    while(!q.empty()){
        current = q.front().first;
        cttl = q.front().second;
        q.pop();
        if(cttl)
            tr(adj[current], it)
                if(!v[(*it)]){
                    v[(*it)] = 1;
                    visited++;
                    q.push( ii((*it),cttl-1));
                }
    }
    printf("Case %u: %u nodes not reachable from node %u with TTL = %u.\n",
        ++cnum,n-visited,s,ttl);
}
int main(void){
    while(cin >> t && t){
        for(i = 0; i < n; i++)adj[i].clear();
        m.clear();
        for(n = i = 0; i < t; i++){
            cin >> a >> b;
            if(m.count(a) == 0) m[a] = n++;
            if(m.count(b) == 0) m[b] = n++;
            ida = m[a];
            idb = m[b];
            adj[ida].push_back(idb);
            adj[idb].push_back(ida);
        }
        while(cin >> s >> ttl && s){
                q.push( ii(m[s],ttl));
                memset(v,0,n);
                v[m[s]] = visited = 1;
                bfs();
        }
    }
}
