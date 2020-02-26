# include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int dp[n] = {};                 // 反思：声明数组长度时，考虑是否从 1 开始。       解决：可以声明最大长度的数组
        dp[1] = 1;
        dp[2] = 2;                      // 反思：未确定数组长度时，谨慎对确定位置的数组赋初值，防止数组越界
        for(int i = 3; i <= n; i ++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

int main(){
    int n;

    cin >> n;
    cout << Solution().climbStairs(n);
    
    return 0;
}