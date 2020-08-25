#include <iostream>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

// time complexity : 79.26%

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        const int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans ; 
        vector<int> cur;

        function<void(int)> dfs = [&](int s) {
            ans.push_back(cur);

            if(cur.size() == n)
                return ;

            for(int i = s; i < n; i ++){
                if(i > s && nums[i] == nums[i-1])
                    continue;
                cur.push_back(nums[i]);
                dfs(i + 1);
                cur.pop_back();
            }
        };

        dfs(0);

        return ans;

    }
};

int main(){
    Solution sol;

    vector<int> nums = {4, 4, 4, 1, 4};
    for(vector<int> v : sol.subsetsWithDup(nums)){
        for(int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}