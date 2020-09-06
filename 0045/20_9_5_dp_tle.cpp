#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        vector<int> dp(nums.size(), -1);
        dp[0] = 0;

        // 2 3 1 1 4
        for(int i = 0; i < nums.size() - 1; i ++){
            for(int j = 1; j <= nums[i] && i + j < nums.size(); j ++){
                dp[i + j] = dp[i + j] == -1 ? dp[i] + 1 : min(dp[i + j], dp[i] + 1);
            }
        }

        return dp[nums.size() - 1];
    }
};

int main(){

    return 0;
}