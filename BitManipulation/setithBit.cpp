#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n = 13; // 1 1 0 1
int i = 1;
// OR operator gives: 1 if either of the bits is 1
// only gives zero if both bits are zero

int main(){
    int mask = 1<<i;
    int ans = n|mask; // 1 1 1 1
    cout << ans << endl; // 15

    return 0;
}