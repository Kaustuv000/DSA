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

/*************  ✨ Windsurf Command ⭐  *************/
/**
 * @brief The main function of the program, which will be called when program
 *        execution begins. This function will get two integers from the user, 
 *        convert the first one to binary, display the binary number, convert the
 *        second binary number to decimal and display the converted decimal number.
 * @return 0 if the program runs successfully.
 */
/*******  cb7b843b-99fa-4751-abf8-ceb70680a63c  *******/
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