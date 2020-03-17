# include <iostream>
# include <algorithm>
# include <cstring>
# include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();

        int dp[nums.size() + 1];                    
        for(int i = 0 ; i < nums.size(); i ++)          // memset() 只有 0 和 -1 正确
            dp[i] = 1;

        int MAX = 1;
        for(int i = 1; i < nums.size(); i ++){
            for(int j = 0; j < i; j ++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[j] + 1, dp[i]);
                    MAX = max(dp[i], MAX);
                }
            }
        }

        return MAX;
    }
};

int main(){
    vector<int> v = {1};
    cout << Solution().lengthOfLIS(v) << "\n";
    return 0;
}