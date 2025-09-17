#include <bits/stdc++.h>
#include <string>
using namespace std;

string LCS(const string& s1, const string& s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // if(n == 0 || m  == 0) return 0;
    
    if(n == 0 || m  == 0) return "";
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1]; 

            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // return dp[n][m];


    int i = n, j = m;
    string lcs = "";
    while (i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            lcs+=s1[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }

    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

// pair<int, string> LongestPalindromicSubseq(const string& s) {
string LongestPalindromicSubseq(const string& s) {
    string sOld = s;
    string sNew = s;
    reverse(sNew.begin(), sNew.end());
    string lps = LCS(sOld, sNew);
    return lps;

}

int main() {
    string s = "bbabcbcab";
    // cout << "Length: "<< res.first << endl;
    cout << "Longest Palindromic Subsequence: " << LongestPalindromicSubseq(s) << endl;
    return 0;
}   