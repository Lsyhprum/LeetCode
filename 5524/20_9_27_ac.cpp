#include <vector>

using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int profit_max = INT_MIN;
        int round_max = 1;
        int profit_cur = 0;
        int left = 0;

        int i = 0;
        for(; i < customers.size(); i ++) {
            int num = (customers[i] + left) >=4 ? 4 : customers[i];
            profit_cur += (num * boardingCost - runningCost);

            left += (customers[i] - num);
            
            if(profit_cur > profit_max) {
                profit_max = profit_cur;
                round_max = i + 1;
            }
            //std::cout << profit_cur << std::endl;
        }

        while(left > 0) {
            int num = left >=4 ? 4 : left;
            profit_cur += (num * boardingCost - runningCost);

            left -= num;
            
            if(profit_cur > profit_max) {
                profit_max = profit_cur;
                round_max = i + 1;
            }
            //std::cout << profit_cur << std::endl;
            i ++;
        }

        return profit_max > 0 ? round_max : -1;
    }
};