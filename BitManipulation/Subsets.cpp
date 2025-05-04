#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int subsett = 1 << n;
    vector<vector<int>> ans;
    for(int num = 0; num < subsett; num++) {
        vector<int> list;
        for(int i = 0; i < n; i++) {
            if(num & (1 << i)) {
                list.push_back(nums[i]);
            }
        }
        ans.push_back(list);
    }
    return ans;
};