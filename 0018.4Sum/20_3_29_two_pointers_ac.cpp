# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

//Runtime: 30.87%
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        if(nums.size() < 4) return res;

        sort(nums.begin(), nums.end());

        int a = 0, b, c, d = nums.size() - 1;

        for(int i = 0; i < nums.size() - 3; i ++){
            if(res.size() && nums[i] == res[res.size() - 1][0]){
                continue;
            }
            int sum3_target = target - nums[i];
            for(int j = i + 1; j < nums.size() -2; j ++){
                if(res.size() && nums[i] == res[res.size() - 1][0] && nums[j] == res[res.size()-1][1]){
                    continue;
                }
                int sum2_target = sum3_target - nums[j];
                int left = j + 1, right = nums.size() - 1;
                while(left < right){
                    if(res.size() && nums[i] == res[res.size() - 1][0] && nums[j] == res[res.size()-1][1] && nums[left] == res[res.size() - 1][2]){
                        left ++;
                        continue;
                    }
                    int val = nums[left] + nums[right];
                    if(val < sum2_target){
                        left ++;
                    }else if(val > sum2_target){
                        right --;
                    }else{
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left ++;
                    }
                }
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> t = {-2, -1, 0, 0, 1, 2};
    vector<vector<int>> v = sol.fourSum(t, 0);
    for(int i = 0; i < v.size(); i ++){
        for(int j = 0; j < v[i].size(); j ++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}