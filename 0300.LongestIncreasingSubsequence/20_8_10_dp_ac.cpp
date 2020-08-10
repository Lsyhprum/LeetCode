#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//time complexity : O(N^2), 38.46%
//space complexity : O(N), 88.53%
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 动态规划：重叠子问题、最优子结构、状态转移方程
        //     重叠子问题：长度为 N 的数组子问题可复用
        //     最优子结构：长度为 N 的数组的 LIS 可由长度 1..N-1 的 LIS 得出

        // 明确状态：LIS
        // 明确 dp 数组含义：dp[i] 为 长度为 i 的数组的 LIS 长度
        // 明确选择：dp[i] = 1 + MAX{dp[1], dp[2], .. , dp[i-1]}
        // 明确base case : dp[1] = 1

        if(nums.size() < 1) return 0;

        vector<int> dp(nums.size(), 1);

        int res = 1;
        for(int i = 1; i < nums.size(); i ++){
            for(int j = 0; j < i; j ++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }

        // for(int i = 0; i < nums.size(); i ++)
        //     cout << dp[i] << endl;

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {13, 12, 11, 10};
    cout << sol.lengthOfLIS(nums);
}