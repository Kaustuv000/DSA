#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string res = "";

    if (n == 0) {
        cout << "0" << endl;
        return 0;
    }

    while (n>0){
        if (n%2 == 1){
            res += "1";
        }
        else{
            res += "0";
        }
        n = n/2;
    }
    reverse(res.begin(), res.end());;
    cout << res << endl;
    return 0;
}