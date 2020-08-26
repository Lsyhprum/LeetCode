# include <iostream>
# include <algorithm>
# include <vector>
# include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        vector<int> pos;
        backtrack(0, nums, pos, cur, res);

        return res;
    }

private:
    void backtrack(int level, vector<int> nums, vector<int> &pos, vector<int> &cur, vector<vector<int>> &res){
        if(level == nums.size()){
            res.push_back(cur);
            return;
        }

        set<int> val;

        for(int i = 0; i < nums.size(); i ++){
            bool flag = true;
            for(int j = 0; j < pos.size(); j ++){
                if(pos[j] == i){
                    flag = false;
                    break;
                }
            }

            if(flag && val.find(nums[i]) == val.end()){
                cur.push_back(nums[i]);
                pos.push_back(i);
                val.insert(nums[i]);
                backtrack(level + 1, nums, pos, cur, res);
                pos.pop_back();
                cur.pop_back();
            }
        }
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