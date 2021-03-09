#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;

        for(char c : S) {
            if(!st.empty() && st.top() == c) {
                st.pop();
            } else {
                st.push(c);
            }
        }

        string ret = "";

        while(!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};

int main() {
    Solution sol;

    std::cout << sol.removeDuplicates("abbacd");
    return 0;
}