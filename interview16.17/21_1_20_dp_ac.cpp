#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];

        for(int i = 1; i < nums.size(); i ++) {
            nums[i] += max(0, nums[i - 1]);
            res = max(res, nums[i]);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << sol.maxSubArray(nums);
    return 0;
}