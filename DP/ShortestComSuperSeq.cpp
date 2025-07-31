#include <iostream>
#include <vector>
using namespace std;

// Step 1: Build LCS DP table
vector<vector<int>> lcsTable(const string& X, const string& Y) {
    int m = X.size(), n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp;
}

// Step 2: Build the SCS using the LCS table
string printSCS(const string& X, const string& Y) {
    int i = X.size(), j = Y.size();
    vector<vector<int>> dp = lcsTable(X, Y);
    string result = "";

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            // common character, part of LCS
            result = X[i - 1] + result;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            result = X[i - 1] + result;
            i--;
        } else {
            result = Y[j - 1] + result;
            j--;
        }
    }

    // Add remaining characters
    while (i > 0) result = X[i - 1] + result, i--;
    while (j > 0) result = Y[j - 1] + result, j--;

    return result;
}

// Driver
int main() {
    string str1 = "AGGTAB", str2 = "GXTXAYB";
    string scs = printSCS(str1, str2);
    cout << "SCS: " << scs << endl;
    return 0;
}
