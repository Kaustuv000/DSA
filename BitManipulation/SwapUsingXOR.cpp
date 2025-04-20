#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int a = 5, b = 6;
int main(){
    cout << "Before swapping: a = " << a << ", b = " << b << endl;
    a = a ^ b; 
    b = a ^ b; // here a^b^b happens so it gives a
    a = a ^ b; // here a^b^a as b is now a, so it gives b
    cout << "After swapping: a = " << a << ", b = " << b << endl;
    return 0;
}