#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int knapsackMemoization(vector<int>& weights, vector<int>& profit, int capacity, int n) {
    if (n == 0 || capacity == 0) {
        return 0;
    }
    if (dp[n][capacity] != -1) {
        return dp[n][capacity];
    }
    if (weights[n - 1] > capacity) {
        dp[n][capacity] = knapsackMemoization(weights, profit, capacity, n - 1);
    } else {
        dp[n][capacity] = max(
            profit[n - 1] + knapsackMemoization(weights, profit, capacity - weights[n - 1], n - 1),
            knapsackMemoization(weights, profit, capacity, n - 1)
        );
    }

    return dp[n][capacity];
}
int knapsackTabulation(vector<int>& weights, vector<int>& profit, int capacity, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weights[i - 1]],
                    dp[i - 1][w]
                );
            }
        }
    }
    return dp[n][capacity];
}


int main() {
    vector<int> weights = {2, 3, 4, 5};
    vector<int> profit = {3, 4, 5, 6};
    int capacity = 5;
    int n = weights.size();

    dp.resize(n + 1, vector<int>(capacity + 1, -1));

    cout << "Maximum value: " << knapsackMemoization(weights, profit, capacity, n) << endl;
    cout << "Maximum value: " << knapsackTabulation(weights, profit, capacity, n) << endl;


    return 0;
}
