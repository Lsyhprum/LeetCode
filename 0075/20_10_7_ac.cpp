#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num_0 = 0, num_1 = 0, num_2 = 0;

        for(int num : nums) {
            if(num == 0) {
                num_0 ++;
            }else if(num == 1) {
                num_1 ++;
            }else {
                num_2 ++;
            }
        }

        int pos = 0;
        while(num_0) {
            nums[pos] = 0;
            num_0 --;
            pos ++;
        }
        while(num_1) {
            nums[pos] = 1;
            num_1 --;
            pos ++;
        }
        while(num_2) {
            nums[pos] = 2;
            num_2 --;
            pos ++;
        }
    }
};

int main() {
    Solution sol;
    vector<int> v = {1, 1, 1, 2};
    sol.sortColors(v);
    for(int i = 0; i < v.size(); i ++) {
        std::cout << v[i] << std::endl;
    }
    return 0;
}