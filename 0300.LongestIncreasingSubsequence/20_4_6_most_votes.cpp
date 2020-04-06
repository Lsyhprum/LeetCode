# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> top;

        for(int i = 0; i < nums.size(); i ++){
            auto lp = lower_bound(top.begin(), top.end(), nums[i]);

            if(lp == top.end()) top.emplace_back(nums[i]);
            else *lp = nums[i];
        }

        return top.size();
    }
};

int main(){
    Solution sol;
    vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << sol.lengthOfLIS(v);
    return 0;
}