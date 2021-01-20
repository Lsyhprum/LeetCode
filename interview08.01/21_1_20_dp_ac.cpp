#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int waysToStep(int n) {
        vector<long long> dp(1000001, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        if(n <= 3) return dp[n];

        for(int i = 4; i <= n; i ++) {
            long long v1 = dp[i-1] % 1000000007;
            long long v2 = dp[i-2] % 1000000007;
            long long v3 = dp[i-3] % 1000000007;
            dp[i] = (v1 + v2 + v3) % 1000000007;
        }

        return dp[n];
    }
};

int main() {
    
    return 0;
}