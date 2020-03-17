# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 0) return 0;

        int MIN = prices[0];
        int MAX = 0;
        for(int i = 0; i < prices.size(); i ++){
            if(MIN > prices[i]){
                MIN = prices[i];
            }
            prices[i] -= MIN;
            MAX = max(prices[i], MAX);
        }
        return MAX;
    }
};

int main(){
    vector<int> v = {7, 6, 4, 3, 1};
    cout << Solution().maxProfit(v) << "\n";
    return 0;
}