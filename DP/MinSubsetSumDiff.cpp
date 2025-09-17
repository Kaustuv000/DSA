#include <bits/stdc++.h>
using namespace std;

int minSubsetDiff(vector<int>& arr, int n){
    int sum = 0;
    for (int i =0; i<n; i++){
        sum += arr[i];
    }

    vector<vector<bool>> dp(n, vector<bool>(sum+1, false));

    for (int i = 0; i<n; i++){
        dp[i][0] = true; // sum 0 is always possible with empty subset
    }

    if(arr[0]<=sum){
        dp[0][arr[0]] = true; // first element can form a subset with its own value 
    }



    for (int i = 1; i<n; i++){
        for (int j = 1; j<=sum; j++){
            if (arr[i] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
            } else {   
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int mini = INT_MAX;

    for (int i = 0; i<=sum/2; i++){
        if(dp[n-1][i]){
            //abs(S1 - S2) = abs((sum - S2) - S2) = abs(sum - 2*S2)
            // where S1 is the sum of one subset and S2 is the sum of the other subset
            // we want to minimize this difference
            mini = min(mini, abs(sum - 2*i));
        }
    }
    return mini;
}