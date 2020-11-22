#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<int> odd(nums.size()); // 奇数组
        vector<int> even(nums.size()); // 偶数组

        even[0] = nums[0];
        odd[0] = 0;

        for(int i = 1; i < nums.size(); i ++) {
            if(i % 2 == 0) {
                even[i] = even[i-1] + nums[i];
                odd[i] = odd[i-1];
            }else{
                even[i] = even[i-1];
                odd[i] = odd[i-1] + nums[i];
            }
        }

        int res = 0;
        for(int i = 0; i < nums.size(); i ++) {
            int odd_tag = (i == 0 ? 0 : odd[i-1]) + even[nums.size() - 1] - even[i];
            int even_tag = (i == 0 ? 0 : even[i-1]) + odd[nums.size() - 1] - odd[i];
            //std::cout << odd_tag << " " << even_tag << std::endl;

            if(odd_tag == even_tag) res ++;
        }

        return res;
    }
};

int main() {
    Solution sol;
    // 2 1 6 4
    // odd  : 0 1 1 5
    // even : 2 2 8 8
    // 164  : odd : 6 even 5
    vector<int> v = {1, 2, 3};
    std::cout << sol.waysToMakeFair(v);
    return 0;
}