#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// time complexity : O(N)
// space complexity : O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];

        for(int i = 1; i < nums.size(); i ++) {
            nums[i] = max(nums[i], nums[i-1] + nums[i]);
            res = max(nums[i], res);
        }

        return res;
    }
};

int main() {

    Solution sol;

    vector<int> nums = {-2, 1, 2, 3, -3, 1, 2, 3, 4};

    std::cout << sol.maxSubArray(nums) << std::endl;

    return 0;
}