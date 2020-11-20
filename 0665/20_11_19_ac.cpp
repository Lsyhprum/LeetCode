#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() <= 2) return true;

        int reverse = 0;
        int pre = nums[0];

        for(int i = 1; i < nums.size(); i ++) {
            if(pre > nums[i]) reverse ++;
            if(reverse > 1) return false;
            pre = nums[i];
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    std::cout << sol.checkPossibility(nums);
    return 0;
}