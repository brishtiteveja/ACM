//============================================================================
// Name        : Disjoint.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share,copy and distribute
// Description : Disjoint Set
//============================================================================

//
//  main.cpp
//  Disjoint Set
//
//  Created by ananda on 6/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#define size 8

using namespace std;

//Disjoint set (rank by union + path compression)
/*
Let P[x] = the parent of node x.
CREATE-SET(x)
P[x] = x
rank[x] = 0
MERGE-SETS(x, y)
PX = FIND-SET(X)
PY =FIND-SET(Y)
If (rank[PX] > rank[PY]) P[PY] = PX
Else P[PX] = PY
If (rank[PX] == rank[PY]) rank[PY] = rank[PY] + 1
And the last operation looks like:

FIND-SET(x)
If (x != P[x]) p[x] = FIND-SET(P[X])
Return P[X]

 */
int a[size][size]={{}}; //adjacent matrix
int parent[size]={};
int rank[size]={};

void createSet(int u){
    parent[u] = u;
    rank[u] = 0;
}

int findRep(int u){ // find representative function
    if (parent[u] == u) {
        return u;
    }else {
        return parent[u] = findRep(parent[u]);
    }
}

void mergeSet(int u,int v){
    if (u != v) {
        int uR = findRep(u);
        int vR = findRep(v);

        if (rank[uR] > rank[vR] ) {
            parent[v] = uR;
        }else if(rank[vR] > rank[uR]){
            parent[u] = vR;
        }else if(rank[vR] == rank[uR]){
            parent[v] = uR;
            rank[uR] += 1;
        }
    }
}

int main(){

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0;i < size ;i++)
        createSet(i);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (a[i][j] && (findRep(i) != findRep(j))) {
                mergeSet(i,j);
            }
        }

    }
    cout <<endl;
    for (int k = 0; k < size; k++ ) {
        cout << findRep(k) <<" " ;
    }
    cout << endl;
    for (int k = 0; k < size ; k++) {
        cout << rank[k] << " ";
    }
    cout << endl;

}


















