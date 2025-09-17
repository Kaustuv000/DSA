#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(const string &s1, const string &s2) {
    int n = s1.size();
    int m = s2.size();

    // dp[i][j] = length of LCSubstring ending at s1[i-1] and s2[j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maxLength = 0; // track the maximum length found
    int endPos = 0;    // optional: track position in s1 where substring ends

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endPos = i; // store position of match end
                }
            } else {
                dp[i][j] = 0; // reset if characters don't match
            }
        }
    }

    // Optional: get the actual substring
    string longestSubstr = s1.substr(endPos - maxLength, maxLength);
    cout << "Longest Common Substring: " << longestSubstr << endl;

    return maxLength;
}

int main() {
    string s1 = "abcde";
    string s2 = "abfce";
    cout << "Length: " << longestCommonSubstring(s1, s2) << endl;
    return 0;
}
