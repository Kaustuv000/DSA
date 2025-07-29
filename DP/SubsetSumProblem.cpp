// if a subset is present in the given array whose sum is given as the target sum
// result in true or false, we dont need to return the sum

// if only one array is given, then take it as a weight array


// if two arrays are given, then take the first array as the weight array and the second array as the value array  

// the sum of all the elements in the array should be even, so we can divide it into two subsets with equal sum
// else we cannot divide it into two subsets with equal sum and return false

// 1. initialization of the dp array
// 2. top row and left most column will be 0
// 3. number of rows will be equal to the number of elements in the array + 1 (arr size + 1)
// 4. number of columns will be equal to the target sum + 1 ( target sum + 1 )
// 5. NOW WE FILL THE DP TABLE or 2D Array


#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;



    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        
        for(int i =0; i<=n; i++){
            dp[i][0] = true;
        }
       
       for(int i = 1; i<=n; i++){
           for (int j=1; j<=sum; j++){
               if (arr[i-1] <= j) {
                   dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j]; 
               }
               else{
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
        return dp[n][sum];
    }


int main(){

int n = 5; // size of the array
int targetSum = 11; // target sum we want to check for
vector<int> arr = {1, 2, 3, 4, 5}; // the array of elements 

bool result = isSubsetSum(arr, targetSum);
if (result) {
    cout << "YES" << endl;
    } else {
    cout << "NO" << endl;
    }
return 0;
}