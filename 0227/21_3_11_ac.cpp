#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();

        stack<long long> vals;
        stack<char> ops;
        int pos = 0;

        while(pos < n) {
            if(s[pos] == ' ') {
                pos ++;
            } else if (s[pos] >= '0' && s[pos] <= '9') {
                long long val = 0;
                while(pos < n && s[pos] >= '0' && s[pos] <= '9') {
                    val = val * 10 + s[pos] - '0';
                    pos ++;
                }

                if(ops.empty() || ops.top() == '+' || ops.top() == '-') {
                    vals.push(val);
                } else if (ops.top() == '*') {
                    long long lhs = vals.top();
                    vals.pop();
                    long long res = lhs * val;
                    vals.push(res);
                    ops.pop();
                } else if (ops.top() == '/') {
                    long long lhs = vals.top();
                    vals.pop();
                    long long res = lhs / val;
                    vals.push(res);
                    ops.pop();
                }
            } else {
                ops.push(s[pos]);
                pos++;
            }
            
        }

        stack<long long> vals_tmp;
        stack<char> ops_tmp;

        while(!ops.empty()) {
            ops_tmp.push(ops.top());
            ops.pop();
        }

        while(!vals.empty()) {
            vals_tmp.push(vals.top());
            vals.pop();
        }

        while(!ops_tmp.empty()) {
            long long lhs = vals_tmp.top();
            vals_tmp.pop();

            long long rhs = vals_tmp.top();
            vals_tmp.pop();

            long long res = 0;
            if(ops_tmp.top() == '+') {
                res = lhs + rhs;
            } else {
                res = lhs - rhs;

                //std::cout << rhs << " " << lhs << " " << res << std::endl;
            }
            
            vals_tmp.push(res);
            ops_tmp.pop();
        }

        return vals_tmp.top();
    }
};

int main() {
    Solution sol;

    std::cout << sol.calculate("1-1+1 + 2") ;
    return 0;
}