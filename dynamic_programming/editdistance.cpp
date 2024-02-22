#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Memoization approach
int Editdis_mem(string word1, string word2, int m, int n, vector<vector<int>>& memo) {
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }
    if (memo[m][n] != -1) {
        return memo[m][n];
    }

    if (word1[m - 1] == word2[n - 1]) {
        return memo[m][n] = Editdis_mem(word1, word2, m - 1, n - 1, memo);
    }

    int insertOp = 1 + Editdis_mem(word1, word2, m, n - 1, memo);
    int deleteOp = 1 + Editdis_mem(word1, word2, m - 1, n, memo);
    int replaceOp = 1 + Editdis_mem(word1, word2, m - 1, n - 1, memo);

    return memo[m][n] = min({insertOp, deleteOp, replaceOp});
}

int Editdis_memoization(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    return Editdis_mem(word1, word2, m, n, memo);
}

// Tabulation approach
int Editdis_tab(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
            }
        }
    }

    return dp[m][n];
}

int main() {
    string word1 = "sitting";
    string word2 = "kitten";

    cout << "Edit distance (Memoization): " << Editdis_memoization(word1, word2) << endl;
    cout << "Edit distance (Tabulation): " << Editdis_tab(word1, word2) << endl;

    return 0;
}
