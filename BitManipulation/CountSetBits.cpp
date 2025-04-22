#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string convToBinary(int n){
    string bin;
    while (n > 0){
        bin += (n % 2) + '0';
        n /= 2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

int main(){
    int N = 16;
    string res = convToBinary(N);
    cout << "Binary representation of " << N << " is: " << res << endl;
    int cnt = 0;
    for (char& c: res){
        if (c == '1'){
            cnt++;
        }
    }
    cout << "There are " << cnt << " number of set bits in " << N << endl;
    return 0;
}