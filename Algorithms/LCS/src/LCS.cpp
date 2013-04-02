//============================================================================
// Name        : LCS.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share,copy and distribute
// Description : Hello World in C++, Ansi-style
//============================================================================

//
//  main.cpp
//  Longest Common Subsequence
//
//  Created by ananda on 6/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string.h>
#define MAX 100

using namespace std;

char X[MAX],Y[MAX];
int i,j,m,n,c[MAX][MAX],b[MAX][MAX];
string out;

int LCSlength(){
    m = strlen(X);
    n = strlen(Y);

    for (i = 1; i <= m; i++) {
        c[i][0] = 0;
    }
    for (j = 0; j <= n; j++) {
        c[0][j] = 0;
    }


    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i > 0 && j > 0) {
                if (X[i-1] == Y[j-1]) {
                    c[i][j] = c[i-1][j-1] + 1;
                    b[i][j] = 1;
                }
                else if(c[i-1][j] > c[i][j-1]){
                    c[i][j] = c[i-1][j];
                    b[i][j] = 2;
                }else {
                    c[i][j] = c[i][j-1];
                    b[i][j] = 3;
                }
            }

           // cout << c[i][j] <<" ";
        }
        cout << endl;
    }
    return c[m][n];
}

void printLCS(int i,int j){
    if (i == 0 || j == 0) {
        return;
    }

    if (b[i][j] == 1) {
        printLCS(i-1, j-1);
        printf("%c",X[i-1]);
    }
    else if(b[i][j] == 2){
        printLCS(i-1, j);
    }else {
        printLCS(i, j-1);
    }
}

int main(int argc, const char * argv[])
{
    while (1) {
        gets(X);
        if (feof(stdin)) {
            break;
        }
        gets(Y);
        printf("LCS length -> %d\n",LCSlength());//count length
        printLCS(m,n);
        printf("\n");
    }

    return 0;
}

