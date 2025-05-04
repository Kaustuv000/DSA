#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// ======= USING BRUTE FORCE =======
// int main(){
//     int n = 780;
//     vector <int> list;
//     for (int i = 1; i<n; i++){
//         if (n%i == 0){
//             list.push_back(i);
//         }
//     }

//     for(int val : list) {
//         cout << val << " ";
//     }

//     return 0;
// }

// ========== V2 ===================

// we can convert the above code to O(sqrt(N)) by using the fact that if a number is divisible by i, then it is also divisible by n/i

// // so we can go from 1 to sqrt(N) and check if the number is divisible by i, if it is then we can add both i and n/i to the list

int main(){
    int n = 780;
    vector <int> list;
    for (int i = 1; i<=sqrt(n); i++){
//  for (int i =1; i*i<n; i++) -> can be done by this way as well , by not using the stl sqrt function
        if (n%i == 0){
            list.push_back(i);
            if (i != n/i){ 
// this is done to avoid adding the same number twice
                list.push_back(n/i);
            }
        }
    }
}
    