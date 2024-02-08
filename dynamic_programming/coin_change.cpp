#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int coinChangeMemo(vector<int>& coins, int target, vector<int>& dp) {
    if (target == 0) return 0;
    if (target < 0) return -1;

    // Check if we have already solved this subproblem.
    if (dp[target] != INT_MAX) return dp[target];

    for (int coin : coins) {

        int subproblem = coinChangeMemo(coins, target - coin, dp);
        if (subproblem == -1) continue;
        dp[target] = min(dp[target], 1 + subproblem);
    }

    return dp[target] = (dp[target] == INT_MAX) ? -1 : dp[target];
}

int coinChange(vector<int>& coins, int target) {
    vector<int> dp(target + 1, INT_MAX);
    return coinChangeMemo(coins, target, dp);
}

int coinChangeTabulation(vector<int>& coins, int target) {
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;//0 target can't be achieves using coins.

    for (int i = 1; i <= target; ++i) {//target loops instead of recursion
        for (int coin : coins) {//coins loop as it is.
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[target] ==INT_MAX ? -1 : dp[target];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int target = 11;
    cout << "Minimum coins required: " << coinChange(coins, target) << endl;
    cout << "Minimum coins required: " << coinChangeTabulation(coins, target) << endl;
    return 0;
}
