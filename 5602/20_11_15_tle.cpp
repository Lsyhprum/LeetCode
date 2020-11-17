#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // 达到 x 最小操作数，可转化为 达到 nums.size() - x 最多连续序列
        int total = 0;

        // 数组之和
        for(int i : nums) total += i;

        if(x > total) return -1;

        int aim = total - x;
        if(aim == 0) return nums.size();

        int len = -1;

        // 记录从 col 开始的 row 长度的连续序列之和
        vector<int> table(nums.size(), 0);
        int tmp = total;
        for(int i = 0; i < nums.size(); i ++) {
            table[i] = tmp;
            tmp -= nums[i];
        }

        for(int i = nums.size() - 2; i >= 0; i --) {
            for(int j = 0; j < nums.size() - i; j ++) {
                table[j] -= nums[i + 1];
                std::cout << table[j] << " ";
                if(table[j] == aim) {
                    len = nums.size() - i - 1;
                    return len;
                }
            }
            std::cout << std::endl;
        }

        return -1;
    }

};

int main() {
    Solution sol;
    vector<int> v = {3,2,20,1,1,3};
    std::cout << sol.minOperations(v, 10);
    return 0;
}