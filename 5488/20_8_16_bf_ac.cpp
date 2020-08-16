#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(int n) {
        // 1 3 5 7 9 11 13
        vector<int> val(n);

        int res = 0;

        for(int i = 0; (2*i) + 1 < n; i ++){
            res += (n - (2*i) - 1);
        }

        return res;
    }
};