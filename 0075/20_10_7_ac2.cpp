#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pos = 0;
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[pos] == 0) {
                nums.insert(nums.begin(), nums[pos]);
                pos ++;
                nums.erase(nums.begin() + pos);
            }else if(nums[pos] == 2) {
                nums.insert(nums.end(), nums[pos]);
                nums.erase(nums.begin() + pos);
            }else if(nums[pos] == 1) {
                pos ++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> v = {0, 0, 1, 1, 2, 2};
    sol.sortColors(v);
    for(int i = 0; i < v.size(); i ++) {
        std::cout << v[i] << std::endl;
    }
    return 0;
}