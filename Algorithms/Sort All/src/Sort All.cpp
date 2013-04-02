//============================================================================
// Name        : Sort.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Free to share,copy and distribute
// Description : All sorting
//============================================================================

//
//  main.cpp
//  bubble sort
//
//  Created by ananda on 6/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
using namespace std;

template<class T> T getmax(T a , T b){
    T result;
    if (a > b) {
        return a;
    }else {
        return b;
    }
}

int a[10] = {1,34,34,-32,34,7,4,5,3,9};
int n;

void swap(int i,int j){
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}


void reverse(int sx,int ex){
    int tmp = a[sx];
    a[sx] = a[ex];
    a[ex] = tmp;
    if (ex - sx > 1) {
        reverse(sx + 1, ex -1);
    }
}

int sortP(int l,int r,int p){
    while (l < r) {
        while (a[l] < p) {
            l++;
        }
        while (a[r] > p) {
            r --;
        }

        swap(l, r);
    }
    return l = r;
}

void quicksort(int left,int right){
    if (left < right) {
        int pi = rand() % (right - left + 1) + left; // pivot index within left and right index  (random is generating a value from 0 to (right - left), so that max(pi) = right)
        int p = a[pi]; // pivot value

        pi = sortP(left, right, p); //arranging smaller in the left of pivot and bigger in the right of pivot and returning pivot index

        quicksort(left, pi);
        quicksort(pi + 1, right);
    }
}

void merge(int l,int c,int r){
    int b[n]; // buffer
    int bi = 0;

    for (int i = l; i <= c ;i++ ) {//backing up the left partition in the buffer
        b[bi++] = a[i];
    }

    int k ,i ,j ; // k: main array iterator, i: buffer iterator, j: right partition iterator

    for (k = l,i = 0 ,j = c+1; i < bi && j <= r; ) {
        if (a[j] < b[i]) {
            a[k++] = a[j++];
        }else {
            a[k++] = b[i++];
        }
    }

    while (i < bi) {
        a[k++] = b[i++];
    }
//    while (j <= c) {
//        a[k++] = a[j++];
//    }
}

void mergeSort(int left,int right){
    if (left < right) {
        int center = (left + right) / 2;

        mergeSort(left, center);
        mergeSort(center + 1, right);

        merge(left,center,right);
    }
}

void bubblesort(){
    for (int i = 0; i < n - 1; i++) { // fixing the bubble position
        for (int j = n - 1; j > i; j--) {
            if (a[j] > a[j-1] ) {
                    swap(j, j-1);
            }
        }
    }
}



int main()
{
    n = 10;
    cout << getmax<int> (15,10);


    cout << endl;
    return 0;
}


