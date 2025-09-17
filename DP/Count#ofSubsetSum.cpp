#include <bits/stdc++.h>
using namespace std;    

int countSubsetSum(vector<int>& arr, int sum){
    int n = arr.size();

    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

    for (int i = 0; i<n; i++){
        dp[i][0] = 1; // sum 0 is always possible with empty subset
    }

    if (arr[0]<=sum){
        dp[0][arr[0]] = 1; // first element can form a subset with its own value
    }

    // now we fill the dp table
    for(int i = 1; i<=n; i++){
        for (int j = 1; j<=sum; j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]]; // include or exclude the current element
            } else {
                dp[i][j] = dp[i-1][j]; // cannot include the current element
            }
        }
    }
    return dp[n][sum]; // return the number of subsets that sum to the target

}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5}; // the array of elements
    int targetSum = 5; // target sum we want to check for
    int result = countSubsetSum(arr, targetSum);
    cout << "Number of subsets with sum " << targetSum << ": " << result << endl;
    return 0;
    // output = 5
}