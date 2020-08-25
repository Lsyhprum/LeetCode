# include <iostream>
# include <vector>

using namespace std;

// runtime: 17.30% memory: 8.33%
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        int val = 0;
        int pos = 0;
        backtrack(target, candidates, pos, val, cur, res);

        return res;
    }

private:
    void backtrack(int target, vector<int> candidates, int pos, int val, vector<int> &cur, vector<vector<int>> &res){
        if(val > target) return;
        if(val == target){
            res.push_back(cur);
            return;
        }

        for(int i = 0; i < candidates.size(); i ++){
            if(i >= pos){
                cur.push_back(candidates[i]);
                val += candidates[i];
                backtrack(target, candidates, i, val, cur, res);
                val -= candidates[i];
                cur.pop_back();
            }
        }
    }
};

int main(){
    Solution sol;

    vector<int> v = {2, 3, 4, 5, 6, 7};
    vector<vector<int>> ans = sol.combinationSum(v, 7);

    for(int i = 0; i < ans.size(); i ++){
        for(int j = 0; j < ans[i].size(); j ++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}