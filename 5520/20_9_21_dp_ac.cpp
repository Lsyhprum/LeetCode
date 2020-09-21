#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        vector<string> v;
        unordered_set<string> c;
        // dp[i][j] 表示以 i 为开头，j 为结尾的 最大子序列个数
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));

        for(int i = 1; i < s.size() + 1; i ++) {
            for(int j = 1; j <= i; j ++) {
                dp[i][j] = max(dp[i][j], dp[i-1][i-1]);
                dp[i][j] = dp[i-1][i-1];
            }
        }
        

        return dp[s.size()];
    }
};

int main() {
    Solution sol;
    cout << sol.maxUniqueSplit("fcmfacp");

    return 0;
}