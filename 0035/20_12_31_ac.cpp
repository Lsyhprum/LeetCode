#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right) {
            int mid = (right - left) / 2 + left;

            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6};

    Solution sol;
    std::cout << sol.searchInsert(nums, 2);

    return 0;
}