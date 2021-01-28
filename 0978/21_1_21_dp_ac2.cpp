#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> dp(2, 1);

        int res = 1;
        for(int i = 1; i < arr.size(); i ++) {
            if(arr[i] < arr[i - 1]) {
                dp[0] = dp[1] + 1;
                dp[1] = 1;
            } else if (arr[i] > arr[i - 1]) {
                dp[1] = dp[0] + 1;
                dp[0] = 1;
            } else {
                dp[0] = dp[1] = 1;
            }

            res = max(max(dp[0], dp[1]), res);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {9,4,2,10,7,8,8,1,9};
    std::cout << sol.maxTurbulenceSize(arr);

    return 0;
}