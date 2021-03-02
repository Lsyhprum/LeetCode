#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        table.resize(nums.size());

        if(nums.size() > 0) {
            table[0] = nums[0];

            for(int i = 1; i < nums.size(); i ++) {
                table[i] = table[i-1] + nums[i];
            }
        }
    }
    
    int sumRange(int i, int j) {
        int result = table[j];

        if(i > 0) {
            result -= table[i - 1];
        }

        return result; 
    }

private:
    vector<int> table;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main() {
    vector<int> nums = {0, -1, -2, -3, -4, -5};
    NumArray* obj = new NumArray(nums);
    int param_1 = obj->sumRange(0, 1);

    std::cout << param_1 << std::endl;
 
    return 0;
}