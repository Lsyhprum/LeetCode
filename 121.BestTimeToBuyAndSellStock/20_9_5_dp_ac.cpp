#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Time complexity : O(N)
// Memory complexity : O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;

        vector<int> dp(prices.size(), 0);
        dp[0] = 0;

        int res = 0;
        for(int i = 1; i < prices.size(); i ++){
            dp[i] = max(dp[i], prices[i] - prices[i-1] + dp[i-1]);

            res = max(res, dp[i]);
        }
        
        return res;
    }
};

int main(){
    return 0;
}