#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool subsetSum_mem(vector<int>& nums, int target, int index, unordered_map<string, bool>& dp_map) {
    if (target == 0) return true;
    if (index >= nums.size() || target < 0) return false;

    string key = to_string(index) + "|" + to_string(target);
    if (dp_map.find(key) != dp_map.end()) return dp_map[key];

    bool include = subsetSum_mem(nums, target - nums[index], index + 1, dp_map);
    bool exclude = subsetSum_mem(nums, target, index + 1, dp_map);

    dp_map[key] = include || exclude;
    return dp_map[key];
}
bool subsetSum(vector<int>& nums, int target) {
    unordered_map<string, bool> dp_map;
    return subsetSum_mem(nums, target, 0, dp_map);
}

bool subsetSum_Tab(vector<int>& nums, int target,int n) {
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    // Base case: subset sum with target 0 is always possible
    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
        }
    }
    return dp[n][target];
}

int main() {
    vector<int> nums= {2, 3, 7, 8};
    int target = 11;
    if (subsetSum(nums, target))
        cout << "Subset with sum " << target << " exists." << endl;
    else
        cout << "No subset with sum " << target << " exists." << endl;

    if (subsetSum_Tab(nums, target,nums.size()))
        cout << "Subset with sum " << target << " exists." << endl;
    else
        cout << "No subset with sum " << target << " exists." << endl;

    return 0;
}
