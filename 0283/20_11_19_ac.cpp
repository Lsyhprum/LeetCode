#include <iostream>
#include <vector>

using namespace std;

// time complexity : O(N), 49.15%
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() <= 1) return;

        int other = 0, pos = 0;

        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] != 0) {
                nums[pos] = nums[i];
                pos ++;
                other ++;
            }
        }

        for(int i = other; i < nums.size(); i ++) {
            nums[i] = 0;
        }

    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 0, 0, 0, 0, 1};

    sol.moveZeroes(nums);

    for(int i : nums) {
        std::cout << i << " ";
    }
    return 0;
}