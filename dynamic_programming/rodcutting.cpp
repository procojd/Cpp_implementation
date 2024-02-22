#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Memoization approach
int Rodcut_mem(int price[], int n, vector<int>& memo) {
    if (n <= 0) return 0;
    
    if (memo[n] != -1) return memo[n];
    
    int max_val = INT_MIN;
    for (int i = 0; i < n; i++) {
        max_val = max(max_val, price[i] + Rodcut_mem(price, n - i - 1, memo));
    }
    memo[n] = max_val;
    return max_val;
}
int rodCuttingMemoization(int price[], int n) {
    vector<int> memo(n + 1, -1);
    return Rodcut_mem(price, n, memo);
}

// Tabulation approach
int Rodcut_tab(int price[], int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++) {
            max_val = max(max_val, price[j] + dp[i - j - 1]);
        }
        dp[i] = max_val;
    }

    return dp[n];
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(price) / sizeof(price[0]);
    
    cout << "Maximum profit (Memoization): " << rodCuttingMemoization(price, size) << endl;
    cout << "Maximum profit (Tabulation): " << Rodcut_tab(price, size) << endl;

    return 0;
}
