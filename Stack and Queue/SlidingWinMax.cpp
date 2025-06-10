#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>   

using namespace std;


// ========== Standard Sliding Window Maximum ==========

// // Value of k is the size of the sliding window
// // in this window we will find the maximum
// int main(){
//     int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
//     int k = 3;
//     vector<int> list;
//     int n = sizeof(nums)/sizeof(nums[0]);
//     int maxi = 0;
//     for (int i = 0; i<=n-k; i++){
//         maxi = nums[i];
//         for(int j = i; j<i+k; j++){
//             maxi = max(maxi, nums[j]);  
//         }
//         list.push_back(maxi);
//     }
//     for (auto &it : list){
//         cout << it << " ";
//     }
//     return 0;
// }


// ===== optimized Sliding Window Maximum using monotonic stack or deque which acts as a stack =====


int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove out-of-window indices
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove all smaller elements from the back
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        // Record max for window
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    for (int x : result) cout << x << " ";
    return 0;
}