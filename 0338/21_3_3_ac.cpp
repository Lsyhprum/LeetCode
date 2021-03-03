#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);

        res[0] = 0;

        if(num == 0) return res;

        res[1] = 1;

        int pos = 0;
        for(int i = 2; i <= num; i ++) {
            int j = 1;
            for(; j < num && pow(2, j) < i; j ++) {}

            if(pow(2, j) == i) {
                pos = 0;
            }

            res[i] = 1 + res[pos];

            pos ++;
        }

        return res;

        // 0 0
        // 1 1
        // 2 10
        // 3 11
        // 4 100
        // 5 101
        // 6 110
        // 7 111
        // 8 1000
    }
};

int main() {

    Solution sol;

    vector<int> res = sol.countBits(1000);

    for(int i : res) {
        std::cout << i << std::endl;
    }

    return 0;
}