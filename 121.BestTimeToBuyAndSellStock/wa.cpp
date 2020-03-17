# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[prices.size()][prices.size()];           // 反思：数组不要定义到正好的大小

        int max = 0;
        for(int i = 1; i < prices.size(); i ++){
            for(int j = 0; j < i; j ++){
                int profit = prices[i] - prices[j];
                if(profit > max)
                    max = profit;
            }
        }

        return max;
    }
};

int main(){
    vector<int> v = {};
    cout << Solution().maxProfit(v) << "\n";
    return 0;
}