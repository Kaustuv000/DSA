#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>
#include <cmath>
using namespace std;

// extreme naive approach

// we go from 2 to N, divide by each number 
// now if we find any number which divides N, we check if its prime or not
// then we add it to the answer if its a prime

// bool prime(int i){

// }
// int main(){
// for(int i = 0; i<sqrt(n); i++){
//     if (n%i == 0){
//         if(prime(i)) list.add(i);
//         if (prime(n/i)) list.add(n/i);
//     }
// }
// return list;
// };



// ======== V2 ========

// school method
// int main(){
//     int n = 780;
//     vector<int> list;
//     for (int i = 2; i<=n; i++){
//         if (n%i == 0){
//             list.push_back(i);
//             while (n%i == 0){
//                 n = n/i;
//                 // we are doing this to remove the prime factors from the number
//                 // the number can be divided by 4, but we will divide it by 2 all the time so that it doesnt go to 4
//                 // so that we can get the next prime factor    
//             }
//         }
//     } 
//     // the number of iterations will be same as the number of prime factors
//     for (int val : list) {
//         cout << val << " ";
//     }
//     return 0;

// }

// for a large number the Time complexity still remians O(N) as it will go till the last



// ======== V3 ========

int main(){
    int n = 37;
    vector<int> list;
    for (int i = 2; i<=sqrt(n); i++){
        if (n%i == 0){
            list.push_back(i);
            while (n%i == 0){
                n = n/i;
                // we are doing this to remove the prime factors from the number
                // the number can be divided by 4, but we will divide it by 2 all the time so that it doesnt go to 4
                // so that we can get the next prime factor    
            }
        }
    } 
    if (n!= 1){ 
        list.push_back(n);
    }
    // this is done because if the number is prime then it will be left as it is
    // so we have to add the last number
        
    //this is done because as we are going from 2 to sqrt(n) the last number wont be reached
    // so we have to add the last number 


    for (int val : list) {
        cout << val << " ";
    }
    return 0;

}

// TC -> O(sqrt(n) * logn)
// SC -> O(prime factors) -> only storing result 