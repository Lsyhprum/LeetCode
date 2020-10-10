#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1;
        int high = n;
        long mid,sum;//使用long类型是为了应对 输入：1804289383 时，计算sum值超出int的取值范围的情况
        while(low<=high)
        {
            mid = low + (high - low )/2;
            sum = mid*(mid+1)/2;
            if(sum == n)
            {
                return (int)mid;//强制类型转换，将long类型转换为int类型
            }
            else if(n > sum)
            {
                low = (int)mid + 1;
            }
            else
            {
                high = (int)mid - 1;
            }
        }
        return high;
    }
};

int main() {
    Solution sol;

    std::cout << sol.arrangeCoins(10);
    return 0;
}