#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        // 终止条件 N = 1
        vector<int> dp(N + 1, 0);

        // 1 2 3 4
        // 0 1 0 1

        for(int i = 2; i <= N; i ++) {
            for(int j = 1; j <= sqrt(N); j ++) {

                //std::cout << i << " " << j << " " << dp[i-j] << std::endl;
                if(i % j == 0 && (dp[i - j] + 1) % 2 != 0) {
                    dp[i] = dp[i - j] + 1;
                }
                //std::cout << dp[i] << std::endl;
            }
        }

        return dp[N] % 2 != 0 ? true : false;
    }
};

int main() {

    Solution sol;

    std::cout << sol.divisorGame(100);

    return 0;
}