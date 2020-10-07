#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // 1 2 3 4
        // 2 3 4 4
        // 3 4 5 4
        // 4 5 5 5
        sort(nums.begin(), nums.end());

        int min = nums.front();
        int res = 0;

        for(int i = 1; i < nums.size(); i ++) {
            res += (nums[i] - min);
        }

        return res;

    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2 ,3};
    std::cout << sol.minMoves(nums);
    return 0;
}