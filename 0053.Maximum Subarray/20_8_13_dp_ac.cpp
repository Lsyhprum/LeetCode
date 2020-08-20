#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// time complexity : O(N),  faster than 84.06% of C++ online submissions for Maximum Subarray.
// memory complexity : O(N), less than 34.12% of C++ online submissions for Maximum Subarray.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 典型的动态规划问题: 重叠子结构、最优子问题、状态转移问题
        // 1. 确定状态 ： 子数组的最大值
        // 2. 确定数组含义 ：以数组 i 为结尾的子数组的和
        // 3. 确定状态转移方程 ： dp[i] = MAX{dp[i], dp[i - 1] + nums[i]}
        // 4. 确定base case : dp[i] = nums[i]

        vector<int> dp(nums.size());
        for(int i = 0; i < nums.size(); i ++)
            dp[i] = nums[i];

        int res = dp[0];
        for(int i = 1; i < nums.size(); i ++){
            dp[i] = max(dp[i], nums[i] + dp[i-1]);
            res = max(res, dp[i]);
            //cout << res << endl;
        }

        return res;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {1, -1, -2, -3, 1, 2, -2, 5, -5};
    cout << sol.maxSubArray(nums);
    return 0;
}