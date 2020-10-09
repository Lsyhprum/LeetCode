#include <iostream>
#include <math.h>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> record;
        for(string op : ops) {
            
            if((op[0] >= '0' && op[0] <= '9') || op[0] == '-') {
                int val = 0;
                int num = 0;
                while(op.size() && op.back() != '-') {
                    val += ((op.back() - '0') * pow(10, num));
                    op.pop_back();
                    num ++;
                }
                if(op.size() != 0) {
                    val *= -1;
                }
                record.push(val);
            }

            if(op[0] == 'C') {
                if(!record.empty()) record.pop();
            }

            if(op[0] == 'D') {
                int val = 2 * record.top();
                record.push(val);
            }

            if(op[0] == '+') {
                int val = record.top();
                record.pop();

                int val2 = record.top();

                record.push(val);
                record.push(val + val2);
            }
        }

        int res = 0;
        while(!record.empty()) {
            res += record.top();
            record.pop();
        }

        return res;
    }
};

int main() {

    Solution sol;

    vector<string> v = {"-1","-2","-3","-4","D","9","+","+"};

    std::cout << sol.calPoints(v);
    return 0;
}