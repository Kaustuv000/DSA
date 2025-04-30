#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

// By HASHING we can count the single numbers

vector<int> hashFunc(int nums[], int n){
    vector<int> ans;
    // int hash[n] = {0}; // This is not a good way to create a hash table
    unordered_map<int, int> hash; // or we can use map

    // LOOKup time
    // O(1) for unordered_map
    // O(log n) for map

    for(int i = 0; i<n; i++){
        hash[nums[i]]++;
    }
    for (auto it : hash){
        if(it.second == 1){
            ans.push_back(it.first);
        }
    }
    return ans;
    
}

int main(){
    int nums[] = {1, 2, 1, 3, 2, 3, 3, 4};
    int n = sizeof(nums)/sizeof(nums[0]);
    vector<int> res = hashFunc(nums, n);
    cout << "The numbers that appear only once are: "<< endl;
   for (auto i : res){
        cout << i << " ";
    }
    return 0;
}
// Time complexity: O(n)
// Space complexity: O(n) for the hash table


// V2. Using XOR -> concept of buckets
// unique numbers will go into different buckets


vector<int> singleNumber(vector<int>& nums) {
    // approach : we know that all duos xor will be 0 and the unique 2 elements xor will contain
    // nothing but a number which contain bits which are not same in both 
    long long numXor=0;
    for(auto it:nums)numXor^=it;
    // now we need to distinguish both the numbers 
    // and xor contains all the bits which are not same in both , we just need one different bit 
    // taking the rightmost one is fine 
    long long rightBit= numXor ^ (numXor &(numXor-1));
    // now take 2 bucket integer which store numbers based on this rightBit
    int a=0,b=0;
    for(auto it:nums){
        // if right bit is set 
        if(it&rightBit)a^=it;
        else b^=it;
    }
    return {a,b};
}