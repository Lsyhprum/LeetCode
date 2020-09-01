#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return getScore(nums, 0, nums.size() - 1) >= 0;
    }

private:
    int getScore(vector<int> &nums, int l, int r){
        if(l == r) return nums[l];
        return max(nums[l] - getScore(nums, l + 1, r), nums[r] - getScore(nums, l, r - 1));
    }

};

int main(){
    Solution sol;

    vector<int> nums = {2, 4, 55, 6, 8};

    cout  << sol.PredictTheWinner(nums);
    return 0;
}