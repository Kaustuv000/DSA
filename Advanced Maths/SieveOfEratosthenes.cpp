#include <iostream>
#include <bits/stdc++.h>
#include <cmath>    

using namespace std;

// ======== V1 ========
// bool isPrime(int n) {
//     if (n <= 1) return false;       // 0 and 1 are not prime
//     if (n == 2) return true;        // 2 is prime
//     if (n % 2 == 0) return false;   // Even numbers > 2 are not prime

//     for (int i = 3; i <= sqrt(n); i += 2) {
//         if (n % i == 0) return false;
//     }
//     return true;
// }


// int main(){
//     int n = 37;
//     for (int i = 0; i<=n; i++){
//         if (isPrime(i)){
//             cout << i << " ";
//         }
//     }
//     return 0;
// }



// ======== V2 ========
// // Sieve of Eratosthenes


int main(){
    int n = 37;
    int prime[n+1];
    for (int i = 2; i <= n; i++){
        prime[i] = 1; // Assume all numbers are prime initially
    }

    for(int i = 2; i * i <= n; i++){
        if (prime[i]==1){
            for (int j = i * i; j <= n; j += i){
                prime[j] = 0; // Mark multiples of i as non-prime
            }
        }
    }

    for (int i = 2; i <= n; i++){
        if (prime[i] == 1){
            cout << i << " ";
        }
    }
    return 0;
}

// TC = O(N) + O(N log log N) + O(N)
// SC = O(N)   