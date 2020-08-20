#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 0) return 0;

        vector<int> dp(prices.size(), 0);
        dp[0] = 0;
        int min = prices[0];
        for(int i = 1; i < prices.size(); i ++){
            if(prices[i] < min){
                min = prices[i];
                //cout << "wtf " << min << endl;
            }     
            dp[i] = max(dp[i-1], prices[i] - min);
        }   

        // for(int i = 0; i < prices.size(); i ++)
        //     cout << dp[i] << endl;

        return dp[prices.size()-1];
    }
};

int main(){
    Solution sol;
    // 7 3 5 1 6 4
    vector<int> prices = {7,6 ,5,4};
    cout << sol.maxProfit(prices);

    return 0;
}