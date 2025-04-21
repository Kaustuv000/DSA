#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// we need to pad with 1's and the ith bit will be 0 only
int n = 13; // 1 1 0 1
int i = 2;
int main(){
    int mask = ~(1<<i); // by using negation operation 0 1 0 0 -> 1 0 1 1
    int ans = n & mask; // 1 0 0 1
    cout<< ans << endl;
    return 0;
}