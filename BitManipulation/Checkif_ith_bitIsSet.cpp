#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// ================ USING LEFT SHIFT ==========================

// if (N & (1<<i)) != 0 -> here i = the bit we need to check 
//      then the bit is SET      
// else it is UN-SET as and operator must give 1 & 1 = 1


int N = 13, i = 1; // check if ith bit is set
// int main() {
//     if (N & (1 << i))
//         cout << "set";
//     else
//         cout << "not set";
//     return 0;
// }


// ================ USING RIGHT SHIFT ==========================

// we bring the check bit to the right most end
// AND it with 1
// if((N>>i)&1) == 1 then SET
// else UN-SET 

// int N = 13, i = 2; // check if ith bit is set
int main() {
    if ((N >>i) & 1)
        cout << "set";
    else
        cout << "not set";
    return 0;
}