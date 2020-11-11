#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if(n == 0) return 0;

        int res = 0;
        int left = 0, right = n - 1;
        int left_max = height[0], right_max = height[n-1];

        while(left <= right) {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);

            if(left_max < right_max) {
                res += (left_max - height[left]);
                left ++;
            } else {
                res += (right_max - height[right]);
                right --;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << sol.trap(v);
    return 0;
}