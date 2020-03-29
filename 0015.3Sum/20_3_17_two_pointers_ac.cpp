# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

//Runtime 83.14%
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; (i < nums.size() && nums[i] <= 0); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right){
                if(left > i + 1 && nums[left] == nums[left-1]){
                    left ++;
                    continue;
                }
                if(right < nums.size() - 1 && nums[right] == nums[right+1]){
                    right --;
                    continue;
                }
                
                int val = nums[left] + nums[right];
                if(val + nums[i] == 0){
                    vector<int> v(3, 0);
                    v[0] = nums[i];
                    v[1] = nums[left];
                    v[2] = nums[right];

                    ans.push_back(v);
                    
                    left ++;
                }else if(val + nums[i] < 0){
                    left ++;
                }else{
                    right --;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;

    vector<int> val = {1, 2, 3, -1, -2, -3};
    vector<vector<int>> ans = sol.threeSum(val);

    for(int i = 0; i < ans.size(); i ++){
        for(int j = 0; j < ans[i].size(); j ++){
            cout << ans[i][j] << endl;
        }
    }
    return 0;
}