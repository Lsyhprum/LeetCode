#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();

        int i = 0;

        stack<long long> vals;
        stack<char> ops;

        while(i < n) {
            if(s[i] == ' ') {
                i ++;
            } else if (s[i] >= '0' && s[i] <= '9') {
                long long val = 0;
                while(i < n && s[i] >= '0' && s[i] <= '9') {
                    val = val * 10 + s[i] - '0';
                    i ++;
                }

                if(ops.empty() || ops.top() == '+') {
                    vals.push(val);
                } else if (ops.top() == '-') {
                    ops.pop();
                    ops.push('+');
                    vals.push(-val);
                } else {
                    long long lhs = vals.top();
                    vals.pop();

                    long long res = 0;
                    if(ops.top() == '*') {
                        res = lhs * val;
                    } else {
                        res = lhs / val;
                    }

                    vals.push(res);
                    ops.pop();
                }
            } else {
                ops.push(s[i]);
                i ++;
            }
        }

        while(!ops.empty()) {
            long long rhs = vals.top();
            vals.pop();

            long long lhs = vals.top();
            vals.pop();

            vals.push(lhs + rhs);

            ops.pop();
        }

        return vals.top();   
    }
};

int main() {
    Solution sol;

    std::cout << sol.calculate("0-2147483647") << std::endl;

    std::cout << INT_MAX << std::endl;
    return 0;
}