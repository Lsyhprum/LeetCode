#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        function<int(int)> fun = [&](int pos) -> int{
            if(pos == s.size()) return 1; // ?

            int res = 0;

            if(s[pos] != '0') res += fun(pos + 1);
            else return 0;

            if(pos + 1 < s.size() && (s[pos] - '0') * 10 + (s[pos + 1] - '0') <= 26)
                res += fun(pos + 2);

            return res;
        };

        return fun(0);
    }
};

int main(){
    Solution sol;

    cout << sol.numDecodings("226");
    return 0;
}