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

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];

        for(int i = 2; i < nums.size(); i ++){
            dp[i] = dp[i-1];
            for(int j = 0; j < i - 1; j ++){
                dp[i] = max(nums[i] + dp[j], dp[i]);
            }
            //cout << dp[i] << endl;
        }                   

        return dp[nums.size() - 1];
    }
};

int main(){
    Solution sol;

    vector<int> nums = {10, 1, 1, 1, 1, 1, 2};

    cout << sol.rob(nums);


    return 0;
}