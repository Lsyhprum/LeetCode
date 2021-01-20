#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Status {
    int lSum, rSum, mSum, iSum;
};

// time complexity : O(N)
// space complexity : O(logN)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }

private:
    Status pushUp(Status l, Status r) {
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int iSum = l.iSum + r.iSum;
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);

        return {lSum, rSum, mSum, iSum};
    }

    Status get(vector<int>& nums, int l, int r) {
        if(l == r) {
            return {nums[l], nums[l], nums[l], nums[l]};
        }

        int mid = (r - l) / 2 + l;

        Status sl = get(nums, l, mid);
        Status sr = get(nums, mid + 1, r);

        return pushUp(sl, sr);
    }
    
};

int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << sol.maxSubArray(nums);
    return 0;
}