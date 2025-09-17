#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr){
    int n= arr.size();

    for (int i = 0; i<n-1; ++i){
        bool swapped = false;


        for (int j = 0; j<n-i-1; ++j){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if (!swapped) break; // If no two elements were swapped, the array is sorted
    }
}


// Utility to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original Array: ";
    printArray(arr);

    bubbleSort(arr);

    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}