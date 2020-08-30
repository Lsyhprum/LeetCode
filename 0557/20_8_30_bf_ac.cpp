#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res;
        stack<char> st;

        for(const char& c : s){
            if(c == ' '){
                while(!st.empty()){
                    res += st.top();
                    st.pop();
                }
                res += ' ';
            }else{
                st.push(c);
            }
        }

        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.reverseWords("abcd fsfsf sffsd");
    return 0;
}