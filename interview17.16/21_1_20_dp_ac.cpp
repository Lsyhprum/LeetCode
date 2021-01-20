#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        int res = max(nums[0], nums[1]);

        vector<int> dp(nums.size(), 0);
        for(int i = 0; i < nums.size(); i ++) {
            dp[i] = nums[i];
        }
        
        for(int i = 2; i < nums.size(); i ++) {
            for(int j = 0; j < i - 1; j ++) {
                dp[i] = max(dp[i], nums[i] + dp[j]);
                //std::cout << i << " " << j << " " << dp[i] << std::endl;

                res = max(res, dp[i]);
            }
        }

        // for(int i = 0; i < nums.size(); i ++) {
        //     std::cout << dp[i] << std::endl;
        // }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> message = {1, 3, 1};
    std::cout << sol.massage(message);
    return 0;
}