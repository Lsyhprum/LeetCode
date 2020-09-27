#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int cur = 0;
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] == 1) {
                cur += 1;
            }else {
                max = cur > max ? cur : max;
                cur = 0;
            }
        }

        return max > cur ? max : cur;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 0, 1};
    std::cout << sol.findMaxConsecutiveOnes(nums);

    return 0;
}