#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

// Time complexity : O(N)
// Memory complexity : O(N)
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);

        function<int(int)> dp = [&](int pos)  -> int{
            if(pos >= nums.size()) return 0;

            if(memo[pos] != -1) return memo[pos];

            int res = max(dp(pos + 1), dp(pos + 2) + nums[pos]);
            memo[pos] = res;

            return res; 
        };
        return dp(0);
    }
};

int main(){
    Solution sol;
    vector<int> v = {1,2,3,1};
    cout << sol.rob(v) ;
    return 0;
}