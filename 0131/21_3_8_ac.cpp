#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<bool>> f;
    vector<string> ans;
    vector<vector<string>> ret;
    int n;

public:
    void dfs(const string &s, int i) {
        if(i == n) {
            ret.push_back(ans);
            return;
        }

        for(int j = i; j < n; j ++) {
            if(f[i][j]) {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        f.assign(n, vector<bool>(n, true));

        for(int i = n - 1; i >= 0; i --) {
            for(int j = i + 1; j < n; j ++) {
                if(f[i][j]) {
                    f[i][j] = (s[i] == s[j]) && f[i+1][j-1];
                }
            }
        }

        dfs(s, 0);

        return ret;
    }
};

int main() {
    Solution sol;

    vector<vector<string>> ret = sol.partition("aaa");
    for(auto iter : ret) {
        for(string s :iter) {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}