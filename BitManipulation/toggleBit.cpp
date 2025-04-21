#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;


// to toggle a bit we need to use XOR operator
// to remember XOR
// even number of 1's -> given even -> 0
// odd number of 1's -> gives odd -> 1

int n = 13;
int i = 1;
int main(){

    int mask = 1<<i;
    int ans = n^mask;
    cout << ans << endl;

    return 0;
}