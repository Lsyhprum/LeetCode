#include <iostream>

using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        // 1  1
        // 2  2
        // 3  1,2 3
        // 4  4
        // 5  2,3 5
        // 6  1,2,3 6
        // 7  3,4 7
        // 8  8
        // 9  4,5 2,3,4
        // 10 10 2,3,4,5
        // 11 5,6
        // 12 3,4,5

        // 大于 1 的奇数必可以拆成两个
        // 大于 3 的 3 的倍数必可以拆成 3 个
        // 大于 5 的 5 的倍数必可以拆成 4 个
    }
};


int main(){
    return 0;
}