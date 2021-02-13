#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;

        for(int i : nums) {
            nums[abs(i) - 1] = -abs(nums[abs(i) - 1]);
        }

        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] > 0) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};

int main() {

    Solution sol;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> res = sol.findDisappearedNumbers(nums);

    for(int i : res) {
        std::cout << i << std::endl;
    }

    return 0;
}