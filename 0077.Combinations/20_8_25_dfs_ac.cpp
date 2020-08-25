#include <iostream>
#include <vector>

using namespace std;

// time complexity : O(C(n, k)), 22.28%
// memory complexity : O(C(n, k) + k), 93.91%

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(n, k, tmp, res);

        return res;
    }

private:
    void dfs(int n, int k, vector<int> &tmp, vector<vector<int>> &res){
        // 条件满足
        if(tmp.size() == k) {
            res.push_back(tmp);
            return ;
        }

        int start = tmp.empty() ? 1 : tmp[tmp.size() - 1] + 1;

        for(int i = start; i <= n; i ++){
            tmp.push_back(i);

            dfs(n, k, tmp, res);

            tmp.pop_back();
        }
    }
};

int main(){

    Solution sol;

    for(auto v : sol.combine(10, 3)){
        for(int i : v){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}