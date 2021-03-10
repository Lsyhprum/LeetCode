#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> ops;
        ops.push(1);
        int ret = 0;
        int sign = 1;
        int pos = 0;

        while(pos < s.size()) {
            if(s[pos] == ' ') {
                pos ++;
            } else if (s[pos] == '+') {
                sign = ops.top();
                pos ++;
            } else if (s[pos] == '-') {
                sign = -ops.top();
                pos ++;
            } else if (s[pos] == '(') {
                ops.push(sign);
                pos ++;
            } else if (s[pos] == ')') {
                ops.pop();
                pos ++;
            } else {
                int val = 0;
                while(pos < s.size() && s[pos] >= '0' && s[pos] <= '9') {
                    val = val * 10 + s[pos] - '0';
                    pos ++;
                }
                ret += (sign * val);
            }
        }

        return ret;
    }
};

int main() {
    Solution sol;

    std::cout << sol.calculate("1+2+(3-(4+5))");
    return 0;
}