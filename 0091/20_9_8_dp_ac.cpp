#include <iostream>

using namespace std;


// Time complexity : O(N)
// Memory complexity : O(1)
class Solution {
public:
    int numDecodings(string s) {
        // 明确状态 ： 以当前字符为第一个字符，或以当前字符为第二个字符
        // 明确 dp 含义 ： 以当前字符作为第一个字符的解码方法总数
        // 明确状态转移方程 ： dp[i] = dp[i+1] + dp[i + 2] 
        //                    dp[i] = 0    s[i] = '0'
        int dp1 = 1, dp2 = 0, dp = 0;

        for(int i = s.size() - 1; i >= 0; i --){
            if(s[i] == '0') {
                dp = 0;
            } else {
                dp = dp1;
                if(i != s.size() - 1) {
                    int val = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if(val <= 26) dp += dp2;
                }
            }

            dp2 = dp1;
            dp1 = dp;
        }

        return dp;
    }
};

int main(){
    Solution sol;

    cout << sol.numDecodings("1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565");
    return 0;
}