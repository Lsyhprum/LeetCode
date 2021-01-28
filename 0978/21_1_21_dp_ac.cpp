#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(2, 1));

        int res = 1;
        int flag = true;
        for(int i = 1; i < arr.size(); i ++) {
            if(arr[i] < arr[i - 1]) {
                dp[i][0] = dp[i-1][1] + 1;
                dp[i][1] = 1;
            } else if (arr[i] > arr[i - 1]) {
                dp[i][1] = dp[i-1][0] + 1;
                dp[i][0] = 1;
            } else {
                dp[i][0] = dp[i][1] = 1;
            }

            res = max(max(dp[i][0], dp[i][1]), res);
        }

        for(int i = 0; i < arr.size(); i ++) {
            std::cout << dp[i][0] << " " << dp[i][1] << std::endl; 
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5, 4, 5, 4, 5, 4, 5};
    std::cout << sol.maxTurbulenceSize(arr);

    return 0;
}