#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int mid = nums.size() / 2;

        int res = 0;

        for(int i = 0; i < nums.size(); i ++) {
            res += abs(nums[i] - nums[mid]);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, 0, 8, 6};
    // 0 0 1 6 8
    // avg : 3   3 3 2 3 5
    // mid : 1   1 1 0 5 7
    std::cout << sol.minMoves2(nums);
    return 0;
}