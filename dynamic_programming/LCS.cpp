#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int LCS_mem(vector<vector<int>>& dp, const string& s1, const string& s2, int i, int j) {
    if (i == 0 || j == 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = 1 + LCS_mem(dp, s1, s2, i - 1, j - 1);
    else
        return dp[i][j] = max(LCS_mem(dp, s1, s2, i, j - 1), LCS_mem(dp, s1, s2, i - 1, j));
}

int LCS_tab(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[m][n];
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    cout << "Length of LCS is: " << LCS_mem(dp, s1, s2, m, n) << endl;
    cout << "Length of LCS is: " << LCS_tab(s1, s2) << endl;
    return 0;
}
