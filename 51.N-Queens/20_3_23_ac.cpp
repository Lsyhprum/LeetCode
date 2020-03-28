# include <iostream>
# include <string>
# include <vector>
# include <set>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> cur;

        if(n < 1) return res;

        set<int> xy_diff;
        set<int> xy_sum;
        set<int> cols;

        dfs(n, 0, cols, xy_diff, xy_sum, cur, res);

        return res;
    }

private:
    void dfs(int n, int row, set<int> &cols, set<int> &xy_diff, set<int> &xy_sum, vector<string> cur, vector<vector<string>> &res){
        if(row >= n){
            res.push_back(cur);
            return;
        } 

        for(int col = 0; col < n; col ++){
            if(cols.find(col) != cols.end() || xy_diff.find(row - col) != xy_diff.end() || xy_sum.find(row + col) != xy_sum.end())
                continue;
            
            cols.insert(col);
            xy_diff.insert(row - col);
            xy_sum.insert(row + col);

            string s(n, '.');
            s[col] = 'Q';
            cur.push_back(s);

            dfs(n, row + 1, cols, xy_diff, xy_sum, cur, res);

            cols.erase(col);
            xy_diff.erase(row - col);
            xy_sum.erase(row + col);
            cur.pop_back();
        }
    }
};

int main(){
    Solution sol;
    
    vector<vector<string>> res = sol.solveNQueens(8);
    cout << res.size() << endl;

    for(int i = 0; i < res.size(); i ++){
        for(int j = 0; j < res[i].size(); j ++){
            cout << res[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}