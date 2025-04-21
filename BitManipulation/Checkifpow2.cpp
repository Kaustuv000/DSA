#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// to check if the number is power of 2 or not we need to see
// if there is only 1 set bit or not
// we can use AND operator to set all others that one particular bit as 0

// 1 0 0 0 (N)   <- 16
// 0 1 1 1 (N-1) <- 15
// here res = 0, so 16 is a power of 2
// if res != 0, then not a power of 2

// for example, 
// 13 = 1 1 0 1 (not a power of 2)
// 12 = 1 1 0 0 ( if we AND 12 with 13, we dont get 0)
// so 13 is not a power of 2

int n = 64;
int main(){
    if (n & (n-1) == 0){
        cout << n << " is a power of 2" << endl;
    } 
    else {
        cout << n << " is not a power of 2" << endl;
    }
    return 0;
}
