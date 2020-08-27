#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        
        dfs(nums, res);
    }

private:
    void dfs(vector<int>& nums, vector<vector<int>>& res){

    }
};

int main(){

    return 0;
}