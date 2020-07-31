#include <iostream>
#include <vector>

using namespace std;

// Time complexity : O(n^2)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        for(int i = 0; i < nums.size(); i ++){
            int num = 0;
            for(int j = i + 1; j < nums.size(); j ++){
                if(nums[j] < nums[i])
                    num ++;
            }
            res[i] = num;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    for(int v : sol.countSmaller(nums))
        cout << v << endl;
}