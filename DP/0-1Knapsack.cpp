// Variations:

// 1. subset sum
// 2. equal sum partition
// 3. count of subset sum
// 4. minimum subsuet sum difference
// 5. target sum
// 6. Number of subset sum with given difference



// *************************************

// WHAT IS KNAPSACK PROBLEM?

// 1. Fractional knapsack -> greedy problem

// 2. 0-1 knapsack -> dynamic programming problem

// 3. Unbounded knapsack -> dynamic programming problem

// *************************************



// How to identify?

// weight , value, capacity
// o/p : max profit

// either it will ask about the choice or the maximum profit
// if it asks about the choice then it is 0-1 knapsack

// now we write a recursive solution for 0-1 knapsack problem

// DP = recursion + memoization + storage

// make a choice diagram

// in a recursive solution , first we will write the base condition

// then the choice diagram needs to be written

// base condition is the smallest valid input 


// here if " n=0 or capacity=0 " then the maximum profit is 0



#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// this is the recursive solution for 0-1 knapsack problem

// int knapsack(int wt[], int val[], int w, int n){
//     // base condition
//     if (n == 0 || w == 0){
//         return 0;
//     }
    
 

//     // we have two choices for each item if its less than or equal to the capacity
//     // choice diagram
//     if (wt[n-1] <= w) {
//         // include the item , we can take the item
//         int include = val[n-1] + knapsack(wt, val, w - wt[n-1], n - 1);


//         // exclude the item, we can also choose not to take the item
//         int exclude = knapsack(wt, val, w, n - 1);
//         return max(include, exclude);
//     } 
    
//     else {
//         // cannot include the item because of its weight constraint
//         // we can only exclude it
//         // hence, we will not include the item
//         return knapsack(wt, val, w, n - 1);
//     }
// }


// int main() {
//         memset(dp, -1, sizeof(dp)); // initialize the dp array with -1
    
//         // Example usage:
//         int wt[] = {1, 2, 3, 4};
//         int val[] = {10, 20, 30, 40};
//         int w = 5;
//         int n = 4;
//         std::cout << "Maximum value: " << knapsack(wt, val, w, n) << std::endl;
//         return 0;
//     }







//---------------------------------------------------------


// now we will write the memoization solution for 0-1 knapsack problem

// 2d array for memoization

// we make the matrix for the variables which change during the recursion calls

// in this case, the variables are n and w

// initialize the memoization array with -1

// memset(dp, -1, sizeof(dp)); -> initialized each box with -1 value

//---------------------------------------------------------

// ADDITION IN THE RECURSIVE CODE

#include <iostream>
#include <string.h>

// int static dp[102][1002]; // assuming max n is 100 and w is 1000

// // memset(dp, -1, sizeof(dp)); // initialize the dp array with -1
// int knapsack(int wt[], int val[], int w, int n){
//     if (n == 0 || w == 0){
//         return 0;
//     }
//     if (dp[n][w] != -1){
//         return dp[n][w];
//     }


//     if (wt[n-1] <= w) {
//         int include = val[n-1] + knapsack(wt, val, w - wt[n-1], n - 1);

//         int exclude = knapsack(wt, val, w, n - 1);
//         return dp[n][w] = max(include, exclude);
//     } 
    
//     else {
//         return dp[n][w] = knapsack(wt, val, w, n - 1);
//     }
// }

// int main() {
//     memset(dp, -1, sizeof(dp)); 

//     int wt[] = {1, 3, 4, 5};
//     int val[] = {1, 4, 5, 7};
//     int W = 7;
//     int n = sizeof(wt)/sizeof(wt[0]);

//     cout << "Max profit: " << knapsack(wt, val, W, n) << endl;
//     return 0;
// }


//--------------------------------------------------------------

// now we will will write the top down approach of the 0-1 knapsack problem

// base condition -> initialization of the dp array


int knapsack(int wt[], int val[], int w, int n) {
int dp[n+1][w+1];
for (int i = 0; i<n+1; i++){
    for (int j = 0; j<w+1; j++){
        if (i == 0 || j == 0){
            dp[i][j] = 0; // base condition
        }
    }
}
for(int i = 1; i<n+1; i++){
    for(int j = 1; j<w+1; j++){
        if (wt[i-1] <= j) {
            dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
        }
        else {
            dp[i][j] = dp[i-1][j]; // cannot include the item because of its weight constraint
        }
    }
}

return dp[n][w]; // maximum profit
}

int main(){
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;
    int n = sizeof(wt)/sizeof(wt[0]);

    cout << "Max val: " << knapsack(wt, val, W, n) << endl;
    return 0;
}