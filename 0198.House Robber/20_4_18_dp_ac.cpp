# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;


// Runtime 100%
class Solution {
public:
    int rob(vector<int>& nums) {
        // 1. 明确状态：抢到的钱数
        // 2. 明确dp[]：dp[i] 从左向右最多抢到的钱数
        // 3. 明确选择：
        //     flag 标识上一家是否抢过
        //     3.1 抢 
        //     3.2 不抢 
        //     3.3 状态转移方程：
        // 4. 明确 base case: dp[i] = nums[i]       wa : dp[0] = 0

        vector<int> dp(nums);
        
        bool flag = true;   // 上一家是否抢过
        for(int i = 1; i < nums.size(); i ++){
            for(int j = 0; j < i - 1; j ++){
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }

            if(!flag && dp[i] < dp[i-1] + nums[i]){ // 上一家没抢过
                dp[i] = dp[i-1] + nums[i];
                flag = false;
            }else{
                flag = true;
            }
        }

        int ans = 0;
        for(int i = 0; i < nums.size(); i ++)
            ans = max(ans, dp[i]);

        return ans;
    }
};

int main(){
    Solution sol;

    vector<int> v = {1, 1, 3, 2, 5, 4, 7};
    cout << sol.rob(v);

    return 0;
}