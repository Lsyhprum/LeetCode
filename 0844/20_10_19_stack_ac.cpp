#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1;
        stack<char> s2;

        for(char c : S) {
            if(c == '#'){
                if(!s1.empty())
                    s1.pop();
            }else{
                s1.push(c);
            }
        }

        for(char c : T) {
            if(c == '#') {
                if(!s2.empty())
                    s2.pop();
            }else{
                s2.push(c);
            }
        }

        if(s1.size() != s2.size()) return false;

        while(!s1.empty() && s1.top() == s2.top()){
            s1.pop();
            s2.pop();
        }

        if(!s1.empty() || !s2.empty()) return false;

        return true;
    }
};

int main() {
    Solution sol;

    std::cout << sol.backspaceCompare("", "#");

    return 0;
}