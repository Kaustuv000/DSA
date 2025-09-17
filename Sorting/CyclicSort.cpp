#include <bits/stdc++.h>

using namespace std;

void cyclicSort(vector<int>& nums){
    int i = 0; 

    while(i<nums.size()){
        int correctIndex = nums[i]-1;
        if(nums[i]!= nums[correctIndex]){
            swap(nums[i], nums[correctIndex]);
        } else {
            i++;
        }   
    }
}

int main(){
    vector<int> nums =  {3, 5, 2, 1, 4};
    cout << "Original array: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cyclicSort(nums);

    cout << "Sorted array: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}