#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 1e6;
    vector<int>spf(n + 1); // spf[i] will store the smallest prime factor of i
    for (int i = 2; i <= n; i++){
        spf[i] = i; // Assume all numbers are prime initially
    }

    for(int i = 2; i * i <= n; i++){
        if (spf[i]==i){
            for (int j = i * i; j <= n; j += i){
                if(spf[j] ==j) spf[j] = i; // Mark multiples of i as non-prime
            }
        }
    }


// given the queries
    int queries[] = {10, 15, 20, 30, 50};
    int size = sizeof(queries) / sizeof(queries[0]);
    for (int i = 0; i < size; i++) {
    int z = queries[i];
    while (z != 1) {
        cout << spf[z] << " ";
        z /= spf[z];
    }
    cout << endl;
}
    return 0;

}