# include <iostream>
# include <vector>
# include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(0, nums, cur, res);
        return res;    
    }

private:
    void backtrack(int level, vector<int> nums, vector<int> &cur, vector<vector<int>> &res){
        if(level == nums.size()){
            res.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); i ++){
            bool flag = true;

            for(int j = 0; j < cur.size(); j ++){
                if(cur[j] == nums[i]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                cur.push_back(nums[i]);
                backtrack(level + 1, nums, cur, res);
                cur.pop_back();
            }
        }
    }
};

int main(){
    Solution sol;
    
    vector<int> v = {1, 2, 3, 4, 5};
    vector<vector<int>> res = sol.permute(v);

    for(int i = 0; i < res.size(); i ++){
        for(int j = 0; j < res[i].size(); j ++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}