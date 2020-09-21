#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        if(len == 0) return 0;

        int dp[601][101][101] = {0};

        for(int i = 1; i < len + 1; i ++){
            int one_num = 0, zero_num = 0;
            for(char c : strs[i-1]) {
                if(c == '0') zero_num ++;
                else one_num ++;
            }

            for(int j = 0; j < m + 1; j ++) {
                for(int k = 0; k < n + 1; k ++) {
                    if(k >= one_num && j >= zero_num) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-one_num][k-zero_num] + 1);
                    }
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                }
            }
        }

        return dp[len][m][n];

    }
};

int main() {

    Solution sol;
    vector<string> v = {"10", "0001", "111001", "1", "0"};
    cout << sol.findMaxForm(v, 5, 3);
    return 0;
}