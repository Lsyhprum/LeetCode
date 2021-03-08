#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<bool>> f;
    vector<int> memo;
    int cur = 0;
    int n;

    int dfs(const string& s, int i) {
        if(i == n) return -1;
        if(memo[i] != -1) return memo[i];

        int ret = INT_MAX;
        for(int j = i; j < n; j ++) {
            if(f[i][j]) {
                ret = min(ret, dfs(s, j + 1) + 1);
            }
        }

        return (memo[i] = ret);
    }

public:
    int minCut(string s) {
        n = s.size();
        f.assign(n, vector<bool>(n, true));
        memo.assign(n, -1);

        for(int i = n - 1; i >= 0; i --) {
            for(int j = i + 1; j < n; j ++) {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }

        return dfs(s, 0);
    }
};

int main() {
    Solution sol;

    std::cout << sol.minCut("ab");
    return 0;
}