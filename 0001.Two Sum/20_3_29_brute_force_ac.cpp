# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

// Runtime: 5.05%
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        
        for(int i = 0; i < nums.size() - 1; i ++){
            for(int j = i + 1; j < nums.size(); j ++){
                if(nums[i] + nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> v = {2, 7, 11, 15};
    vector<int> res = sol.twoSum(v, 13);
    cout << res[0] << " " << res[1] << endl;

    return 0;
}