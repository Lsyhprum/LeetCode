# include <iostream>
# include <vector>

using namespace std;

/**
 *  4ms 87.01%   
 **/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        if(n < 1) return res;

        string cur;
        int left = 0;
        dfs(n, 1, left, cur, res); 

        return res;
    }

private:
    void dfs(int n, int layer, int left, string &cur, vector<string> &res){
        if(layer > n * 2){
            res.push_back(cur);
            return;
        }

        if(left < n){
            cur += "(";

            dfs(n, layer + 1, left + 1, cur, res);

            cur.pop_back();
        }

        int right = layer - left;
        if(right <= left){
            cur += ")";

            dfs(n, layer + 1, left, cur, res);

            cur.pop_back();
        }
    }
};

int main(){
    Solution sol;
    vector<string> res = sol.generateParenthesis(4);

    for(vector<string>::iterator it = res.begin(); it != res.end(); it ++){
        cout << *it << endl;
    }
    return 0;
}