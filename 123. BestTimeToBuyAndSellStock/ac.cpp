# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit[prices.size() + 1];
        profit[1] = 0;

        int MAX = 0;
        for(int i = 2; i <= prices.size(); i ++){
            int MIN = prices[1];
            int j = 1;
            int tmp = 0;
            for(; j < i; j ++){
                if(prices[j] < MIN)
                    MIN = prices[j];
                prices[j] -= MIN;
                if(prices[j] > tmp)
                    tmp = prices[j];
            }
            MIN = prices[j];
            int tmp2 = 0;
            for(int k = i; k <= prices.size(); k ++){
                if(prices[k] < MIN)
                    MIN = prices[k];
                prices[k] -= MIN;
                if(prices[k] > tmp2)
                    tmp2 = prices[k];
            }
            MAX = max(tmp + tmp2, MAX);
        }

        cout << MAX << endl;
        return MAX;
    }
};

int main(){
    vector<int> v = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << Solution().maxProfit(v) << "\n";
    return 0;
}