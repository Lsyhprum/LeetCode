#include <iostream>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        vector<int> cur;
        int val = 0;

        function<void(int)> fun = [&](int pos) {
            if(val > target) return;
            if(val == target) {
                res.emplace_back(cur);
                return;
            }
            
            for(int i = pos; i < candidates.size(); i ++){
                cur.emplace_back(candidates[i]);

                val += candidates[i];

                fun(i);

                val -= candidates[i];

                cur.pop_back();
            }
        };

        fun(0);

        return res;
    }

};

int main(){
    return 0;
}