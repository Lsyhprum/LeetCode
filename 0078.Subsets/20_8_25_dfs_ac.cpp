#include <iostream>
#include <vector>

using namespace std;

// time complexity : 4 ms, faster than 72.31% of C++ online submissions for Subsets.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(nums, 0, tmp, res);

        return res;
    }

private:
    void dfs(const vector<int> &nums, int index, vector<int> &tmp, vector<vector<int>> &res){
        //if(index == nums.size()) return ;

        res.push_back(tmp);

        for(int i = index; i < nums.size(); i ++){
            tmp.push_back(nums[i]);

            dfs(nums, i + 1, tmp, res);

            tmp.pop_back();
        }
    }
};

int main(){
    Solution sol;

    vector<int> nums = {1, 2, 5, 6};
    for(vector<int> v : sol.subsets(nums)){
        for(int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}