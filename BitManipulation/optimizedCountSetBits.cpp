#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// we will be using AND operator 

int countSetBitsV1(int n){
    int cnt = 0;
    while (n > 1){
        cnt += n&1; // if the last bit is 1, then we add 1 to the count
        n = n>>1;   // right shift the number by 1 bit to check the next bit
    }               // similar to dividing by 2

    if (n==1){ // to count the last bit
        cnt++;
    }
    return cnt;
}


int countSetBitsV2(int m){
    int cnt = 0;
    while (m != 0){
        m = m & (m-1);
        // this will remove the last set bit from m
        // for example, 13 = 1 1 0 1
        // 12 = 1 1 0 0 
        // 12 & 11 = 1 1 0 0
        // 12 & 10 = 1 0 0 0    
        cnt++;
        // so we will get 3 set bits in 13
        // 1 1 0 1 = 3 set bits
        // 1 0 0 0 = 1 set bit
        // 0 0 0 0 = 0 set bits
        // so we will get 3 set bits in 13

    }
    return cnt; // TC = O(k) where k is the number of set bits in the number
}



int main(){
    int N1 = 16;
    int N2 = 13;
    cout << "Number of set bits in " << N1 << " is: " << countSetBitsV1(N1) << endl;
    cout << "Number of set bits in " << N2 << " is: " << countSetBitsV2(N2) << endl;
    return 0;
}


