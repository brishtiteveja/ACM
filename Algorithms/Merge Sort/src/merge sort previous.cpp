//
//  main.cpp
//  merge sort
//
//  Created by ananda on 5/17/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#define min(a,b) (a<b ? a : b)

using namespace std;
int buffer2[15];

void merge2(int a[],int left,int center,int right)
{
    int buffIndex = 0;
    
    for (int i = left; i <= center; i++) {
        buffer2[buffIndex++] = a[i];
    }
    
    int k = left ,b, i;
    
    for (b = 0 , i = center + 1 ; b < buffIndex && i <=right; ) {
        if (a[i] < buffer2[b]) {
            a[k++] = a[i++];
        }else {
            a[k++] = buffer2[b++];
        }
    }
    
    while (b < buffIndex) {
        a[k++] = buffer2[b++];
    }
    while (i <= right) {
        a[k++] = a[i++];
    }
}
void mergeSort2(int a[],int left,int right){
    if (left < right) {
        int center;
        center = (left + right) / 2;
        
        //partition
        mergeSort2(a, left, center);
        mergeSort2(a, center + 1 , right);
        
        //merge
        merge2(a,left,center,right);
    }
    
}

int main2(int argc, const char * argv[])
{
    int a[15] = {4,5,-11,7,12,1,2,-6,9,-8,3,15,14,13,10};
   
    mergeSort2(a,0,14);
    
    for (int i = 0; i < 15; i++) {
        cout << a[i] << endl;
    }
    
    return 0;
}

