#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int N) {
        if(N == 0) return 0;

        vector<int> dp(N + 1, 0);
        dp[0] = 0; dp[1] = 1;

        for(int i = 2; i <= N; i ++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[N];
    }
};

int main(){
    Solution sol;

    cout << sol.fib(1);
    return 0;
}