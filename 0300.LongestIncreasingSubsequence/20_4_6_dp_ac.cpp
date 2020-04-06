# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();

        if(len <= 1) return len;

        vector<int> dp(len, 1);

        for(int i = 1; i < len; i ++){
            for(int j = 0; j < i; j ++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < len; i ++){
            ans = max(ans, dp[i]);
            cout << dp[i] << endl;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> v = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    cout << sol.lengthOfLIS(v) << endl;
    return 0;
}