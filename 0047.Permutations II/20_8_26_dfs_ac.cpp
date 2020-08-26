# include <iostream>
# include <functional>
# include <algorithm>
# include <vector>
# include <set>

using namespace std;

// time complexity : 67.15%
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<bool> flag(nums.size(), true);
        vector<int> cur;
        
        function<void(int)> dfs = [&](int level) {
            if(level == nums.size()){
                //cout << "wtf" << endl;
                res.push_back(cur);
                return;
            }

            for(int i = 0; i < nums.size(); i ++){
                if((i != 0 && flag[i-1] && nums[i] == nums[i-1]) || flag[i] == false){
                    continue;
                }

                cur.push_back(nums[i]);
                flag[i] = false;
                dfs(level + 1);
                flag[i] = true;
                cur.pop_back();
            }
        };

        dfs(0);

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> v = {1, 1, 1, 2, 2, 2};
    vector<vector<int>> res = sol.permuteUnique(v);

    for(int i = 0; i < res.size(); i ++){
        for(int j = 0; j < res[i].size(); j ++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}