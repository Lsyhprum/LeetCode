#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        int origin_len = nums.size();

        nums.resize(origin_len * 2);

        for(int i = 0; i < origin_len; i ++)
            nums[i + origin_len] = nums[i];

        // 4 1 2 4 1 2
        // 4 1 6 8 8 10

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];

        for(int i = 2; i < nums.size(); i ++){
            dp[i] = dp[i-1];

            for(int j = 0; j < i - 1; j ++){
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
            cout << dp[i] << endl;
        }

        return dp[nums.size() - 1] / 2;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {4, 1, 2};

    cout << sol.rob(nums);

    return 0;
}