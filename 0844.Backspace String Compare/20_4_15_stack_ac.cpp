# include <iostream>
# include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> st1;
        stack<char> st2;

        for(char c : S){
            if(c == '#'){
                if(!st1.empty()) st1.pop();
            }else{
                st1.push(c);
            }
        }

        for(char c : T){
            if(c == '#'){
                if(!st2.empty()) st2.pop();
            }else{
                st2.push(c);
            }
        }

        if(st1.size() != st2.size()) return false;

        for(int i = 0; i < st1.size(); i ++){
            if(st1.top() != st2.top()) return false;
            st1.pop();
            st2.pop();
        }

        return true;
    }
};

int main(){
    Solution sol;

    cout << sol.backspaceCompare("abcd", "bbcd");
    return 0;
}