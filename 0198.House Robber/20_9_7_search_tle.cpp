#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

// Time complexity : O(2^N)
// Memory complexity : O(N)
class Solution {
public:
    int rob(vector<int>& nums) {
        
        function<int(int)> dp = [&](int pos)  -> int{
            if(pos >= nums.size()) return 0;

            return max(dp(pos + 1), dp(pos + 2) + nums[pos]);
        };
        return dp(0);
    }
};

int main(){
    Solution sol;
    vector<int> v = {2,7,9,3,1};
    cout << sol.rob(v) ;
    return 0;
}