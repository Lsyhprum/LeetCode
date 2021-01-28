#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        int sum = 0;

        for(int i = 0; i < nums.size(); i ++) {
            if(2 * sum + nums[i] == total)
                return i;
            sum += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> v = {-1, -2, 3, -1, -2};
    std::cout << sol.pivotIndex(v);
    return 0;
}