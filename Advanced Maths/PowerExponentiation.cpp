#include <iostream>
#include <vector>

using namespace std;

int power(int x,int n){
    // x = base, n = exponent
    int ans = 1;
    while (n>0){
        if (n%2==1){
            // n is odd
            // multiply the current ans with x
            ans = ans * x;
            n = n - 1; // reduce n by 1 to make it even
        }
        else{
            // n is even
            n = n / 2; // divide n by 2
            x = x * x; // square the base as the exponent is halved 
        }
    }
    if (n<0){
        ans = 1/ans;
    }
    // if n is negative, we need to take the reciprocal of the ans
    return ans;  
}

int main(){
    int x = 2;
    int n = 10;
    cout << power(x,n) << endl; // 1024
    return 0;
}   

// when the power is negative we just need to divide the ans by x
// for example, 2^-3 = 1/(2^3) = 1/8 = 0.125

// Time Complexity: O(log n)
// Space Complexity: O(1)