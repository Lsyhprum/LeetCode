#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private: 
    vector<int> _nums;
public:
    NumArray(vector<int>& nums) {
        _nums = nums;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for (int index = i; index <= j; index++) {
            sum += _nums[index];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main(){
    vector<int> v = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(v);

    int res = obj->sumRange(0, 5);
    cout << res << endl;
    return 0;
}