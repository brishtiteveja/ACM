//============================================================================
// Name        : 10258-Contest.cpp
// Author      : Ajmarin, Dhrubo Abdullah Khan
// Version     : 2
// Copyright   : Free to share
// Description : C++ STL,algorithm,Multi-field sorting,sorting,
//============================================================================

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int NC = 100,NP = 10;//Number of contestants,Number of Players
char line[1024];

struct player{
	int penalty[NP],solved[NP];				//penalty vector for problems,solved flag for problems
	int n,ps,submissions,tp;				//index of the player,total number of solved problems, submissions & total penalty of the player
	void clear(int num){
		n = num;							//index of the player
		ps = submissions = tp = 0;			//number of solved problems, submissions,penalty time initialization
		for(int i = 0; i < NP; ++i){
			solved[i] = penalty[i] = 0;		//initializing
		}
	}
	bool operator<(const player p) const{		//operator< overload for
		return ps > p.ps || (ps == p.ps && tp < p.tp) \
				|| (ps == p.ps && tp == p.tp && n < p.n);
	}
}p[100];

int main() {
	int player,problem,time;
	char verdict[16];
	int t;
	cin.getline(line,1024);
	sscanf(line,"%d",&t);				//test case
	cin.getline(line,1024);

	while(t--){
		for(int i = 0;i < NC;++i)
			p[i].clear(i);
		while(cin.getline(line,1024) && line[0]){
			sscanf(line,"%d %d %d %s",&player,&problem,&time,verdict);
			--player;				//decreased player index
			--problem;				//decreased problem index
			if(*verdict == 'C' && !p[player].solved[problem]){//if correct and the problem not yet solved by the player
				p[player].solved[problem] = 1;		//mark the problem for the player as solved
				p[player].ps++;						//increase the number of solved problem
				p[player].tp += time + p[player].penalty[problem];	//total penalty time
			}else if(*verdict == 'I' && !p[player].solved[problem]){
				p[player].penalty[problem] += 20;					//penalty of 20 for each incorrect solution for the problem
			}
			++p[problem].submissions;				//number of submissions
		}
		sort(p,p+NC);
		for(int i = 0;i < NC;++i){
			if(p[i].submissions){
				printf("%d %d %d\n",p[i].n + 1, p[i].ps,p[i].tp);
			}
		}
		if(t)
			printf("\n");
	}

	return 0;
}

/*
 *
 *
 * #include <algorithm>
#include <cstdio>
using namespace std;
const int NC = 100, NP = 10;
char line[1024];
struct player {
    int penalty[NP], solved[NP];
    int n, ps, submissions, tp;
    void clear(int num){
        n = num;
        ps = submissions = tp = 0;
        for(int i = 0; i < NP; ++i) solved[i] = penalty[i] = 0;
    }
    bool operator<(const player p) const {
        return ps > p.ps || (ps == p.ps && tp < p.tp) || (ps == p.ps && tp == p.tp && n < p.n);
    }
} p[100];
int main(void){
    int player, problem, time;
    char verdict[16];
    int t;
    gets(line);
    sscanf(line, "%d", &t);
    gets(line);
    while(t--){
        for(int i = 0; i < NC; ++i) p[i].clear(i);
        while(gets(line) && line[0]){
            sscanf(line, "%d %d %d %s", &player, &problem, &time, verdict);
            --player; --problem;
            if(*verdict == 'C' && !p[player].solved[problem]){
                p[player].solved[problem] = 1;
                p[player].ps++;
                p[player].tp += time + p[player].penalty[problem];
            } else if(*verdict == 'I' && !p[player].solved[problem])
                p[player].penalty[problem] += 20;
            ++p[player].submissions;
        }
        sort(p, p + NC);
        for(int i = 0; i < NC; ++i) if(p[i].submissions)
            printf("%d %d %d\n", p[i].n + 1, p[i].ps, p[i].tp);
        if(t) puts("");
    }
    return 0;
}
 */
 */
