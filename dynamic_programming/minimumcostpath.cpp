#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Memoisation approach
int minCostMemo(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& memo) {
    if (row < 0 || col < 0) {
        return INT_MAX;
    }
    if (row == 0 && col == 0) {
        return grid[0][0];
    }
    if (memo[row][col] != -1) {
        return memo[row][col];
    }

    int left = minCostMemo(row, col - 1, grid, memo);
    int top = minCostMemo(row - 1, col, grid, memo);
    memo[row][col] = grid[row][col] + min(left, top);
    return memo[row][col];
}

int minCostMemoisation(int rows, int cols, vector<vector<int>>& grid) {
    vector<vector<int>> memo(rows, vector<int>(cols, -1));
    return minCostMemo(rows - 1, cols - 1, grid, memo);
}

// Tabulation approach
int minCostTabulation(int rows, int cols, vector<vector<int>>& grid) {
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < rows; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < cols; ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[rows - 1][cols - 1];
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    cout << "Minimum cost (Memoisation): " << minCostMemoisation(grid.size(), grid[0].size(), grid) << endl;
    cout << "Minimum cost (Tabulation): " << minCostTabulation(grid.size(), grid[0].size(), grid) << endl;

    return 0;
}
