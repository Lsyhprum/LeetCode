#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) return 0;

        prices.push_back(0);

        int res = 0;
        for(int i = 0; i < prices.size() - 1; i ++){
            int profit1 = func(prices, 0, i);
            int profit2 = func(prices, i + 1, prices.size() - 1);

            res = max(res, profit1 + profit2);
        }

        return res;
    }

private:
    int func(vector<int> &prices, int left, int right){
        cout << left << " " << right << endl;
        if(right - left == 0) return 0;

        vector<int> dp(right - left + 1, 0);
        dp[0] = 0;
        
        int res = 0;
        for(int i = left + 1; i <= right; i ++){
            dp[i - left] = max(dp[i - left], prices[i] - prices[i-1] + dp[i - left - 1]);

            res = max(dp[i-left], res);
        }

        return res;
    }

};

int main(){
    Solution sol;

    vector<int> prices = {1, 2};
    cout << sol.maxProfit(prices);

    return 0;
}