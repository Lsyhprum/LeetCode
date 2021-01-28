#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();

        if(len == 0 || len == 2) return -1;
        if(len == 1) return 0;

        int left = 0, right = len - 1;
        int left_sum = 0, right_sum = 0;

        bool flag = true;
        while(left < right) {
            if(left_sum <= right_sum) {
                if(nums[left] >= 0) {
                    left_sum += nums[left];
                    left ++;
                    flag = true;
                } else {
                    right_sum += nums[right];
                    right --;
                    flag = false;
                }
            } else {
                if(nums[right] >= 0) {
                    right_sum += nums[right];
                    right --;
                    flag = false;
                } else {
                    left_sum += nums[left];
                    left ++;
                    flag = true;
                }
            }
        }

        int res = -1;
        std::cout << left_sum << " " << right_sum << std::endl;
        if(left == right && left_sum == right_sum)
            if(flag) {
                res = left;
            } else {
                res = right;
            }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> v = {-1, -2, 3, -1, -2};
    std::cout << sol.pivotIndex(v);
    return 0;
}