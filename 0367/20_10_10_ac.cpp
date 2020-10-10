#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 1, right = num;

        while(left <= right) {
            long long mid = ((right - left) >> 1) + left;
            //std::cout << mid << std::endl;

            if(mid * mid > num) {
                right = mid - 1;
            } else if (mid * mid < num) {
                left = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    std::cout << sol.isPerfectSquare(2000105819);
    return 0;
}