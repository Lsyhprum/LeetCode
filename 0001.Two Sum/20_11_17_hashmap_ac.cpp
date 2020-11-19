#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Time complexity : O(N)
// Memory complexity : O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        for(int i = 0; i < nums.size(); i ++) {
            int aim = target - nums[i];
            if(map.find(aim) != map.end()) {
                res.push_back(map[aim]);
                res.push_back(i);
                break;
            }
            map[nums[i]] = i;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {2, 7, 1};
    vector<int> v = sol.twoSum(v1, 3);
    for(int i : v) {
        std::cout << i << std::endl;
    }
    return 0;
}