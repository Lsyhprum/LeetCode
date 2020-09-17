#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        return max(robRange(nums, 0, n-2), robRange(nums, 1, n-1));
    }

private:
    int robRange(vector<int>& nums, int start, int end){
        int dp1 = 0, dp2 = 0, dp = 0;

        for(int i = end; i >= start; i --){
            dp = max(dp1, dp2 + nums[i]);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {1,2,3,1};

    cout << sol.rob(nums);

    return 0;
}