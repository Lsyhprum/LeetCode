#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        for(string log : logs) {
            log.pop_back();
            if(log == "..") {
                if(!st.empty()) {
                    st.pop();
                }
            }else if(log != ".." && log != ".") {
                st.push(log);
            }
        }

        int res = 0;

        while(!st.empty()) {
            st.pop();
            res ++;
        }

        return res;
    }
};