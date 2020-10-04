#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<int> dp(nums.back() + 1, 0);

        for(int i = 0; i < nums.size(); i ++) {
            dp[nums[i]] ++;
        }
        
        std::cout << nums.back() << " " << dp[nums.back()] << std::endl;
        if(dp[nums.back()] == nums.back()) return dp[nums.back()];

        for(int i = nums.back() - 1; i >= 0; i --) {
            dp[i] += dp[i + 1];
            std::cout << i << " " << dp[i] << std::endl;
            if(dp[i] == i) return i;
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    std::cout << sol.specialArray(nums);
    return 0;
}