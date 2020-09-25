#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for(int i = 1; i < strs.size() + 1; i ++) {
            int zero_num = 0, one_num = 0;

            for(char c : strs[i-1]) {
                if(c == '0') zero_num ++;
                else one_num ++;
            }

            for(int j = 0; j < m + 1; j ++) {
                for(int k = 0; k < n + 1; k ++) {
                    if(j >= zero_num && k >= one_num) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j - zero_num][k - one_num] + 1);
                    }
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                }
            }
        }

        return dp[strs.size()][m ][n];
    }
};

int main() {
    Solution sol;
    vector<string> a = {"10", "0", "1"};
    cout << sol.findMaxForm(a, 1, 1);
    return 0;
}