# include <iostream>
# include <vector>

using namespace std;

// Runtime 96.24% 
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() <= 1) return 0;

        int pre_val = INT_MIN;

        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] > pre_val && i + 1 < nums.size() && nums[i + 1] < nums[i]){
                return i;
            }
        }
        if(nums[nums.size() - 1] > nums[nums.size() - 2]){
            return nums.size() - 1;
        }

        return 0;
    }
};

int main(){
    Solution sol;
    vector<int> v = {1, 1};
    cout << sol.findPeakElement(v) << endl;
    return 0;
}