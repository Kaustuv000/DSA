#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string convertToBinary(int n){
    string res = "";

    if (n == 0) {
        return "0";
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
    return res;
}


int convertToDecimal(string bin){
    
    int dec = 0;
    int power =0;
    for (int i = bin.length() - 1; i >= 0; i--) {
        int bit = bin[i] - '0';   
        dec += bit * pow(2, power); 
        power++;
    }

    return dec;
}

int main(){
    int bin;
    cin >> bin;
    string binNum = convertToBinary(bin);
    cout << binNum<< endl;
    string bin2;
    cin >> bin2;
    cout << "converted decimal number is: " <<convertToDecimal(bin2);
    return 0;
}