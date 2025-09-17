#include <bits/stdc++.h>
using namespace std;


// // given the array 
// we will start from the first element and check if it is greater than the previous element

// we will use a vector to store the index of the elements in the longest increasing subsequence

// either u can take the element or we cannot take the current element, we can pass to the next one , and check if the next element is greater than the previous element

// if it is greater than the previous element, we can take it and add it to the vector, otherwise we will not take it and move to the next element


// so it we are not taking it 

//  len = 0 + f(index +1, prevIndex, arr, dp);

// if we are taking it, we will add 1 to the length and move to the next element
// len = 1 + f(index +1, index, arr, dp);

//    if(prevIndex == -1||arr[index]>arr[prevIndex]){
//       len = max(len, 1+f(index+1, index, arr, dp));
//    }

// return dp[index][prevIndex] = len;

// for this the time complexity will be O(2^n) and space complexity will be O(n) for the recursion stack



// memoization  code
int f(int index, int prevIndex, vector<int>& arr, vector<vector<int>>& dp){
    
    if(index == arr.size()){
        return 0;
    }

    if (dp[index][prevIndex + 1] != -1) {
        return dp[index][prevIndex + 1];
    }

    int len = 0+f(index+1, prevIndex, arr, dp);

    if(prevIndex == -1 || arr[index] > arr[prevIndex]){
        len = max(len, 1 + f(index + 1, index, arr, dp));
    }
    return dp[index][prevIndex + 1] = len;
}

int longestIncreasingSubsequence(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    
    return f(0, -1, arr, dp);
}

