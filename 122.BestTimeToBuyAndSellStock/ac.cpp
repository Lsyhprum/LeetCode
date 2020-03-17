# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;

        int profit[prices.size()] = {};
        int MIN = prices[0];
        int sum = 0;
        for(int i = 0 ; i < prices.size(); i ++){
            if(prices[i] > MIN){
                profit[i] = prices[i] - MIN;
                MIN = prices[i];
            }else{
                MIN = prices[i];
                profit[i] = 0;
            }
            sum += profit[i];
        }

        return sum;

    }
};

int main(){
    vector<int> v = {7, 4, 3, 2 ,6, 4};
    cout << Solution().maxProfit(v) << "\n";
    return 0;
}