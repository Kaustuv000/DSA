#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>
#include <limits.h> // for INT_MAX and INT_MIN
#include <cmath> // for abs function

using namespace std;

int divide(int m, int n) {
    if (m == n) return 1;
    
    int sign = ((m < 0) ^ (n < 0)) ? -1 : 1; // handling negative number

    long long a = abs((long long)m);
    long long b = abs((long long)n);
    long long ans = 0;

    while (a >= b) {
        int cnt = 0;
        while (a >= (b << (cnt + 1))) cnt++;    // Finding the largest power of 2 (2^cnt) such that b * (2^cnt) is still less than or equal to a.
        a -= (b << cnt);                       //b << (cnt + 1) is equivalent to b * 2^(cnt+1)
        ans += (1 << cnt);                   // Subtract b * 2^cnt from a
        
    }

    if (sign == -1) ans = -ans;

    // Handling overflow cases
    if (ans == 1<<31 && sign) return INT_MAX;
    if (ans == 1<<31 && !sign) return INT_MIN;

    return (int)ans;
};