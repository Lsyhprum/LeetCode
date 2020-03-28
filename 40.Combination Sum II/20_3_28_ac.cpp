# include <iostream>
# include <algorithm>
# include <vector>
# include <set>

using namespace std;

// runtime 5.24%
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        set<int> pos;
        int val = 0;
        int j = 0;
        backtrack(candidates, target, pos, j, val, cur, res);

        return res;
    }

private:
    void backtrack(vector<int> candidates, int target, set<int> pos, int j, int val, vector<int> &cur, vector<vector<int>> &res){
        if(val > target) return;
        if(val == target){
            res.push_back(cur);
            return;
        }

        set<int> index;
        for(int i = 0; i < candidates.size(); i ++){
            if(j <= i && index.find(candidates[i]) == index.end() && pos.find(i) == pos.end()){
                cur.push_back(candidates[i]);
                pos.insert(i);
                val += candidates[i];
                index.insert(candidates[i]);
                backtrack(candidates, target, pos, i, val, cur, res);
                val -= candidates[i];
                pos.erase(i);
                cur.pop_back();
            }
        }

    }
};

int main(){
    Solution sol;
    vector<int> v = {10,1,2,7,6,1,5};

    vector<vector<int>> res = sol.combinationSum2(v, 8);

    for(int i = 0; i < res.size(); i ++){
        for(int j = 0; j < res[i].size(); j ++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}