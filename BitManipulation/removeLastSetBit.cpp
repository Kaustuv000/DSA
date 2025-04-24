#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// to remove last set bit we need to use AND operator
// to remember AND -> ' bit1 * bit2 '
// we need to AND n with n-1
//       #          <- last set bit here
// 16 -> 1 0 0 0 0
// 15 -> 0 1 1 1 1
// 16 & 15 = 0 0 0 0 0   <- last set bit removed

//                        #   <- last set bit here
int n = 15; // 15 = 1 1 1 1
int main(){
    int ans = n & (n-1);
    cout << ans << endl; // 1 1 1 0
    return 0;
}