#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() <= 0 || amount < 0) return -1;
        if(amount == 0) return 0;

        vector<int> dp(amount + 1, INT_MAX);
        for(int i = 0; i < coins.size(); i ++){
            if(coins[i] > amount) continue;
            dp[coins[i]] = 1;
        }

        for(int i = 1; i < amount; i ++) {
            if(dp[i] == INT_MAX) continue;
            for(int j = 0; j < coins.size(); j ++) {
                if((((long long)i + coins[j]) >= INT_MAX) || (amount < (i + coins[j]))) continue;
                int target = i + coins[j];
                if((long long)(dp[i] + 1) >= INT_MAX) continue;
                dp[target] = min(dp[target], dp[i] + 1);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];

    }
};

int main(){
    Solution sol;
    vector<int> coins = {1, 2, 5};
    cout << sol.coinChange(coins, 11);

    return 0;
}