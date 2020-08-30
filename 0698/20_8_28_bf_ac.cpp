#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k){
        const int aim = accumulate(nums.begin(), nums.end(), 0);

        if(aim % k != 0) return false;

        sort(nums.rbegin(), nums.rend());

        return dfs(nums, aim / k, 0, k, 0);
    }

    bool dfs(const vector<int> &nums, int target, int cur, int k, int used){
        if(k == 0) return used == (1 << nums.size()) - 1;

        for(int i = 0; i < nums.size(); i ++){
            if(used & (1 << i)) continue;

            int t = cur + nums[i];

            if(t > target) break;
            int new_used = used | (1 << i);
            if(t == target && dfs(nums, target, 0, k - 1, new_used)) return true;
            else if(dfs(nums, target, t, k , new_used)) return true; 
        }

        return false;
    }
};

int main(){

    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << sol.canPartitionKSubsets(nums, 3);
    return 0;
}