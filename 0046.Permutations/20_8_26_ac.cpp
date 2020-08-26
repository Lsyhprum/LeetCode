# include <iostream>
# include <functional>
# include <vector>
# include <set>

using namespace std;

// time complexity : O(n!)
// memory complexity : O(n)

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> flag(nums.size(), true);

        function<void(int)> dfs = [&](int level) {
            if(level == nums.size()){
                res.push_back(cur);
                return;
            }

            for(int i = 0; i < nums.size(); i ++){
                if(flag[i]){
                    flag[i] = false;
                    cur.push_back(nums[i]);
                    dfs(level + 1);
                    cur.pop_back();
                    flag[i] = true;
                }
            }    
        };

        dfs(0);
        
        return res;    
    }
};

int main(){
    Solution sol;
    
    vector<int> v = {1, 2, 3};
    vector<vector<int>> res = sol.permute(v);

    for(int i = 0; i < res.size(); i ++){
        for(int j = 0; j < res[i].size(); j ++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}