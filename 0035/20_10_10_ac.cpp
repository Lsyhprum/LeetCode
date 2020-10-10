#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right) {
            int mid = (right - left) / 2 + left;
            //std::cout << mid << std::endl;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    std::cout << sol.searchInsert(nums, 0);
    return 0;
}