#include <iostream>
#include <vector>
#include <cstring> // For memset
using namespace std;

int LIS_memo(vector<int>& nums, int prev, int cur, vector<vector<int>>& dp) {

    if (cur == nums.size()) return 0;
    if (dp[prev + 1][cur] != -1) return dp[prev + 1][cur];
    
    int taken = 0;
    if (prev == -1 || nums[cur] > nums[prev]) {
        taken = 1 + LIS_memo(nums, cur, cur + 1, dp);
    }
    int not_taken = LIS_memo(nums, prev, cur + 1, dp);
    
    dp[prev + 1][cur] = max(taken, not_taken);
    return dp[prev + 1][cur];
}
int LIS_tab(vector<int>& nums) {
       vector<int>dp;
         dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(dp.back()<nums[i])
            {
                dp.push_back(nums[i]);
            }
            else{
                int index=lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                dp[index]=nums[i];
            }
        }
         return dp.size();
    }

int main() {

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n, -1));
    cout << "Length of LIS: " << LIS_memo(nums, -1, 0, dp) << endl;
    cout << "Length of LIS: " << LIS_tab(nums) << endl;
    return 0;
}
